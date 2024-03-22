#include "GPE_Bus.h"
#include "Macro.h"
#include "LevelManager.h"
#include "Game.h"

GPE_Bus::GPE_Bus(const ShapeData& _data) : InteractableActor(STRING_ID("Bus"), _data)
{
}

void GPE_Bus::Interact()
{
	//string _newLevelPath = GetLevelFromIndex(LevelManager::GetInstance().GetNextLevelIndex());
	//Game::GetMap()->LoadMapData(_newLevelPath);

	//TODO décharger la current map puis charger la nouvelle
}
