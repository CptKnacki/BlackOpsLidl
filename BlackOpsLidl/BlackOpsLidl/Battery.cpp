#include "Battery.h"
#include "Macro.h"

Battery::Battery(const ShapeData& _data, const float _range)
	: RecipeIngredient(STRING_ID("Battery"), _data, _range, IT_BATTERY)
{


}
