#include "RecipeIngredient.h"
#include "Item.h"

RecipeIngredient::RecipeIngredient(const string& _name, const ShapeData& _data, const float _range, const ItemType& _type)
	:CollectableActor(_name, _data, _range, _type)
{
}
