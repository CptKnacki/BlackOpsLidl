#include "ZombieWaveManager.h"

ZombieWaveManager::ZombieWaveManager()
{

}

ZombieWaveManager::~ZombieWaveManager()
{
    delete spawnerTest;
    spawnerTest = nullptr;
}

void ZombieWaveManager::Init()
{
    inBetweenWaveTimer = new Timer([&]() { StartNewWave(); }, seconds(timeBetweenWave), false, false);

    //spawnerTest = new ZombieSpawner(0, Vector2f(400, 400)); // TODO à retirer ( juste pour les tests )
    //spawnerTest = new ZombieSpawner(0, Vector2f(-250, -100)); // TODO à retirer ( juste pour les tests )
    spawnerTest = new ZombieSpawner(0, Vector2f(550, -300)); // TODO à retirer ( juste pour les tests )
}

void ZombieWaveManager::Update()
{
    if (!inBetweenWaveTimer)
    {
        Init();
        return;
    }


    if (CheckEndOfWave() && !inBetweenWaveTimer->IsRunning())
        inBetweenWaveTimer->Start();

}

bool ZombieWaveManager::CheckEndOfWave()
{
    for (ZombieSpawner* _spawner : allSpawners)
    {
        if (_spawner->CheckHasZombiesLeft())
            return false;
    }

    return true;
}

void ZombieWaveManager::StartNewWave()
{
    cout << "NEW WAVE ! \n";
    for (ZombieSpawner* _spawner : allSpawners)
    {
        if (!_spawner)
            continue;

        _spawner->AddZombieCount(1);
        _spawner->SpawnZombieWave();
    }
}

void ZombieWaveManager::DrawZombiesPath()
{
    for (Zombie* _zombie : allZombies)
    {
        if (!_zombie)
            continue;
        _zombie->DrawCurrentPath();
    }
}
