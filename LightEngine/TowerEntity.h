#pragma once

#pragma region Local Dependencies

#include "LivingEntity.h"

#pragma endregion

class Timer;
class Action;

class TowerEntity : public LivingEntity {
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

	TowerEntity();
	void OnInitialize() override;
	void OnUpdate() override;
	void Die() override;
private:

	int m_ammo, m_max;
	Timer* m_shoot;
	Timer* m_reload;

	bool temp_switch;

	/*State m_current;
	int m_conditions[Count][Count];
	Action** m_actions;*/

	void Shoot();
	void Reload();
};