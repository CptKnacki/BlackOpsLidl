#include "PlayerInventoryComponent.h"
#include "Macro.h"
#include "BonusDrinkManager.h"
#include "Game.h"

PlayerInventoryComponent::PlayerInventoryComponent(Actor* _owner) : Component(_owner)
{

}

void PlayerInventoryComponent::AddBonusDrink(GPE_BonusDrink* _drink)
{
	if (Contains<GPE_BonusDrink>(_drink, drinks))
		return;


	_drink->GetBonusDrinkEffect();
	drinks.push_back(_drink);
	Game::GetInGameMenu()->AddBonusDrinkUI(_drink->GetIconPath());

}

void PlayerInventoryComponent::AddCraftPart(RecipeIngredient* _ingredient)
{
	craftPart.push_back(_ingredient);
	Game::GetInGameMenu()->AddItemUI(_ingredient->GetShapePath());
}

void PlayerInventoryComponent::AddCraftResult(RecipeResult* _result)
{
	craftResults.push_back(_result);
	Game::GetInGameMenu()->AddItemUI(_result->GetShapePath());

}
