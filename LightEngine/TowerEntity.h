#pragma once

#pragma region Local Dependencies

#include "Entity.h"

#pragma endregion

class Timer;
class Action;

class TowerEntity : public Entity {
public:
	//enum State {
	//	Idle,
	//	Shooting,
	//	Reloading,

	//	Empty,
	//	Loaded,
	//	Full,

	//	Count
	//};

	virtual void OnInitialize() override;
	virtual void OnUpdate() override;
	virtual void OnCollision(Entity* collidedWith) override;
	virtual void OnDestroy() override;

private:
	int m_ammo, m_max;
	Timer* m_shoot;
	Timer* m_reload;

	/*State m_current;
	int m_conditions[Count][Count];
	Action** m_actions;*/

	void Shoot();
	void Reload();
};