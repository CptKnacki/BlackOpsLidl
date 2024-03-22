#include "PlayerInventoryComponent.h"
#include "Macro.h"

PlayerInventoryComponent::PlayerInventoryComponent(Actor* _owner) : Component(_owner)
{


}

void PlayerInventoryComponent::AddBonusDrink(GPE_BonusDrink* _drink)
{
	if (Contains<GPE_BonusDrink>(_drink, drinks))
		return;

	_drink->GetBonusDrinkEffect();
	drinks.push_back(_drink);
}
