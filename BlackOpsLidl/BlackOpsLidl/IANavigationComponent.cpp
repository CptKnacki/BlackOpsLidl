#include "IANavigationComponent.h"
#include "Actor.h"
#include "Timer.h"
#include "Game.h"
#include "Zombie.h"


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

	Zombie* _zombie = dynamic_cast<Zombie*>(owner);
	if (_zombie)
		_zombie->ResetNodeIndex();

	
	algoNavigation->ComputePath(gridData->GetClosestNode(owner->GetShapePosition()), gridData->GetClosestNode(endTarget->GetShapePosition()));

	
}
