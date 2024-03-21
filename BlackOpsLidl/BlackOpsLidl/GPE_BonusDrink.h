#pragma once
#include "Actor.h"

class GPE_BonusDrink 
{

protected:
	string drinkName;

public:
	GPE_BonusDrink();
	string GetDrinkName() const { return drinkName; }

public:
	virtual void GetBonusDrinkEffect() = 0;
};

