#include "Recipe.h"
#include "Game.h"
#include "Macro.h"


Recipe::Recipe(RecipeResult* _result, vector<RecipeIngredient*> _ingredients)
{
    recipeResult = _result;
    ingredientsLists = _ingredients;
}


bool Recipe::CheckHasEnoughIngredients(PlayerInventoryComponent* _inventoryComponent)
{
    const size_t _ingredientsSize = ingredientsLists.size();
    vector<RecipeIngredient*> _ingredients = _inventoryComponent->GetCraftPart();

    for (size_t i = 0; i < _ingredientsSize; i++)
    {
        if (!Contains<RecipeIngredient>(ingredientsLists[i], _ingredients))
            return false;
    }

    return true;

}

void Recipe::CreateRecipeResult()
{
    PlayerInventoryComponent* _inventoryComponent = Game::GetPlayer()->GetComponent<PlayerInventoryComponent>();

    if (!_inventoryComponent || CheckHasEnoughIngredients(_inventoryComponent))
        return;

    RemoveIngredientsFromInventory(_inventoryComponent);
    _inventoryComponent->AddCraftResult(recipeResult);

}

void Recipe::RemoveIngredientsFromInventory(PlayerInventoryComponent* _inventoryComponent)
{
    const size_t _ingredientsSize = ingredientsLists.size();
    vector<RecipeIngredient*> _ingredients = _inventoryComponent->GetCraftPart();

    for (size_t i = 0; i < _ingredientsSize; i++)
    {
        EraseElement<RecipeIngredient>(_ingredients, ingredientsLists[i]);
    }
    
}
