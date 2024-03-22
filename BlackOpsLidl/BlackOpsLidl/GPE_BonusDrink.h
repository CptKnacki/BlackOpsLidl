#pragma once
#include "Actor.h"

class GPE_BonusDrink 
{

protected:
	string drinkName;
	string iconPath;
public:
	GPE_BonusDrink();
	string GetDrinkName() const { return drinkName; }
	string GetIconPath() const { return iconPath; }
public:
	virtual void GetBonusDrinkEffect() = 0;
};

