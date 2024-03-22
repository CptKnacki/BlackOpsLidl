#pragma once
#include "Singleton.h"
#include "IManager.h"
#include "ZombieSpawner.h"


class ZombieWaveManager : public Singleton<ZombieWaveManager>
{
	vector<ZombieSpawner*> allSpawners;
	vector<Zombie*> allZombies;
	Timer* inBetweenWaveTimer = nullptr;
	float timeBetweenWave = 3.0f;
	int waveCount = 1;

	ZombieSpawner* spawnerTest;

public:
	ZombieWaveManager();
	~ZombieWaveManager();

	void AddSpawner(ZombieSpawner* _spawner) { allSpawners.push_back(_spawner); }
	void AddZombie(Zombie* _zombie) { allZombies.push_back(_zombie); }
	int GetWaveCount() const { return waveCount; }
public:
	void Init();
	void Update();
	bool CheckEndOfWave();
	void StartNewWave();
	void DrawZombiesPath();
	
};

