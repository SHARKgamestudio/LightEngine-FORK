#include "EnemyEntity.h"

#pragma region Local Dependencies

#include "LivingEntity.h"
#include "Tags.h"

#pragma endregion

EnemyEntity::EnemyEntity() : LivingEntity(100), AttackModule(20) {
	SetTag(FACTION_ENEMY);
}

void EnemyEntity::OnInitialize()  {
	SetRigidBody(false);
	SetDirection(-1, 0);
	SetSpeed(64);
}

void EnemyEntity::OnUpdate() {
	if (GetPosition().x <= GetRadius() * 3) {
		SetSpeed(0);
	}
}

void EnemyEntity::OnCollision(Entity* collidedWith) {
	if (collidedWith->IsTag(FACTION_ENEMY)) {
		SetSpeed(0);
	}

	if (collidedWith->IsTag(FACTION_PLAYER)) {
		Attack((LivingEntity*)collidedWith);
	}
}

void EnemyEntity::Die() { Destroy(); }