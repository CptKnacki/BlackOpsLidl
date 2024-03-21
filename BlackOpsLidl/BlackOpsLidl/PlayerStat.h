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
	int staminaRegen;

	int moneyCount;

	int headShotPercentage;

	// Components
	PlayerAnimationComponent* animation;
	PlayerMovementComponent* movement;

	int numberOfDeath;
	float bonusMoveSpeed = 0;
	float reloadTimeReduction = 0;
	int bonusExplosionResistance = 0;

	bool hasDoubleShots = false;


public:
	void SetCurrentLife(const int _newLife)
	{
		currentLife = _newLife;
	}
	int GetCurrentLife() const
	{
		return currentLife;
	}
	
	void SetMaxLife(const int _maxLife)
	{
		maxLife = _maxLife;
	}
	int GetMaxLife() const
	{
		return maxLife;
	}
	
	int GetMoney() const
	{
		return moneyCount;
	}
	
	int GetStaminaRegen() const
	{
		return staminaRegen;
	}
	void SetStaminaRegen(const int _regen)
	{
		staminaRegen = _regen;
	}
	
	void SetBonusMoveSpeed(const float _moveSpeed)
	{
		bonusMoveSpeed = _moveSpeed;
	}
	float GetBonusMoveSpeed() const
	{
		return bonusMoveSpeed;
	}
	
	void SetBonusExplosionResistance(const int _resistance)
	{
		bonusExplosionResistance = _resistance;
	}
	int GetBonusExplosionResistance() const
	{
		return bonusExplosionResistance;
	}
	
	int GetHeadShotPercentage() const
	{
		return headShotPercentage;
	}
	void SetHeadShotPercentage(const int _percentage)
	{
		headShotPercentage = _percentage;
	}
	
	bool GetHasDoubleShot() const { return hasDoubleShots; }
	void SetHasDoubleShot(const bool _hasDoubleShot) { hasDoubleShots = _hasDoubleShot; }

	void SetReloadTimeReduction(const float _reloadReduction)
	{
		reloadTimeReduction = _reloadReduction;
	}
	float GetReloadTimeReduction() const
	{
		return reloadTimeReduction;
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