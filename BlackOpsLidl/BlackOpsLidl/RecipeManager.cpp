#include "RecipeManager.h"
#include "Turbine.h"

#define PATH_TURBINE "Fan.png"

RecipeManager::RecipeManager()
{
	// TODO poser toutes les Recipes
	InitTurbineRecipe();

}

void RecipeManager::CheckForAnyRecipes()
{
	for (Recipe* _recipe : allRecipes)
		_recipe->CreateRecipeResult();
}

void RecipeManager::InitTurbineRecipe()
{
	vector<ItemType> _ingredients = { IT_FAN, IT_MANNEQUIN, IT_BATTERY };

	ShapeData _turbineData = ShapeData(Vector2f(0, 0), Vector2f(30, 120), PATH_TURBINE);
	Turbine* _turbine = new Turbine(_turbineData);

	Recipe* _turbineRecipe = new Recipe(_turbine, _ingredients);

	allRecipes.push_back(_turbineRecipe);
}
