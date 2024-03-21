#pragma once
#include "Component.h"
#include "GPE_BonusDrink.h"


class PlayerInventoryComponent : public Component
{
	
	vector<GPE_BonusDrink*> drinks;

	vector<Actor*> 

public:
	PlayerInventoryComponent(Actor* _owner);

public: 
	void AddBonusDrink(GPE_BonusDrink* _drink);

};

