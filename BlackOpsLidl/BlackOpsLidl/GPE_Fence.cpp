#include "GPE_Fence.h"
#include "Macro.h"
#include "Game.h"

GPE_Fence::GPE_Fence(const ShapeData& _data, int _moneyRequired)
	: Actor(STRING_ID("Fence"), _data)
{
	isOpen = false;
	moneyRequired = _moneyRequired;

}

void GPE_Fence::TryToOpen()
{
	PlayerStat* _playerStats = Game::GetPlayer()->GetStats();
	int _playerMoney = _playerStats->GetMoney();

	if (_playerMoney >= moneyRequired)
	{
		_playerStats->UpdateMoney(-moneyRequired);
		OpenDoor();
	}

}

void GPE_Fence::OpenDoor()
{
	isOpen = true;
	// TODO Faire disparaître
}

void GPE_Fence::CloseDoor()
{
	isOpen = false;
	// TODO Faire réapparaître

}
