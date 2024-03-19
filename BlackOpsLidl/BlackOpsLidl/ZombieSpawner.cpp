#include "ZombieSpawner.h"
#include "ZombieWaveManager.h"

#define PATH_ZOMBIE "Animations/Zombie.png"

ZombieSpawner::ZombieSpawner(int _count, Vector2f _spawnPosition)
{
	zombieCount = _count;
	spawnPosition = _spawnPosition;
	inBetweenSpawnTimer = new Timer([&]() {SpawnZombie(); }, seconds(1), false, true);

	ZombieWaveManager::GetInstance().AddSpawner(this);
}

void ZombieSpawner::SpawnZombieWave()
{
	zombieList.clear();
	
	currentWaveCount = 0;
	inBetweenSpawnTimer->Start();

}

void ZombieSpawner::SpawnZombie()
{
	if (currentWaveCount >= zombieCount)
	{
		inBetweenSpawnTimer->Stop();
		return;
	}

	Vector2f _sizeZombie = Vector2f(80, 80);
	ShapeData _dataZombie = ShapeData(Vector2f(0.0f + 100 * currentWaveCount, 0.0f), _sizeZombie, PATH_ZOMBIE);

	Zombie* _zombie = new Zombie(_dataZombie);
	_zombie->Init();
	zombieList.push_back(_zombie);

	currentWaveCount++;

}




bool ZombieSpawner::CheckHasZombiesLeft()
{
	return zombieList.size() != 0;
}
