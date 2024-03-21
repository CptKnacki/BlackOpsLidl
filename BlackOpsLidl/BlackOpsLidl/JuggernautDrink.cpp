#include "JuggernautDrink.h"
#include "BonusDrinkManager.h"
#include "Game.h"

JuggernautDrink::JuggernautDrink()
{
	drinkName = JUGGERNAUT;
}

void JuggernautDrink::GetBonusDrinkEffect()
{
	PlayerStat* _stats = Game::GetPlayer()->GetStats();

	_stats->SetMaxLife(_stats->GetMaxLife() * 2);
}
