#include "GPE_Bus.h"
#include "Macro.h"
#include "LevelManager.h"
GPE_Bus::GPE_Bus(const ShapeData& _data) : InteractableActor(STRING_ID("Bus"), _data)
{
}

void GPE_Bus::Interact()
{
	string _newLevelPath = GetLevelFromIndex(LevelManager::GetInstance().GetNextLevelIndex());

	LevelData _newLevelData = LevelManager::GetInstance().LoadLevelData(_newLevelPath);

	//TODO Rajouter le traitement du LevelData pour charger les éléments
}
