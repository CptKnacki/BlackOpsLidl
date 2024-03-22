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
	vector<GPE_BonusDrink*> GetBonusDrinks() const { return drinks; }
public: 
	void AddBonusDrink(GPE_BonusDrink* _drink);
	void AddCraftPart(RecipeIngredient* _ingredient);
	void AddCraftResult(RecipeResult* _result);
};

