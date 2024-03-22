#include "PlayerMovementComponent.h"
#include "Actor.h"
#include "PlayerAnimationComponent.h"
#include "Game.h"
#include "Timer.h"
#include "Macro.h"
#include "Kismet.h"
#include "FxManager.h"

PlayerMovementComponent::PlayerMovementComponent(Actor* _owner) : MovementComponent(_owner)
{
	// Movement
	canMove = false;
	speed = 0.45f;
	directionHasChanged = false;
	direction = Vector2f();

	// Ground
	isOnGround = false;
	checkGroundDistance = owner->GetShapeSize().y * 0.3f;

	// Dash
	canDash = true;
	isDashing = false;
	isResetingDash = false;
	dashSpeed = 1.50f;
	dashDuration = 0.25f;
	dashCooldown = 0.60f;
	dashDirection = 1.0f;

	// Sit
	isStanding = true;
	sitOffset = 30.0f;

	//Distance
	checkWallDistance = owner->GetShapeSize().x / 2.0f;

	// Components
	animation = owner->GetComponent<PlayerAnimationComponent>();
}


bool PlayerMovementComponent::CheckGround()
{
	HitInfo _info;
	return Raycast(owner->GetShapePosition(), Vector2f(0.0f, 1.0f), checkGroundDistance, _info, { owner });
}



void PlayerMovementComponent::Update(const float _deltaTime)
{
	if (!canMove) return;

	Game::GetCamera()->SetUpdate(!isOnGround);

	Vector2f _offset;

	if (isDashing)
	{
		_offset = Vector2f(dashDirection * dashSpeed * _deltaTime, 0.0f);
	}

	else
	{
		// S'il faut que je reset mon dash
		if (!canDash && !isResetingDash)
		{
			isResetingDash = true;
			new Timer([this]() {
				canDash = true;
				isResetingDash = false;
			}, seconds(dashCooldown));
		}
		 
		// Déplacement par défaut
		_offset = direction * speed * _deltaTime;

	}

	const Vector2f& _collisionOffset = Vector2f(0.0f, -5.0f);
	const Vector2f& _destination = _offset + _collisionOffset;
	collision->GetBoxCollision()->GetDrawable()->setPosition(owner->GetShapePosition() + Vector2f(_destination.x * checkWallDistance, _destination.y));

	if (!collision->CheckCollision())
	{
		owner->GetDrawable()->move(_offset);
	}
}

void PlayerMovementComponent::Dash()
{
	if (!canMove || !canDash || isDashing) return;

	canDash = false;
	isDashing = true;
	new Timer([this]() { isDashing = false; }, seconds(dashDuration));
	animation->GetCurrentAnimation()->RunAnimation("Dash", dashDirection);
	FxManager::GetInstance().Run("FxDash");
}

void PlayerMovementComponent::SetDirectionX(const float _directionX, const string& _animName)
{
	if (!canMove) return;

	if (_directionX == direction.x * -1.0f)
	{
		directionHasChanged = true;
	}

	if (_directionX == 0.0f)
	{
		animation->GetCurrentAnimation()->RunAnimation("StopRight", dashDirection);

		if (directionHasChanged)
		{
			directionHasChanged = false;
			return;
		}

		if (owner->GetDrawable()->getScale().x >= 0.0f)
		{
			dashDirection = 1.0f;
		}

		else
		{
			dashDirection = -1.0f;
		}
	}

	else
	{
		dashDirection = _directionX;
		animation->GetCurrentAnimation()->RunAnimation(_animName, dashDirection);
	}

	direction.x = _directionX;
}