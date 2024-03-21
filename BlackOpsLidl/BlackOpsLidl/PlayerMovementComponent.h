#pragma once
#include "MovementComponent.h"
#include "PlayerAnimationComponent.h"
#include "SoundManager.h"

class PlayerMovementComponent : public MovementComponent
{
	// Movement
	bool directionHasChanged;
	Vector2f direction;

	// Ground
	bool isOnGround;
	float checkGroundDistance;

	// Dash
	bool canDash;
	bool isDashing;
	bool isResetingDash;
	float dashSpeed;
	float dashDuration;
	float dashCooldown;
	float dashDirection;

	// Sit
	bool isStanding;
	float sitOffset;

	//Distance
	float checkWallDistance;

	// Components
	PlayerAnimationComponent* animation;

public:
	void SetDirectionX(const float _directionX, const string& _animName);
	void SetDirectionY(const float _directionY)
	{
		if (!canMove) return;
		direction.y = _directionY;
	}
	bool IsOnGround() const
	{
		return isOnGround;
	}
	bool GetIsDashing() const
	{
		return isDashing;
	}
	Vector2f GetDirection() const
	{
		return direction;
	}
	float GetDashDirection()const
	{
		return dashDirection;
	}

public:
	PlayerMovementComponent(Actor* _owner);

private:
	bool CheckGround();
	void PlaySound(const string& _sound, const bool _isLoop);
	void Stop();
public:
	virtual void Update(const float _deltaTime) override;
	void Dash();
};