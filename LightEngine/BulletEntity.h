#pragma once

#pragma region Local Dependencies

#include "Entity.h"
#include "AttackModule.h"

#pragma endregion

class BulletEntity : public Entity, public AttackModule {
public:
	BulletEntity();
	void OnInitialize() override;
	void OnUpdate() override;
	void OnCollision(Entity* collidedWith) override;
};