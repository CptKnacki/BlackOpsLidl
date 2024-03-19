#include "ZombieAttackState.h"
#include "ZombieBrain.h"

ZombieAttackState::ZombieAttackState(Brain* _brain)
	: AttackState(_brain)
{
	attackToChase = new AttackToChase(_brain->GetBlackBoard());
	transitions.push_back(attackToChase);
}

void ZombieAttackState::Init()
{
	attackToChase->Init(dynamic_cast<ZombieBrain*>(brain)->GetChaseState());
}

void ZombieAttackState::Start()
{
	AttackState::Start();

	animation->RunAnimation("Attack", animation->GetCurrentAnimation()->GetDirectionX());
}
