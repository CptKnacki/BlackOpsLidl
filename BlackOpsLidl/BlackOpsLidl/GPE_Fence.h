#pragma once
#include "InteractableActor.h"




class GPE_Fence : public InteractableActor
{

	bool isOpen;
	int moneyRequired;

public:
	GPE_Fence(const ShapeData& _data, int _moneyRequired);

	bool GetIsOpen() const { return isOpen; }
	int GetMoneyRequired() const { return moneyRequired; }

public:
	virtual void Interact() override;
	void OpenDoor();
	void CloseDoor();
};

