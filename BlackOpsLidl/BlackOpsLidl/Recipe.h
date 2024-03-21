#pragma once
#include "RecipeIngredient.h"
#include "RecipeResult.h"
#include "PlayerInventoryComponent.h"

class Recipe
{
	RecipeResult* recipeResult;
	vector<RecipeIngredient*> ingredientsLists;

public:
	Recipe(RecipeResult* _result, vector<RecipeIngredient*> _ingredients);

public:
	bool CheckHasEnoughIngredients(PlayerInventoryComponent* _inventoryComponent);
	void CreateRecipeResult();
	void RemoveIngredientsFromInventory(PlayerInventoryComponent* _inventoryComponent);


};

