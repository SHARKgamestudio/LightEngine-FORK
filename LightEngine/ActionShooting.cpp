#include "ActionShooting.h"

#include "Timer.h"
#include "TowerEntity.h"
#include "BulletEntity.h"

ActionShooting::ActionShooting(void* _owner) : Action(_owner) {
	m_timer = new Timer(0.25f);
}

void ActionShooting::start() {
	m_timer->reset();
}

void ActionShooting::update(float _delta) {
	if (!m_timer->update(_delta)) { return; }

	TowerEntity* tower = (TowerEntity*)m_owner;

	if (tower->m_ammo > 0)
	{
		BulletEntity* bullet = tower->CreateEntity<BulletEntity>(tower->GetRadius() / 4, sf::Color::Blue);
		bullet->SetPosition(tower->GetPosition().x, tower->GetPosition().y);
		tower->m_ammo--;
		tower->SetState(TowerEntity::State::Loaded);
	}
	else { tower->SetState(TowerEntity::State::Empty); }
}