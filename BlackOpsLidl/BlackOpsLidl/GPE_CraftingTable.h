#pragma once
#include "Actor.h"

class GPE_CraftingTable : public Actor
{


public:
	GPE_CraftingTable(const ShapeData& _data);
	// TODO Cr�er une classe Recipe ainsi qu'un manager de Recipe qui sera parcouru dans la m�thode CheckForRecipes

public:
	void CheckForRecipes();
};

