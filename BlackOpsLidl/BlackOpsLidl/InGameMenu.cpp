#include "InGameMenu.h"
#include "Game.h"
#include "ZombieWaveManager.h"
#include "Macro.h"


InGameMenu::InGameMenu(Menu* _owner) : Menu("InGame", _owner)
{
	const Vector2f& _windowSize = Game::GetWindowSize(); // Egal a zéro ici :'(

	Vector2f _waveCountPosition = Vector2f(1900, 10);
	currentWaveCount = new Label(TextData("", _waveCountPosition, FONT, 34, Color::Red), AT_CENTER);
	canvas->AddWidget(currentWaveCount);

	Vector2f _moneyCountPosition = Vector2f(1850, 850);
	moneyCountText = new Label(TextData("", _moneyCountPosition, FONT, 34, Color::Red), AT_CENTER);
	canvas->AddWidget(moneyCountText);


	Vector2f _lifeBarPosition = Vector2f(300, 30);
	Vector2f _lifeBarSize = Vector2f(550, 50);
	lifeBar = new ShapeWidget(ShapeData(_lifeBarPosition, _lifeBarSize, PATH_LIFEBAR));
	canvas->AddWidget(lifeBar);

	Vector2f _staminaBarPosition = Vector2f(300, 80);
	Vector2f _staminaBarSize = Vector2f(550, 30);
	staminaBar = new ShapeWidget(ShapeData(_staminaBarPosition, _staminaBarSize, PATH_STAMINABAR));
	canvas->AddWidget(staminaBar);
}

void InGameMenu::Init()
{
	Menu::Init();
}

void InGameMenu::UpdateMenu()
{
	PlayerStat* _playerStats = Game::GetPlayer()->GetStats();
	PlayerInventoryComponent* _playerInventory = Game::GetPlayer()->GetInventory();

	string _waveString = to_string(ZombieWaveManager::GetInstance().GetWaveCount());
	currentWaveCount->SetString(_waveString);

	float _lifeScaleFactor = _playerStats->GetCurrentLife() / _playerStats->GetMaxLife();
	lifeBar->GetDrawable()->setScale(Vector2f(_lifeScaleFactor, 1));

	float _staminaScaleFactor = _playerStats->GetCurrentStamina() / _playerStats->GetMaxStamina();
	staminaBar->GetDrawable()->setScale(Vector2f(_staminaScaleFactor, 1));

	string _moneyString = to_string(_playerStats->GetMoney()) + "$";
	moneyCountText->SetString(_moneyString);

	

}

void InGameMenu::AddBonusDrinkUI(string _path)
{
	if (drinks.size() != 0)
	{
		for (string _str : drinks)
		{
			if (_str == _path)
				return;
		}
	}

	Vector2f _bonusIconPosition = Vector2f(50, 125);
	Vector2f _bonusIconSize = Vector2f(40, 40);

	Vector2f _nextPosition = _bonusIconPosition + Vector2f((_bonusIconSize.x + 10) * drinks.size(), 0);

	ShapeWidget* _shape = new ShapeWidget(ShapeData(_nextPosition, _bonusIconSize, _path));

	drinks.push_back(_path);
	canvas->AddWidget(_shape);

}

void InGameMenu::AddItemUI(string _path)
{
	if (items.size() != 0)
	{
		for (string _str : items)
		{
			if (_str == _path)
				return;
		}
	}

	Vector2f _itemIconPosition = Vector2f(70, 250);
	Vector2f _itemIconSize = Vector2f(60, 60);

	Vector2f _nextPosition = _itemIconPosition + Vector2f(0, (_itemIconSize.y + 10) * items.size());

	ShapeWidget* _shape = new ShapeWidget(ShapeData(_nextPosition, _itemIconSize, _path));

	items.push_back(_path);
	canvas->AddWidget(_shape);

}

