#pragma once
#include "Component.h"
#include "PlayerInventoryComponent.h"
#include "Merchand.h"
#include"PNJ.h"

class InteractionComponent : public Component
{
	float range;
	PlayerInventoryComponent* inventory;
	Merchand* merchand;
	PNJ* pnj;

public:
	InteractionComponent(Actor* _owner);

public:
	void TryToInteract();
	void StopInteract();
};