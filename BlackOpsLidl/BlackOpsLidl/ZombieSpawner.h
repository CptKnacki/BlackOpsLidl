#pragma once
#include "Zombie.h"


class ZombieSpawner
{
	int zombieCount = 3;
	int currentWaveCount = 0;
	vector<Zombie*> zombieList;
	Vector2f spawnPosition;
	Timer* inBetweenSpawnTimer;

public:
	ZombieSpawner(int _count, Vector2f _spawnPosition);

	void AddZombieCount(int _count) { zombieCount += _count; }
public:
	void SpawnZombieWave();
	void SpawnZombie();
	bool CheckHasZombiesLeft();
};

