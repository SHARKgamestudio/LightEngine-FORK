#include "BulletEntity.h"

void BulletEntity::OnInitialize() {
	SetRigidBody(false);
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