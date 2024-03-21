#include "GPE_CraftingTable.h"
#include "Macro.h"
#include "RecipeManager.h"

GPE_CraftingTable::GPE_CraftingTable(const ShapeData& _data) : Actor(STRING_ID("CraftingTable"), _data)
{


}

void GPE_CraftingTable::TryToCraft()
{
	RecipeManager::GetInstance().CheckForAnyRecipes();

}
