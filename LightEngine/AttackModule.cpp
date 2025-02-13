#include "AttackModule.h"

#pragma region Local Dependencies

#include "LivingEntity.h"

#pragma endregion

AttackModule::AttackModule(int _damage) {
	m_damage = _damage;
}

AttackModule::~AttackModule() {
}

int AttackModule::Attack(LivingEntity* _module) {
	_module->TakeDamage(m_damage);
	return m_damage;
}