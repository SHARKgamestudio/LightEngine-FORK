#pragma once

#pragma region Local Dependencies

#include "Entity.h"
#include "HealthModule.h"

#pragma endregion

class LivingEntity : public Entity, public HealthModule {
public:
	LivingEntity(int _health, int _maxHealth = -1);
	~LivingEntity();

	virtual void Die() = 0;
};