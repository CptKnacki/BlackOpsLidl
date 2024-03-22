#pragma once
#include "GPE_BonusDrink.h"
class DeadshotDaiquiriDrink : public GPE_BonusDrink
{
public:
	DeadshotDaiquiriDrink();

public:
	virtual void GetBonusDrinkEffect() override;
};

