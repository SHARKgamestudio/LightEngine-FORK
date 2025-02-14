#pragma once

#include "Action.h"

class ActionEmpty : public Action {
public:
	ActionEmpty(void* _owner);
	void start() override {};
	void update(float _deltaTime) override {};
};