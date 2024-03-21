#include "PHDFlopperDrink.h"
#include "BonusDrinkManager.h"
#include "Game.h"

PHDFlopperDrink::PHDFlopperDrink()
{
	drinkName = PHD_FLOPPER;
}

void PHDFlopperDrink::GetBonusDrinkEffect()
{
	PlayerStat* _stats = Game::GetPlayer()->GetStats();

	_stats->SetBonusExplosionResistance(explosionResistance);
}
