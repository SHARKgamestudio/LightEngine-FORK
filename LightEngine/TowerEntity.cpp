#include "TowerEntity.h"

#include "BulletEntity.h"
#include "Timer.h"

void TowerEntity::OnInitialize() {
	SetRigidBody(false);
	m_max = 8;
	m_ammo = m_max;
	m_shoot = new Timer(0.16f);
	m_reload = new Timer(1.6f);
}

void TowerEntity::OnUpdate() {
}

void TowerEntity::OnCollision(Entity* collidedWith) {
}

void TowerEntity::OnDestroy() {
}

void TowerEntity::Shoot() {
	BulletEntity* bullet = CreateEntity<BulletEntity>(25, sf::Color::Blue);
	bullet->SetPosition(GetPosition().x, GetPosition().y);
	bullet->SetDirection(1, 0);
	bullet->SetSpeed(1024);
}

void TowerEntity::Reload() {
	m_ammo = m_max;
}