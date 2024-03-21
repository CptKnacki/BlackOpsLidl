#include "DeadshotDaiquiriDrink.h"
#include "BonusDrinkManager.h"
#include "Game.h"

DeadshotDaiquiriDrink::DeadshotDaiquiriDrink()
{
	drinkName = DEADSHOT_DAIQUIRI;
}

void DeadshotDaiquiriDrink::GetBonusDrinkEffect()
{
	PlayerStat* _stats = Game::GetPlayer()->GetStats();

	_stats->SetHeadShotPercentage(_stats->GetHeadShotPercentage() * 3);
}
