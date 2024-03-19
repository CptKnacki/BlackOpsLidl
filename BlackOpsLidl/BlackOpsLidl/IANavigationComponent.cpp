#include "IANavigationComponent.h"
#include "Actor.h"
#include "Timer.h"
#include "Game.h"


IANavigationComponent::IANavigationComponent(Actor* _owner) :
	Component(_owner)
{
	algoNavigation = new AstarAlgo();
}

void IANavigationComponent::Init()
{
	endTarget = Game::GetPlayer();
	requestTimer = new Timer([&]() { Request(); }, seconds(1), true, true);
	gridData = Game::GetNavigationGrid()->data;
}

void IANavigationComponent::Request()
{
	if (!endTarget || !gridData)
		return;

	algoNavigation->ComputePath(gridData->GetClosestNode(owner->GetShapePosition()), gridData->GetClosestNode(endTarget->GetShapePosition()));
	
}
