#pragma once
#include "Actor.h"


class GPE_Bus : public Actor
{
	int currentLevelIndex = 1;


public:
	GPE_Bus(const ShapeData& _data);

public:
	void ChangingLevelBehaviour();
};

