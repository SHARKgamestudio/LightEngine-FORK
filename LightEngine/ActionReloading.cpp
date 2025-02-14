#include "ActionReloading.h"

#include "Timer.h"
#include "TowerEntity.h"

ActionReloading::ActionReloading(void* _owner) : Action(_owner) {
	m_timer = new Timer(1.5f);
}

void ActionReloading::start() {
	m_timer->reset();
}

void ActionReloading::update(float _delta) {
	if (!m_timer->update(_delta)) { return; }

	TowerEntity* tower = (TowerEntity*)m_owner;

	tower->m_ammo = tower->m_max;

	tower->SetState(TowerEntity::State::Full);
}