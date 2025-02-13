#include "BulletEntity.h"

#pragma region Local Dependencies

#include "LivingEntity.h"
#include "Tags.h"

#pragma endregion

BulletEntity::BulletEntity() : AttackModule(20) {
	SetTag(FACTION_NEUTRAL);
}

void BulletEntity::OnInitialize() {
	SetRigidBody(false);
	SetDirection(1, 0);
	SetSpeed(512);
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
	if (collidedWith->IsTag(FACTION_ENEMY)) {
		Attack((LivingEntity*)collidedWith);
		Destroy();
	}
}