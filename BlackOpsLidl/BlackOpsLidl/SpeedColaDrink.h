#pragma once
#include "GPE_BonusDrink.h"

class SpeedColaDrink : public GPE_BonusDrink
{
	float reloadTimeReduction = 0.5f;


public:
	SpeedColaDrink();

public:
	virtual void GetBonusDrinkEffect() override;
};

