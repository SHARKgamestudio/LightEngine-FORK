#pragma once

class LivingEntity;

class AttackModule {
public:
	AttackModule(int _damage);
	~AttackModule();

	int Attack(LivingEntity* _module);
private:
	int m_damage;
};