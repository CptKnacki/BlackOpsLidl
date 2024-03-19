#include "Zombie.h"
#include "Game.h"

Zombie::Zombie(const ShapeData& _data) : Enemy(STRING_ID("Zombie"), _data)
{
	navigation = new IANavigationComponent(this);
	components.push_back(navigation);
}

void Zombie::Init()
{
	const Vector2f& _size = Vector2f(30, 30);

	const float _speed = 0.08f;
	cout << "NEW ZOMBIE SPAWNED \n";

	animation->InitAnimations(
		{
			AnimationData("Attack", Vector2f(5.0f, 38.0f), _size, READ_RIGHT, true, 1, _speed, "Idle"),
			AnimationData("Death", Vector2f(5.0f, 165.0f), _size, READ_RIGHT, true, 8, _speed, ""),
			AnimationData("Idle", Vector2f(5.0f, 5.0f), _size, READ_RIGHT, true, 8, _speed, ""),
			AnimationData("Running", Vector2f(5.0f, 70.0f), _size, READ_RIGHT, true, 8, _speed, ""),
		});

	currentPath = navigation->GetAstarAlgo()->correctPath;
}

void Zombie::Update(const float _deltaTime)
{
	Enemy::Update(_deltaTime);

	//FollowPathToPlayer();
}

void Zombie::FollowPathToPlayer()
{
	//SetShapePosition(Game::GetPlayer()->GetShapePosition());


	vector<Node*> _co = navigation->GetAstarAlgo()->correctPath;

}
