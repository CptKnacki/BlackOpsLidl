#pragma once
#include "RecipeIngredient.h"
#include "RecipeResult.h"
#include "PlayerInventoryComponent.h"

class Recipe
{
	RecipeResult* recipeResult;
	vector<ItemType> ingredientsLists;

public:
	Recipe(RecipeResult* _result, vector<ItemType> _ingredients);

public:
	bool CheckHasEnoughIngredients(PlayerInventoryComponent* _inventoryComponent);
	void CreateRecipeResult();
	void RemoveIngredientsFromInventory(PlayerInventoryComponent* _inventoryComponent);
	bool ContainsItemType(vector<ItemType> _vector, ItemType _item);
	int GetItemIndexFromItemType(vector<RecipeIngredient*> _items, ItemType _item);
};

