#pragma once
#include "Actor.h"
#include "Item.h"

class RecipeResult : public Actor
{
	ItemType itemType;

public:
	RecipeResult(const string& _itemName, const ShapeData& _data, const ItemType& _type);

};

