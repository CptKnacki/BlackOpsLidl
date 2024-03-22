#pragma once
#include "CollectableActor.h"

class RecipeIngredient : public CollectableActor
{

public:
	RecipeIngredient(const string& _name, const ShapeData& _data, const float _range, const ItemType& _type);
};

