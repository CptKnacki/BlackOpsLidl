#pragma once
#include "Singleton.h"
#include "Actor.h"

struct LevelData
{
	string backgroundPath;
	Vector2f backgroundPos;
	Vector2f backgroundSize;

};

class LevelManager : public Singleton<LevelManager>
{

	vector<int> allLevelsIndexes;
	int currentLevelIndex = 1;


public:
	LevelManager();
	int GetNextLevelIndex();
	LevelData LoadLevelData(const string& _path);
};

