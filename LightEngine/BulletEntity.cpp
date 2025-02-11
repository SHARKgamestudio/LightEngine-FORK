#include "BulletEntity.h"

int BulletEntity::GetDamage() {
	return m_damage;
}

void BulletEntity::OnInitialize() {
	SetRigidBody(false);
	SetTag(1);

	m_damage = 64;
	m_speed = 1024;

	SetDirection(1, 0);
	SetSpeed(m_speed);
}

void BulletEntity::OnUpdate() {
	if (GetPosition().x < 0
		|| GetPosition().x > GetScene()->GetWindowWidth()
		|| GetPosition().y < 0
		|| GetPosition().y > GetScene()->GetWindowHeight())
	{
		Destroy();
	}
}

void BulletEntity::OnCollision(Entity* collidedWith) {
}

void BulletEntity::OnDestroy() {
}