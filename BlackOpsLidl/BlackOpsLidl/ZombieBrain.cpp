#include "ZombieBrain.h"

ZombieBrain::ZombieBrain(Actor* _owner)
	: EnemyBrain(_owner)
{
	chase = new ZombieChaseState(this, _owner);
	states.push_back(chase);

	attack = new ZombieAttackState(this, _owner);
	states.push_back(attack);

	Init();
}

void ZombieBrain::Init()
{
	attack->Init();
	chase->Init();

	attack->GetNextTransition()->SetNextState(chase);
	chase->GetNextTransition()->SetNextState(attack);

	currentState = chase;
	currentState->Start();
}
