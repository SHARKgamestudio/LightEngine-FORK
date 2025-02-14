#pragma once

#include "Action.h"

class Timer;

class ActionShooting : public Action {
public:
	ActionShooting(void* _owner);

	void start() override;
	void update(float _delta) override;
private:
	Timer* m_timer;
};