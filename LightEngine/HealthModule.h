#pragma once

class HealthModule {
public:
	HealthModule(int _health, int _maxHealth = -1);
	~HealthModule();

	void TakeDamage(int _damage);
	void Heal(int _heal);
	bool IsAlive() const;

	virtual void Die() = 0;
private:
	int m_health;
	int m_maxHealth;
};