#pragma once

#include "Action.h"

class ActionLoaded : public Action {
public:
	ActionLoaded(void* _owner);
	void start() override {};
	void update(float _deltaTime) override {};
};