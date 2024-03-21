#include "SpeedColaDrink.h"
#include "BonusDrinkManager.h"
#include "Game.h"

SpeedColaDrink::SpeedColaDrink()
{
	drinkName = SPEED_COLA;
}

void SpeedColaDrink::GetBonusDrinkEffect()
{
	PlayerStat* _stats = Game::GetPlayer()->GetStats();

	_stats->SetReloadTimeReduction(reloadTimeReduction);
}
