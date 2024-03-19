#pragma once
#include "Singleton.h"
#include "IManager.h"
#include "ZombieSpawner.h"


class ZombieWaveManager : public Singleton<ZombieWaveManager>
{
	vector<ZombieSpawner*> allSpawners;
	Timer* inBetweenWaveTimer = nullptr;
	float timeBetweenWave = 3.0f;

	ZombieSpawner* spawnerTest;

public:
	ZombieWaveManager();
	~ZombieWaveManager();

	void AddSpawner(ZombieSpawner* _spawner) { allSpawners.push_back(_spawner); }

public:
	void Init();
	void Update();
	bool CheckEndOfWave();
	void StartNewWave();
};

