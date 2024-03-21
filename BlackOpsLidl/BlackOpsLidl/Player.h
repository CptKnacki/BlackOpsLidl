#pragma once
#include "Actor.h"
#include "PauseMenu.h"
#include "PlayerStat.h"
#include "Inventory.h"
#include "CharmsMenu.h"
#include "PlayerMovementComponent.h"
#include "PlayerAttackComponent.h"
#include "PlayerAnimationComponent.h"
#include "PlayerInventoryComponent.h"
#include "InteractionComponent.h"
#include "CollisionComponent.h"
#include "PlayerSoundData.h"
#include "Weapon.h"

using namespace std;

class Player : public Actor
{
	PauseMenu* pauseMenu;
	PlayerStat* stats;
	CharmsMenu* charmsMenu;
	PlayerMovementComponent* movement;
	PlayerAttackComponent* attack;
	PlayerAnimationComponent* animation;
	InteractionComponent* interaction;
	PlayerInventoryComponent* inventory;
	CircleShape* light;
	SoundData* sound;
	PlayerSoundData data;


public:
	void SetStatus(const bool _status)
	{
		movement->SetCanMove(_status);
	}
	PlayerStat* GetStats() const
	{
		return stats;
	}
	PlayerInventoryComponent* GetInventory() const
	{
		return inventory;
	}
	CircleShape* GetLight() const
	{
		return light;
	}
	PlayerMovementComponent* GetPlayerMovement()const
	{
		return movement;
	}
	Vector2f GetPosition() const
	{
		return GetShapePosition();
	}

public:
	Player(const string& _name, const ShapeData& _data);

private:
	void InitAnimations();
	void SetupPlayerInput();
	void TryToOpen(Menu* _menu, const bool _restoreActions = true);

public:
	virtual void Init() override;
	virtual void Update(const float _deltaTime) override;
	void CloseAllMenus(const bool _restoreActions);
};