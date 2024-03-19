#pragma once
#include "EnemyBrain.h"
#include "ZombieChaseState.h"
#include "ZombieAttackState.h"

class ZombieBrain : public EnemyBrain
{
	ZombieChaseState* chase = nullptr;
	ZombieAttackState* attack = nullptr;


public:
	ChaseState* GetChaseState() const
	{
		return chase;
	}
	AttackState* GetAttackState() const
	{
		return attack;
	}

public:
	ZombieBrain(Actor* _owner);

public:
	virtual void Init() override;
};

