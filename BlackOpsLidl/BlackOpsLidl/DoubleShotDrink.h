#pragma once
#include "GPE_BonusDrink.h"

class DoubleShotDrink : public GPE_BonusDrink
{

public:
	DoubleShotDrink();

public:
	virtual void GetBonusDrinkEffect() override;
};

