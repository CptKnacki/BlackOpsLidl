#pragma once
#include "InteractableActor.h"
#include "GPE_BonusDrink.h"


class GPE_VendingMachine : public InteractableActor
{

	int vendingPrice;
	GPE_BonusDrink* currentVendingDrink;
	bool isAvailable = true;

public:
	GPE_VendingMachine(const ShapeData& _data, GPE_BonusDrink* _bonusDrink, int _vendingPrice);

	int GetVendingPrice() const { return vendingPrice; }
	bool GetIsAvailable() const { return isAvailable; }
	GPE_BonusDrink* GetBonusDrink() const { return currentVendingDrink; }

public:
	virtual void Interact() override;
	void GiveDrink();
};

