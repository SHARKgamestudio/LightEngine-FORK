#pragma once

#pragma region Local Dependencies

#include "Entity.h"

#pragma endregion

class BulletEntity : public Entity {
public:
	int GetDamage();

	virtual void OnInitialize() override;
	virtual void OnUpdate() override;
	virtual void OnCollision(Entity* collidedWith) override;
	virtual void OnDestroy() override;
private:
	int m_damage;
	int m_speed;
};