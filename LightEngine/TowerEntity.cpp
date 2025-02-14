#include "TowerEntity.h"

#pragma region Local Dependencies

#include "LivingEntity.h"
#include "BulletEntity.h"
#include "Action.h"
#include "Timer.h"
#include "Tags.h"

#pragma endregion

#include "ActionEmpty.h"
#include "ActionFull.h"
#include "ActionLoaded.h"
#include "ActionReloading.h"
#include "ActionShooting.h"
#include <iostream>

TowerEntity::TowerEntity() : LivingEntity(100) {
	SetTag(FACTION_PLAYER);

	m_actions[(int)State::Shooting] = new ActionShooting(this);
	m_actions[(int)State::Reloading] = new ActionReloading(this);
	m_actions[(int)State::Empty] = new ActionEmpty(this);
	m_actions[(int)State::Full] = new ActionFull(this);
	m_actions[(int)State::Loaded] = new ActionLoaded(this);

	m_max = 8;
	m_ammo = m_max;

	memset(m_conditions, 0, sizeof(m_conditions));

	AllowTransition(State::Full, State::Full);
	AllowTransition(State::Full, State::Shooting);
	AllowTransition(State::Shooting, State::Loaded);
	AllowTransition(State::Shooting, State::Empty);
	AllowTransition(State::Loaded, State::Shooting);
	AllowTransition(State::Loaded, State::Reloading);
	AllowTransition(State::Empty, State::Reloading);
	AllowTransition(State::Reloading, State::Full);

	m_current = State::Full;
}

void TowerEntity::AllowTransition(State _from, State _to) {
	m_conditions[_from][_to] = 1;
}

void TowerEntity::OnInitialize() {
	SetRigidBody(false);
}

void TowerEntity::OnUpdate() {
	m_actions[(int)m_current]->update(GetDeltaTime());
	std::cout << m_current << std::endl;
}

void TowerEntity::Die() { Destroy(); }

bool TowerEntity::SetState(State _state) {
	bool result = m_conditions[(int)m_current][(int)_state];

	if (result) {
		m_actions[(int)_state]->start();
		m_current = _state;
	}

	return result;
}