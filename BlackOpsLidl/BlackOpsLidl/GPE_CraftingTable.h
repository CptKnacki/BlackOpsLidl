#pragma once
#include "InteractableActor.h"

class GPE_CraftingTable : public InteractableActor 
{

public:
	GPE_CraftingTable(const ShapeData& _data);
	
public:
	virtual void Interact() override;
};

