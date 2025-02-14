#pragma once

#include "Action.h"

class Timer;

class ActionReloading : public Action {
public :
	Timer* m_timer;

	ActionReloading(void* _owner);

	void start() override;
	void update(float _delta) override;
};