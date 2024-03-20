#pragma once
#include "Actor.h"




class GPE_Fence : public Actor
{

	bool isOpen;
	int moneyRequired;

public:
	GPE_Fence(const ShapeData& _data, int _moneyRequired);

	bool GetIsOpen() const { return isOpen; }
	int GetMoneyRequired() const { return moneyRequired; }

public:
	void TryToOpen();
	void OpenDoor();
	void CloseDoor();
};

