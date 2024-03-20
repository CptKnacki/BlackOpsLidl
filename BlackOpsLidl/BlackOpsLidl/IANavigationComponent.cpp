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
	gridData = Game::GetNavigationGrid()->data;
	requestTimer = new Timer([&]() { Request(); }, seconds(1), true, true);
}

void IANavigationComponent::Request()
{
	if (!endTarget || !gridData)
		return;

	cout << "OIA";
	algoNavigation->ComputePath(gridData->GetClosestNode(owner->GetShapePosition()), gridData->GetClosestNode(endTarget->GetShapePosition()));
	
}
