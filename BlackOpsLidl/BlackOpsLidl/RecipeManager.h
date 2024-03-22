#pragma once
#include "Singleton.h"
#include "Recipe.h"


class RecipeManager : public Singleton<RecipeManager>
{
	vector<Recipe*> allRecipes;


public:
	RecipeManager();

public:
	void CheckForAnyRecipes();

private:
	void InitTurbineRecipe();

};

