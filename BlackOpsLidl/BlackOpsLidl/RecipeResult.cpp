#include "RecipeResult.h"
#include "Macro.h"


RecipeResult::RecipeResult(const string& _itemName, const ShapeData& _data, const ItemType& _type) : Actor(_itemName, _data)
{
	itemType = _type;
}
