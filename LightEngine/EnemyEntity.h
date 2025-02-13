#pragma once

#pragma region Local Dependencies

#include "LivingEntity.h"
#include "AttackModule.h"

#pragma endregion

class EnemyEntity : public LivingEntity, public AttackModule {
public:
	EnemyEntity();
	void OnInitialize() override;
	void OnUpdate() override;
	void OnCollision(Entity* collidedWith) override;
	void Die() override;
};