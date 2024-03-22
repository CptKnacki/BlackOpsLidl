#pragma once
#include "MovementComponent.h"

class BulletMovementComponent : public MovementComponent
{
	float minRange;
	Vector2f destination;
	Vector2f direction;
	float checkWallDistance;


public: 
	Vector2f GetDestination() const
	{
		return destination;
	}

public:
	BulletMovementComponent(Actor* _owner);

private:
	void MoveToDestination(const float _deltaTime);

public:
	void SetDestination(const Vector2f& _destination, const bool _canMove = true);
	bool IsAtPosition() const;

	virtual void Update(const float _deltaTime) override;
};

