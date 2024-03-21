#include "DoubleShotDrink.h"
#include "BonusDrinkManager.h"
#include "Game.h"


DoubleShotDrink::DoubleShotDrink()
{
	drinkName = DOUBLE_SHOT;
}

void DoubleShotDrink::GetBonusDrinkEffect()
{
	PlayerStat* _stats = Game::GetPlayer()->GetStats();
	_stats->SetHasDoubleShot(true);

}
