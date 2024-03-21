#pragma once
#include "RecipeIngredient.h"
class Battery : public RecipeIngredient
{

public:
	Battery(const ShapeData& _data, const float _range);
};

