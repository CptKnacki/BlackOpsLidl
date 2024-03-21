#include "EnergyDrink.h"
#include "BonusDrinkManager.h"
#include "Game.h"

EnergyDrink::EnergyDrink()
{
}

void EnergyDrink::GetBonusDrinkEffect()
{
	PlayerStat* _stats = Game::GetPlayer()->GetStats();

	_stats->SetBonusMoveSpeed(bonusMoveSpeed);
}
