#include "PHDFlopperDrink.h"
#include "BonusDrinkManager.h"
#include "Game.h"

#define PATH_PHDFLOPPER "BonusIcons/PHDFlopperIcon.png"

PHDFlopperDrink::PHDFlopperDrink()
{
	drinkName = PHD_FLOPPER;
	iconPath = PATH_PHDFLOPPER;
}

void PHDFlopperDrink::GetBonusDrinkEffect()
{
	PlayerStat* _stats = Game::GetPlayer()->GetStats();

	_stats->SetBonusExplosionResistance(explosionResistance);
}
