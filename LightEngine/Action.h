#pragma once

class Action {
public:
	Action(void* _owner) { m_owner = _owner; }
	~Action() { m_owner = nullptr; }

	virtual void start() = 0;
	virtual void update(float _delta) = 0;
protected:
	void* m_owner;
};