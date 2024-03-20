#pragma once
#include "Menu.h"
#include "ProgressBar.h"
#include "Timer.h"

#define PATH_LIFE "UIs/Player/Life/Life_"

class Player;
class PlayerAnimationComponent;
class PlayerMovementComponent;

class PlayerStat : public Menu
{
	int currentLife;
	int maxLife;

	int currentStamina;
	int maxStamina;

	int moneyCount;

	int headShotPercentage;

	// Components
	PlayerAnimationComponent* animation;
	PlayerMovementComponent* movement;

	int numberOfDeath;

public:
	void SetCurrentLife(const int _newLife)
	{
		currentLife = _newLife;
	}
	int GetCurrentLife() const
	{
		return currentLife;
	}
	int GetMaxLife() const
	{
		return maxLife;
	}
	int GetMoney() const
	{
		return moneyCount;
	}
private:
	string ComputeLifePath(const bool _toAdd) const
	{
		return PATH_LIFE + to_string(_toAdd) + ".png";
	}

public:
	PlayerStat(Player* _player);

public:
	void Init();
	void UseStamina(const int _factor);
	void UpdateLife(const int _count);
	void UpdateMoney(const int _factor);
	void Death();
};