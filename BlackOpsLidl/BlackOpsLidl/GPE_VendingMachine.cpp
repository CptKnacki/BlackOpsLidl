#include "GPE_VendingMachine.h"
#include "Macro.h"
#include "PlayerStat.h"
#include "Game.h"
#include "PlayerInventoryComponent.h"

GPE_VendingMachine::GPE_VendingMachine(const ShapeData& _data, GPE_BonusDrink* _bonusDrink, int _vendingPrice) : InteractableActor(STRING_ID("VendingMachine"), _data)
{
	currentVendingDrink = _bonusDrink;
	vendingPrice = _vendingPrice;
}

void GPE_VendingMachine::Interact()
{
	if (!isAvailable)
		return;

	vector<GPE_BonusDrink*> _drinks = Game::GetPlayer()->GetInventory()->GetBonusDrinks();
	if (Contains(currentVendingDrink, _drinks))
		return;


	PlayerStat* _playerStats = Game::GetPlayer()->GetStats();
	int _playerMoney = _playerStats->GetMoney();

	if (_playerMoney >= vendingPrice)
	{
		_playerStats->UpdateMoney(-vendingPrice);
		GiveDrink();
	}
}

void GPE_VendingMachine::GiveDrink()
{
	isAvailable = false;

	PlayerInventoryComponent* _inventory = Game::GetPlayer()->GetInventory();

	if (!_inventory)
		return;

	_inventory->AddBonusDrink(currentVendingDrink);
}
