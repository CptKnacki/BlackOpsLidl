#include "Fan.h"
#include "Macro.h"

Fan::Fan(const ShapeData& _data, const float _range) 
	: RecipeIngredient(STRING_ID("Fan"), _data, _range, IT_FAN)
{

}
