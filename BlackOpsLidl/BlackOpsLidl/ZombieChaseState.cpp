#include "ZombieChaseState.h"
#include "ZombieBrain.h"

ZombieChaseState::ZombieChaseState(Brain* _brain, Actor* _owner) : ChaseState(_brain)
{
	owner = _owner;

	chaseToAttack = new ChaseToAttack(_brain->GetBlackBoard());
	transitions.push_back(chaseToAttack);

	SetNextTransition(chaseToAttack);

}

void ZombieChaseState::Init()
{
	chaseToAttack->Init(dynamic_cast<ZombieBrain*>(brain)->GetAttackState());
}

void ZombieChaseState::Start()
{
	ChaseState::Start();

	MobMovementComponent* _movement = owner->GetComponent<MobMovementComponent>();
	AnimationComponent* _animation = owner->GetComponent<AnimationComponent>();

	if (_movement && _animation)
	{
		Vector2f _direction = _movement->GetLastDirection();
		_animation->RunAnimation("Running", _direction.x);
	}
}

