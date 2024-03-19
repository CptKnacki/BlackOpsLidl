#include "ZombieBrain.h"

ZombieBrain::ZombieBrain(Actor* _owner)
	: EnemyBrain(_owner)
{
	chase = new ZombieChaseState(this);
	states.push_back(chase);

	attack = new ZombieAttackState(this);
	states.push_back(attack);

	Init();
}

void ZombieBrain::Init()
{
	attack->Init();
	chase->Init();

	currentState = chase;
	currentState->Start();
}
