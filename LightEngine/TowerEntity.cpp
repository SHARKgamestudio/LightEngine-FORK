#include "TowerEntity.h"

#include "BulletEntity.h"
#include "Timer.h"

void TowerEntity::OnInitialize() {
	SetRigidBody(false);
	m_max = 8;
	m_ammo = m_max;
	m_shoot = new Timer(0.16f);
	m_reload = new Timer(1.6f);

	temp_switch = true;
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

void TowerEntity::OnCollision(Entity* collidedWith) {
}

void TowerEntity::OnDestroy() {
}

void TowerEntity::Shoot() {
	BulletEntity* bullet = CreateEntity<BulletEntity>(GetRadius() / 4, sf::Color::Blue);
	bullet->SetPosition(GetPosition().x, GetPosition().y);
}

void TowerEntity::Reload() {
	m_ammo = m_max;
}