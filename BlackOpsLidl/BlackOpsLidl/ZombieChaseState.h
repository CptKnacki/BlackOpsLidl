#pragma once
#include "ChaseState.h"


class ZombieChaseState : public ChaseState
{
	ChaseToAttack* chaseToAttack;


public:
	ZombieChaseState(Brain* _brain);

public:
	virtual void Init() override;
};

