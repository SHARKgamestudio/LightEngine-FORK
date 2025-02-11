#include "Timer.h"

Timer::Timer() {
	m_time = 0;
	m_duration = 0;
}

Timer::Timer(float _duration) {
	m_time = 0;
	m_duration = _duration;
}

Timer::~Timer() {
	m_time = 0;
}

bool Timer::update(float deltaTime) {
	m_time += deltaTime;
	return m_time >= m_duration;
}

void Timer::reset() {
	m_time = 0;
}

float Timer::getTime() const {
	return m_time;
}