#include "PlayerStat.h"
#include "PlayerAnimationComponent.h"
#include "PlayerMovementComponent.h"
#include "Game.h"
#include "TextureManager.h"
#include"FxManager.h"
#include "Timer.h"

#include <iostream>
#include"Game.h"
#include"DeathMob.h"

#define PATH_MANA_FULL "UIs/Player/Mana/ManaBar_Full.png"
#define PATH_MANA_EMPTY "UIs/Player/Mana/ManaBar_Empty.png"
#define PATH_GEO "UIs/Inventory/Geo.png"
#define FONT "pixelmix.ttf"
#define PATH_DEATHMOB "Animations/DeathMob.png"

PlayerStat::PlayerStat(Player* _player) : Menu("PlayerStat", nullptr)
{

	maxLife = 100;
	currentLife = maxLife;
	lifeRegen = 2;

	maxStamina = 100;
	currentStamina = maxStamina;
	staminaRegen = 5;
	
	moneyCount = 2000;
	
	headShotPercentage = 15;

	animation = _player->GetComponent<PlayerAnimationComponent>();
	movement = _player->GetComponent<PlayerMovementComponent>();

	numberOfDeath = 0;
}


void PlayerStat::Init()
{
	#pragma region Mana

	const Vector2f& _manaPos = Vector2f(150.0f, 80.0f);
	const Vector2f& _manaSize = Vector2f(200.0f, 130.0f);
	//manaBar = new ProgressBar(ShapeData(_manaPos, _manaSize, PATH_MANA_EMPTY),
	//						  PATH_MANA_FULL, ProgressType::PT_BOTTOM);
	//canvas->AddWidget(manaBar);
	//canvas->AddWidget(manaBar->GetForeground());

	#pragma endregion

	#pragma region Geos

	//const Vector2f& _geoPos = _manaPos + Vector2f(35.0f, 50.0f);
	//const Vector2f& _geoSize = Vector2f(40.0f, 40.0f);
	//ShapeWidget* _geoIcon = new ShapeWidget(ShapeData(_geoPos, _geoSize, PATH_GEO));
	//canvas->AddWidget(_geoIcon);
	//
	//const Vector2f& _geoTextPos = _geoPos + Vector2f(25.0f, -5.0f);
	//geosCountText = new Label(TextData(to_string(geosCount), _geoTextPos, FONT, 22), AT_LEFT);
	//canvas->AddWidget(geosCountText);

	#pragma endregion

	regenTimer = new Timer([&]() { RegenLifeAndStamina(); }, seconds(1), true, true);
}


void PlayerStat::UseStamina(const int _factor)
{
	currentStamina -= _factor;
}


void PlayerStat::UpdateLife(const int _count)
{

	currentLife += _count;

	if (currentLife <= 0)
	{
		Death();
	}
}


void PlayerStat::UpdateMoney(const int _factor)
{
	moneyCount += _factor;

}


void PlayerStat::Death()
{
	numberOfDeath++;

	////TODO remove
	//for (Actor* _actor : ActorManager::GetInstance().GetAllValues())
	//{
	//	if (DeathMob* _death = dynamic_cast<DeathMob*>(_actor))
	//	{
	//		// _death->SetToRemove(true);
	//		_death->GetDrawable()->setScale(Vector2f(0.0f, 0.0f)); ///TODO CHANGE
	//	}
	//}
	//
	//Player* _player = Game::GetPlayer();
	//Vector2f _lastPos = _player->GetShapePosition();
	//DeathMob* _deathMob = new DeathMob("Death" + to_string(numberOfDeath), ShapeData(_lastPos, Vector2f(100.0f, 100.0f), PATH_DEATHMOB));
	//_deathMob->Init();
	//
	//if (Bench* _bench = Game::GetMap()->GetBench())
	//{
	//	const Vector2f& _benchPos = _bench->GetShapePosition();
	//	Game::GetPlayer()->SetShapePosition(_benchPos);
	//}
	//
	//for (int _index = 0; _index < currentMaxLifesCount; _index++)
	//{
	//	_player->GetStats()->UpdateLife(1);
	//} 
}

void PlayerStat::RegenLifeAndStamina()
{
	
	if (currentStamina < maxStamina)
		currentStamina = (currentStamina + staminaRegen >= maxStamina) ? maxStamina : currentStamina + staminaRegen;

	if (currentLife < maxLife)
		currentLife = (currentLife + lifeRegen >= maxLife) ? maxLife : currentLife + lifeRegen;
}
