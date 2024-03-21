#include "BonusDrinkManager.h"
#include "JuggernautDrink.h"
#include "DoubleShotDrink.h"
#include "SpeedColaDrink.h"
#include "EnergyDrink.h"
#include "PHDFlopperDrink.h"
#include "DeadshotDaiquiriDrink.h"
#include "Macro.h"

BonusDrinkManager::BonusDrinkManager()
{
	JuggernautDrink* _juggernaut = new JuggernautDrink();
	allDrinks.push_back(_juggernaut);

	DoubleShotDrink* _doubleShot = new DoubleShotDrink();
	allDrinks.push_back(_doubleShot);

	SpeedColaDrink* _speedCola = new SpeedColaDrink();
	allDrinks.push_back(_speedCola);

	EnergyDrink* _energyDrink = new EnergyDrink();
	allDrinks.push_back(_energyDrink);

	PHDFlopperDrink* _phdFlopper = new PHDFlopperDrink();
	allDrinks.push_back(_phdFlopper);

	DeadshotDaiquiriDrink* _deadshotDaiquiri = new DeadshotDaiquiriDrink();
	allDrinks.push_back(_deadshotDaiquiri);
}

GPE_BonusDrink* BonusDrinkManager::GetDrinkByName(string _drinkName)
{
	for (GPE_BonusDrink* _drink : allDrinks)
	{
		if (_drink->GetDrinkName() == _drinkName)
			return _drink;
	}

    return nullptr;
}
