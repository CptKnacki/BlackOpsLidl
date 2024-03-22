#include "DoubleShotDrink.h"
#include "BonusDrinkManager.h"
#include "Game.h"

#define PATH_DOUBLESHOT "BonusIcons/DoubleShotIcon.png"

DoubleShotDrink::DoubleShotDrink()
{
	drinkName = DOUBLE_SHOT;
	iconPath = PATH_DOUBLESHOT;
}

void DoubleShotDrink::GetBonusDrinkEffect()
{
	//PlayerStat* _stats = Game::GetPlayer()->GetStats();
	//_stats->SetHasDoubleShot(true);

}
