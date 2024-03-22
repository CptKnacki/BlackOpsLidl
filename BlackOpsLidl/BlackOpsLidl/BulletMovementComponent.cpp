#include "BulletMovementComponent.h"
#include "AnimationComponent.h"
#include "Actor.h"
#include "Macro.h"
#include "Kismet.h"
#include "Game.h"

void BulletMovementComponent::SetDestination(const Vector2f& _destination, const bool _canMove)
{
	destination = _destination;
	canMove = _canMove;

	Vector2f _newDirection = _destination - owner->GetShapePosition();
	Normalize(_newDirection);
}

BulletMovementComponent::BulletMovementComponent(Actor* _owner) : MovementComponent(_owner)
{
	destination = _owner->GetShapePosition();
}

void BulletMovementComponent::MoveToDestination(const float _deltaTime)
{
	if (!canMove) return;

	Vector2i mousePosition = Mouse::getPosition(Game::GetWindow());

	destination = Vector2f(mousePosition.x, mousePosition.y);

	Vector2f _direction = destination;
	Normalize(_direction);
	lastDirection = _direction;

	const Vector2f& _position = owner->GetShapePosition() + _direction * speed * _deltaTime;
	owner->GetDrawable()->setPosition(_position);
}

void BulletMovementComponent::Update(const float _deltaTime)
{
	MoveToDestination(_deltaTime);
	if (IsAtPosition())
	{
		if (collision->CheckCollision())
		{
			owner->Destroy();

	/*		ActorManager::GetInstance().DestroyActor(collision->GetOwner());*/

			cout << "Touche!" << endl;
		}
	}
}

bool BulletMovementComponent::IsAtPosition() const
{
	return Distance(owner->GetShapePosition(), destination) <= minRange;
}