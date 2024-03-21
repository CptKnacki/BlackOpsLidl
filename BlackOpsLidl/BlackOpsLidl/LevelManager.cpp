#include "LevelManager.h"

LevelManager::LevelManager()
{

}

int LevelManager::GetNextLevelIndex()
{
	if (currentLevelIndex == allLevelsIndexes.size() - 1)
		return currentLevelIndex;

	currentLevelIndex++;

	return currentLevelIndex;

}

LevelData LevelManager::LoadLevelData(const string& _path)
{
	return LevelData();
}
