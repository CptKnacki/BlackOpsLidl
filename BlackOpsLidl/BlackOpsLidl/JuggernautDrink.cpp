#include "JuggernautDrink.h"
#include "BonusDrinkManager.h"
#include "Game.h"

#define JUGGERNAUT_PATH "BonusIcons/JuggernautIcon.png"

JuggernautDrink::JuggernautDrink()
{
	drinkName = JUGGERNAUT;
	iconPath = JUGGERNAUT_PATH;
}

void JuggernautDrink::GetBonusDrinkEffect()
{
	//PlayerStat* _stats = Game::GetPlayer()->GetStats();
	//
	//if (!_stats)
	//	return;

	//_stats->SetMaxLife(_stats->GetMaxLife() * 2);
}
