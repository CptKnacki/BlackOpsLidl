#include "Recipe.h"

Recipe::Recipe(RecipeResult* _result, vector<RecipeIngredient*> _ingredients)
{
    recipeResult = _result;
    ingredientsLists = _ingredients;
}

bool Recipe::CheckHasEnoughIngredients()
{
    return false;
}

void Recipe::CreateRecipeResult()
{
    if (!CheckHasEnoughIngredients())
        return;

    // ADD RECIPE RESULT TO INVENTORY

    RemoveIngredientsFromInventory();

}

void Recipe::RemoveIngredientsFromInventory()
{
}
