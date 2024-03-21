#include "Zombie.h"
#include "Game.h"
#include "ZombieWaveManager.h"
#include "ZombieBrain.h"

Zombie::Zombie(const ShapeData& _data) : Enemy(STRING_ID("Zombie"), _data)
{
	navigation = new IANavigationComponent(this);
	components.push_back(navigation);

	movement = new MobMovementComponent(this);
	components.push_back(movement);

	brain = new ZombieBrain(this);
	brain->GetBlackBoard()->hasTarget = true;
	components.push_back(brain);


	ZombieWaveManager::GetInstance().AddZombie(this);
}

void Zombie::Init()
{
	cout << "NEW ZOMBIE SPAWNED \n";

	const Vector2f& _size = Vector2f(30, 30);

	const float _speed = 0.08f;

	animation->InitAnimations(
		{
			AnimationData("Idle", Vector2f(5.0f, 5.0f), _size, READ_RIGHT, true, 8, _speed, ""),
			AnimationData("Running", Vector2f(5.0f, 70.0f), _size, READ_RIGHT, true, 8, _speed, ""),
			AnimationData("Attack", Vector2f(5.0f, 38.0f), _size, READ_RIGHT, true, 7, _speed, ""),
			AnimationData("Death", Vector2f(5.0f, 165.0f), _size, READ_RIGHT, true, 8, _speed, ""),
		});

	navigation->Init();
}

void Zombie::Update(const float _deltaTime)
{
	Enemy::Update(_deltaTime);

	currentPath = navigation->GetAstarAlgo()->correctPath;
	FollowPathToPlayer();
	CheckIsInRange();

}

void Zombie::FollowPathToPlayer()
{
	//if (currentPath.size() == 0)
	//	return;
	//
	//if (movement->IsAtPosition() && currentNodeIndex < currentPath.size() - 2)
	//	currentNodeIndex++;
	//	
	//movement->SetDestination(currentPath[currentNodeIndex]->position);

	// TODO FIX LE CRASH ZEBI
}

void Zombie::DrawCurrentPath()
{
	if (currentPath.size() == 0)
		return;
	
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

void Zombie::CheckIsInRange()
{
	Vector2f _playerPosition = Game::GetPlayer()->GetShapePosition();

	
	bool _isInRange = (Distance(GetShapePosition(), _playerPosition) <= attackRange);
	brain->GetBlackBoard()->isInRange = _isInRange;


}
