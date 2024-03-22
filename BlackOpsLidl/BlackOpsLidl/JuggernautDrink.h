#pragma once
#include "GPE_BonusDrink.h"
class JuggernautDrink : public GPE_BonusDrink
{

public:
	JuggernautDrink();

public:
	virtual void GetBonusDrinkEffect() override;
};

