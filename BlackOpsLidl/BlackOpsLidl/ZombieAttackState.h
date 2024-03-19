#pragma once
#include "AttackState.h"
#include "AttackToChase.h"

class ZombieAttackState : public AttackState
{
	AttackToChase* attackToChase;

public:
	ZombieAttackState(Brain* _brain);

public:
	virtual void Init() override;
	virtual void Start() override;
};

