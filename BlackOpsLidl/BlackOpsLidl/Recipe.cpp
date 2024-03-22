#include "Recipe.h"
#include "Game.h"
#include "Macro.h"


Recipe::Recipe(RecipeResult* _result, vector<ItemType> _ingredients)
{
    recipeResult = _result;
    ingredientsLists = _ingredients;
}


bool Recipe::CheckHasEnoughIngredients(PlayerInventoryComponent* _inventoryComponent)
{
    vector<RecipeIngredient*> _playerIngredients = _inventoryComponent->GetCraftPart();
    vector<ItemType> _playerIngredientsType;
    const size_t _playerIngredientsSize = _playerIngredients.size();
    const size_t _ingredientsSize = ingredientsLists.size();

    for (size_t i = 0; i < _playerIngredientsSize; i++)
        _playerIngredientsType.push_back(_playerIngredients[i]->GetItemData().type);

    for (size_t j = 0; j < _ingredientsSize; j++)
    {
        if (!ContainsItemType(_playerIngredientsType, ingredientsLists[j]))
            return false;
    }

    return true;

}

void Recipe::CreateRecipeResult()
{
    PlayerInventoryComponent* _inventoryComponent = Game::GetPlayer()->GetInventory();

    if (!_inventoryComponent || CheckHasEnoughIngredients(_inventoryComponent))
        return;

    RemoveIngredientsFromInventory(_inventoryComponent);
    _inventoryComponent->AddCraftResult(recipeResult);

}

void Recipe::RemoveIngredientsFromInventory(PlayerInventoryComponent* _inventoryComponent)
{
    const size_t _ingredientsSize = ingredientsLists.size();
    vector<RecipeIngredient*> _ingredients = _inventoryComponent->GetCraftPart();
    vector<string> _list = Game::GetInGameMenu()->GetItemsList();

    for (size_t i = 0; i < _ingredientsSize; i++)
    {
        int _index = GetItemIndexFromItemType(_ingredients, ingredientsLists[i]);

        if (_index == -4)
            continue;

        _list.erase(remove(_list.begin(), _list.end(), _ingredients[_index]->GetShapePath()), _list.end());
        EraseElement<RecipeIngredient>(_ingredients, _ingredients[_index]);
    }
    
}

bool Recipe::ContainsItemType(vector<ItemType> _vector, ItemType _item)
{
    size_t _size = _vector.size();

    for (size_t i = 0; i < _size; i++)
    {
        if (_vector[i] == _item)
            return true;
    }

    return false;
}

int Recipe::GetItemIndexFromItemType(vector<RecipeIngredient*> _items, ItemType _item)
{
    vector<ItemType> _playerIngredientsType;
    const size_t _playerIngredientsSize = _items.size();

    for (size_t i = 0; i < _playerIngredientsSize; i++)
    {
        if (_items[i]->GetItemData().type == _item)
            return i;
    }

    return -4;
}
