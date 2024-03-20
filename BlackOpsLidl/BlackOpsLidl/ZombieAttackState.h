#pragma once
#include "AttackState.h"
#include "AttackToChase.h"
#include "Zombie.h"

class ZombieAttackState : public AttackState
{
	AttackToChase* attackToChase;
	Actor* owner;

public:
	ZombieAttackState(Brain* _brain, Actor* _owner);

public:
	virtual void Init() override;
	virtual void Start() override;
};

