#include "RecipeManager.h"

RecipeManager::RecipeManager()
{
	// TODO poser toutes les Recipes


	// First Recipe : TURBINE -> FAN + MANNEQUIN + BATTERY
}

void RecipeManager::CheckForAnyRecipes()
{
	for (Recipe* _recipe : allRecipes)
		_recipe->CreateRecipeResult();
}
