#pragma once
#include "Singleton.h"
#include "GPE_BonusDrink.h"

#define JUGGERNAUT "Juggernaut"
#define DOUBLE_SHOT "DoubleShot"
#define SPEED_COLA "SpeedCola"
#define ENERGY_DRINK "EnergyDrink"
#define PHD_FLOPPER "PHDFlopper"
#define DEADSHOT_DAIQUIRI "DeadshotDaiquiri"


class BonusDrinkManager : public Singleton<BonusDrinkManager>
{
	vector<GPE_BonusDrink*> allDrinks;

public:
	BonusDrinkManager();

public:
	GPE_BonusDrink* GetDrinkByName(string _drinkName);

};

