#include "HealthModule.h"

HealthModule::HealthModule(int _health, int _maxHealth) {
	m_health = _health;
	if (_maxHealth == -1) m_maxHealth = _health;
	else m_maxHealth = _maxHealth;
}

HealthModule::~HealthModule() {
}

bool HealthModule::IsAlive() const {
	return m_health > 0;
}

void HealthModule::TakeDamage(int _damage) {
	if (m_health > 0) m_health -= _damage;
	else Die();
}

void HealthModule::Heal(int _heal) {
	if (m_health > 0) return;

	if (m_health < m_maxHealth) {
		m_health += _heal;
		if (m_health > m_maxHealth) m_health = m_maxHealth;
	}
}