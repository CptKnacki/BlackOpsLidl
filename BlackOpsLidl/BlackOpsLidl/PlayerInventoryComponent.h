#pragma once
#include "Component.h"
#include "GPE_BonusDrink.h"
#include "RecipeIngredient.h"
#include "RecipeResult.h"


class PlayerInventoryComponent : public Component
{
	
	vector<GPE_BonusDrink*> drinks;

	vector<RecipeIngredient*> craftPart;
	vector<RecipeResult*> craftResults;

public:
	PlayerInventoryComponent(Actor* _owner);

	vector<RecipeIngredient*> GetCraftPart() const { return craftPart; }

public: 
	void AddBonusDrink(GPE_BonusDrink* _drink);
	void AddCraftPart(RecipeIngredient* _ingredient) { craftPart.push_back(_ingredient); }
	void AddCraftResult(RecipeResult* _result) { craftResults.push_back(_result); }
};

