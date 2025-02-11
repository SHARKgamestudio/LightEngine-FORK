#include "EnemyEntity.h"
#include "BulletEntity.h"

void EnemyEntity::OnInitialize() {
	SetRigidBody(false);
	SetTag(2);

	m_maxHealth = 100;
	m_health = m_maxHealth;
}

void EnemyEntity::OnUpdate() {
	if (m_health <= 0) {
		Destroy();
	}
}

void EnemyEntity::OnCollision(Entity* collidedWith) {
	if (collidedWith->IsTag(1)) {
		collidedWith->Destroy();

		m_health -= ((BulletEntity*)collidedWith)->GetDamage();
	}
}

void EnemyEntity::OnDestroy() {
}