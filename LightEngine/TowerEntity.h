#pragma once

#pragma region Local Dependencies

#include "LivingEntity.h"

#pragma endregion

class Timer;
class Action;

class TowerEntity : public LivingEntity {
public:
	enum State {
		Idle,
		Shooting,
		Reloading,

		Empty,
		Loaded,
		Full,

		Count
	};

	TowerEntity();
	void OnInitialize() override;
	void OnUpdate() override;
	void Die() override;

	bool SetState(State _state);

	int m_ammo, m_max;

private:
	State m_current;
	Action* m_actions[Count];
	int m_conditions[Count][Count];
	void AllowTransition(State _from, State _to);
};