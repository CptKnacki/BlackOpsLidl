#include "PlayerInventoryComponent.h"
#include "Macro.h"
#include "BonusDrinkManager.h"
#include "Game.h"

PlayerInventoryComponent::PlayerInventoryComponent(Actor* _owner) : Component(_owner)
{

	AddBonusDrink(BonusDrinkManager::GetInstance().GetDrinkByName(JUGGERNAUT)); // TODO REMOVE
	AddBonusDrink(BonusDrinkManager::GetInstance().GetDrinkByName(DOUBLE_SHOT)); // TODO REMOVE
}

void PlayerInventoryComponent::AddBonusDrink(GPE_BonusDrink* _drink)
{
	if (Contains<GPE_BonusDrink>(_drink, drinks))
		return;


	_drink->GetBonusDrinkEffect();
	drinks.push_back(_drink);
	Game::GetInGameMenu()->AddBonusDrinkUI(_drink->GetIconPath());

}
