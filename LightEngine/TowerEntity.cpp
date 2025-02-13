#include "TowerEntity.h"

#pragma region Local Dependencies

#include "LivingEntity.h"
#include "BulletEntity.h"
#include "Timer.h"
#include "Tags.h"

#pragma endregion

TowerEntity::TowerEntity() : LivingEntity(100) {
	SetTag(FACTION_PLAYER);

	m_max = 8;
	m_ammo = m_max;
	m_shoot = new Timer(0.16f);
	m_reload = new Timer(1.6f);

	temp_switch = true;
}

void TowerEntity::OnInitialize() {
	SetRigidBody(false);
}

void TowerEntity::OnUpdate() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) && temp_switch) {
		temp_switch = false;
		Shoot();
	}
	else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
		temp_switch = true;
	}
}

void TowerEntity::Die() { Destroy(); }

void TowerEntity::Shoot() {
	BulletEntity* bullet = CreateEntity<BulletEntity>(GetRadius() / 4, sf::Color::Blue);
	bullet->SetPosition(GetPosition().x, GetPosition().y);
}

void TowerEntity::Reload() {
	m_ammo = m_max;
}