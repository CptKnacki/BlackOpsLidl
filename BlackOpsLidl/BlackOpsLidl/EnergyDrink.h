#pragma once
#include "GPE_BonusDrink.h"
class EnergyDrink : public GPE_BonusDrink
{
	float bonusMoveSpeed = 0.3f;

public:
	EnergyDrink();

public:
	virtual void GetBonusDrinkEffect() override;
};

