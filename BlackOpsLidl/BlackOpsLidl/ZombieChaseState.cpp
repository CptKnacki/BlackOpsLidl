#include "ZombieChaseState.h"
#include "ZombieBrain.h"

ZombieChaseState::ZombieChaseState(Brain* _brain)
	: ChaseState(_brain)
{
	chaseToAttack = new ChaseToAttack(_brain->GetBlackBoard());
	transitions.push_back(chaseToAttack);
}

void ZombieChaseState::Init()
{
	chaseToAttack->Init(dynamic_cast<ZombieBrain*>(brain)->GetAttackState());
}

