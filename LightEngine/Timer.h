#pragma once

class Timer {
public:
	Timer();
	Timer(float _duration);
	~Timer();

	bool update(float deltaTime);
	void reset();
	float getTime() const;
private:
	float m_duration;
	float m_time;
};