#pragma once
#include "Menu.h"

#define PATH_LIFEBAR "UIs/InGame/lifebar.png"
#define PATH_STAMINABAR "UIs/InGame/staminabar.png"


class InGameMenu : public Menu
{
	vector<ShapeWidget*> items;
	vector<ShapeWidget*> bonus;
	vector<ShapeWidget*> weapons;

	ShapeWidget* lifeBar;
	ShapeWidget* staminaBar;
	ShapeWidget* currentWeapon;

	Label* currentWeaponBulletsText;
	Label* moneyCountText;
	Label* currentWaveCount;

	vector<string> drinks;

public:
	InGameMenu(Menu* _owner);

public:
	virtual void Init() override;
	void UpdateMenu();
	void AddBonusDrinkUI(string _path);
};

