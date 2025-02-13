#include "HealthModule.h"

HealthModule::HealthModule(int _health, int _maxHealth) {
	m_health = _health;
	if (_maxHealth == -1) m_maxHealth = _health;
	else m_maxHealth = _maxHealth;
}

HealthModule::~HealthModule() {
}

void HealthModule::TakeDamage(int _damage) {
	if (m_health > 0) m_health -= _damage;
	else Die();
}