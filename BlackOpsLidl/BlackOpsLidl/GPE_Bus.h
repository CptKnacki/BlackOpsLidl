#pragma once
#include "InteractableActor.h"


class GPE_Bus : public InteractableActor
{
	int currentLevelIndex = 1;


public:
	GPE_Bus(const ShapeData& _data);

public:
	virtual void Interact() override;
};

