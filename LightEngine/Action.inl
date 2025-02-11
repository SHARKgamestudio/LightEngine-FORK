#pragma once

template <typename T>
class Action {
public:
	Action(T* _owner) : m_owner(_owner) {}
	~Action() { m_owner = nullptr; }

	virtual void start() = 0;
	virtual void update() = 0;
protected:
	T* m_owner;
};