#pragma once
#include "Actor.h"
#include "GPE_BonusDrink.h"


class GPE_VendingMachine : public Actor
{

	int vendingPrice;
	GPE_BonusDrink* currentVendingDrink;
	bool isAvailable = true;

public:
	GPE_VendingMachine(const ShapeData& _data, int _vendingPrice);

	int GetVendingPrice() const { return vendingPrice; }
	bool GetIsAvailable() const { return isAvailable; }
	GPE_BonusDrink* GetBonusDrink() const { return currentVendingDrink; }
	// TODO Rajouter dans le player inventory une liste des boissons et des collectibles
	// Pour le GPE_CraftTable check les composants présents dans l'inventaire et si 
	//		tout les composants d'une recette sont présents, effectuer le craft

public:
	void CheckCanAffordDrink();
	void GiveDrink();
};

