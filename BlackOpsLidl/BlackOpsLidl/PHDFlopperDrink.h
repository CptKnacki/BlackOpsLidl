#pragma once
#include "GPE_BonusDrink.h"
class PHDFlopperDrink : public GPE_BonusDrink
{

	int explosionResistance = 75;

public:
	PHDFlopperDrink();

public:
	virtual void GetBonusDrinkEffect() override;
};

