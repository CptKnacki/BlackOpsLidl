#pragma once
#include "RecipeIngredient.h"
#include "RecipeResult.h"

class Recipe
{
	RecipeResult* recipeResult;
	vector<RecipeIngredient*> ingredientsLists;

public:
	Recipe(RecipeResult* _result, vector<RecipeIngredient*> _ingredients);

public:
	bool CheckHasEnoughIngredients();
	void CreateRecipeResult();
	void RemoveIngredientsFromInventory();


};

