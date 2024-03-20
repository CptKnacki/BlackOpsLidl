#include "ZombieAttackState.h"
#include "ZombieBrain.h"
#include "AnimationComponent.h"

ZombieAttackState::ZombieAttackState(Brain* _brain, Actor* _owner)
	: AttackState(_brain)
{
	owner = _owner;

	attackToChase = new AttackToChase(_brain->GetBlackBoard());
	transitions.push_back(attackToChase);

	SetNextTransition(attackToChase);
}


void ZombieAttackState::Init()
{
	attackToChase->Init(dynamic_cast<ZombieBrain*>(brain)->GetChaseState());
}

void ZombieAttackState::Start()
{
	AttackState::Start();

	MobMovementComponent* _movement = owner->GetComponent<MobMovementComponent>();
	AnimationComponent* _animation = owner->GetComponent<AnimationComponent>();

	if (_movement && _animation)
	{
		Vector2f _direction = _movement->GetLastDirection();
		_animation->RunAnimation("Attack", _direction.x);
	}
}
