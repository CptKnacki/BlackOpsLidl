#pragma once
#include "Actor.h"

class GPE_CraftingTable : public Actor // TODO InteractableActor ??
{


public:
	GPE_CraftingTable(const ShapeData& _data);
	

public:
	void TryToCraft();
};

