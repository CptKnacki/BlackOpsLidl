#pragma once
#include "Component.h"
#include "AstarAlgo.h"

class Timer;

class IANavigationComponent : public Component
{
	AstarAlgo* algoNavigation = nullptr;
	GridPointData* gridData = nullptr;
	Actor* endTarget = nullptr;
	Timer* requestTimer = nullptr;

public:
	IANavigationComponent(Actor* _owner);

	AstarAlgo* GetAstarAlgo() { return algoNavigation; }
public:
	virtual void Init() override;
	void Request();
	
};

