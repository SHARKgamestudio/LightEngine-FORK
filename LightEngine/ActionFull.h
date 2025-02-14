#pragma once

#include "Action.h"

class ActionFull : public Action {
public:
	ActionFull(void* _owner);
	void start() override {};
	void update(float _deltaTime) override {};
};