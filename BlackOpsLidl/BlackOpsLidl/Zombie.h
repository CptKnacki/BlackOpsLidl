#pragma once
#include "Enemy.h"
#include "IANavigationComponent.h"


class Zombie : public Enemy
{

	IANavigationComponent* navigation = nullptr;
	vector<Node*> currentPath;
public:
	Zombie(const ShapeData& _data);

public:
	virtual void Init() override;
	virtual void Update(const float _deltaTime) override;
	void FollowPathToPlayer();
	void DrawCurrentPath();
};

