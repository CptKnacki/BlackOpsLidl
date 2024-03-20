#pragma once
#include "ChaseState.h"
#include "Zombie.h"


class ZombieChaseState : public ChaseState
{
	ChaseToAttack* chaseToAttack;
	Actor* owner;

public:
	ZombieChaseState(Brain* _brain, Actor* _owner);

public:
	virtual void Init() override;
	virtual void Start() override;
};

