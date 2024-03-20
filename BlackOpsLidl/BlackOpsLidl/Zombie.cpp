#include "Zombie.h"
#include "Game.h"
#include "ZombieWaveManager.h"

Zombie::Zombie(const ShapeData& _data) : Enemy(STRING_ID("Zombie"), _data)
{
	navigation = new IANavigationComponent(this);
	components.push_back(navigation);


	ZombieWaveManager::GetInstance().AddZombie(this);
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

	navigation->Init();
}

void Zombie::Update(const float _deltaTime)
{
	Enemy::Update(_deltaTime);

	//FollowPathToPlayer();
}

void Zombie::FollowPathToPlayer()
{
	//SetShapePosition(Game::GetPlayer()->GetShapePosition());

}

void Zombie::DrawCurrentPath()
{
	currentPath = navigation->GetAstarAlgo()->correctPath;

	if (currentPath.size() == 0)
		return;
	
	cout << "NODE! \n";
	for (size_t i = 0; i < currentPath.size() - 1; i++)
	{
	
		sf::VertexArray lines(sf::LinesStrip, 2);
		lines[0].position = currentPath[i]->position;
		lines[1].position = currentPath[i + 1]->position;
		lines[0].color = Color::Green;
		lines[1].color = Color::Green;
	
		Game::GetWindow().draw(lines);
	}
}
