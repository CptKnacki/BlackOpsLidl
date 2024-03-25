#pragma once
#include "Menu.h"

#define PATH_LIFEBAR "UIs/InGame/lifebar.png"
#define PATH_STAMINABAR "UIs/InGame/staminabar.png"
#define PATH_WEAPON "Weapons/AK-47.png"


class InGameMenu : public Menu
{
	vector<ShapeWidget*> weapons;

	ShapeWidget* lifeBar;
	ShapeWidget* staminaBar;
	ShapeWidget* currentWeapon;

	Label* currentWeaponBulletsText;
	Label* moneyCountText;
	Label* currentWaveCount;

	vector<string> items;
	vector<string> drinks;


public:
	InGameMenu(Menu* _owner);


	vector<string> GetItemsList() const { return items; }
public:
	virtual void Init() override;
	void UpdateMenu();
	void AddBonusDrinkUI(string _path);
	void AddItemUI(string _path);

};

