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
	GetShape()->setScale(sf::Vector2f(0, 0));
	// TODO Mettre à jour la grid
}

void GPE_Fence::CloseDoor()
{
	isOpen = false;
	GetShape()->setScale(sf::Vector2f(1, 1));
	// TODO Mettre à jour la grid

}
