#include "ZombieWaveManager.h"

ZombieWaveManager::ZombieWaveManager()
{

}

void ZombieWaveManager::Init()
{
    inBetweenWaveTimer = new Timer([&]() { StartNewWave(); }, seconds(timeBetweenWave), false, false);

    ZombieSpawner* _spawner = new ZombieSpawner(5, Vector2f(0, 0)); // TODO à retirer ( juste pour les tests )
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
