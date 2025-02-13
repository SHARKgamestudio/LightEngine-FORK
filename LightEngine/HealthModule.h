#pragma once

class HealthModule {
public:
	HealthModule(int _health, int _maxHealth = -1);
	~HealthModule();

	void TakeDamage(int _damage);

	virtual void Die() = 0;
protected:
	int m_health;
	int m_maxHealth;
};