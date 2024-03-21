#include "Game.h"
#include "TimerManager.h"
#include "InputManager.h"
#include "ActorManager.h"
#include "ZombieWaveManager.h"
#include "HUD.h"
#include "Widget.h"
#include "Spawner.h"

#define PATH_PLAYER "Animations/knighModif.png"


RenderWindow Game::window;
Map* Game::map;
Player* Game::player;
Camera* Game::camera;
Brightness* Game::brightness;
GridNavigation* Game::grid;

#include "TriggerBox.h"

#define PATH_ZOMBIE "Animations/Zombie.png"
#define PATH_TEST_ZOMBIE "Animations/TEST_Zombie.png"

#define PATH_HORIZONTAL_FENCE "HorizontalFence.png"
#define PATH_VERTICAL_FENCE "VerticalFence.png"

#include "Zombie.h"
#include "GPE_Fence.h"

Game::Game()
{
	menu = new MainMenu();
	player = new Player("Player", ShapeData(Vector2f(0, 0), Vector2f(75.0f, 75.0f), PATH_PLAYER));
	map = new Map();
	camera = new Camera();
	brightness = new Brightness();

	grid = new GridNavigation(17, 50, Vector2f(-300,-400));
} 

Game::~Game()
{
	delete map;
	delete brightness;
}


void Game::Start()
{
	window.create(VideoMode(1920, 1080), "BlackOpsLidl", Style::Fullscreen);

	TimerManager::GetInstance().SetRenderCallback(bind(&Game::UpdateWindow, this));
	new Timer([&]() { Init(); }, seconds(1.0f), true, false);
}

void Game::Init()
{
	menu->Init();
	map->Init();
	camera->Init();
	brightness->Init();

	Vector2f _fenceSize = Vector2f(100, 50);
	ShapeData _dataFence = ShapeData(Vector2f(250.0f, -250.0f), _fenceSize, PATH_HORIZONTAL_FENCE);
	ShapeData _dataFence2 = ShapeData(Vector2f(350.0f, -250.0f), _fenceSize, PATH_HORIZONTAL_FENCE);

	GPE_Fence* _fenceTest = new GPE_Fence(_dataFence, 570);
	GPE_Fence* _fenceTest2 = new GPE_Fence(_dataFence2, 570);
	//_fenceTest2->GetShape()->setScale(sf::Vector2f(0, 0));


	grid->Generate();
	Vector2f _sizeZombie = Vector2f(80, 80);
	
	

	/*TriggerBox* _box = new TriggerBox(ShapeData(Vector2f(100.0f, 0.0f), Vector2f(200.0f, 200.0f), ""), [&]() {
		cout << "coucou" << endl;
	});

	_box->GetComponent<CollisionComponent>()->GetBoxCollision()->GetDrawable()->setOutlineThickness(-5.0f);
	_box->GetComponent<CollisionComponent>()->GetBoxCollision()->GetDrawable()->setFillColor(Color::Red);
	//
	//Vector2f _sizeBoofly = Vector2f(150.0f, 180.0f);
	//Vector2f _sizeBelfly = Vector2f(50.0f, 50.0f);
	//Vector2f _sizeHuskBully = Vector2f(75.0f, 75.0f);
	//Vector2f _sizeFalseKnight = Vector2f(700.0f, 500.0f);
	//
	//ShapeData _dataHuskBully = ShapeData(Vector2f(300.0f, -150.0f), _sizeHuskBully, PATH_HUSK_BULLY, IntRect(5, 21, 105, 135));
	//HuskBully* _huskBully = new HuskBully(_dataHuskBully);
	//_huskBully->Init();
	//
	//ShapeData _data = ShapeData(_positionFalseKnight, _sizeFalseKnight, PATH_FALSE_KNIGHT);
	//FalseKnight* _falseKnight = new FalseKnight(_data);
	//_falseKnight->Init();*/
}

void Game::Update()
{

	while (window.isOpen())
	{
		TimerManager::GetInstance().Update();
		if (!InputManager::GetInstance().Update(window)) break;
		player->GetLight()->setPosition(player->GetShapePosition().x + 50.0f, player->GetShapePosition().y + 50.0f);
		ActorManager::GetInstance().Update();
		ZombieWaveManager::GetInstance().Update();
	}
}

void Game::UpdateWindow()
{
	window.clear();

	const float _deltaTime = TimerManager::GetInstance().GetDeltaTime();
	camera->Update(_deltaTime);

	window.setView(camera->GetView());
	//DrawWorldUIs();

	DrawMap();
	DrawActors();
	//window.draw(*player->GetLight());
	DrawUIs();

	grid->ShowNodes();
	ZombieWaveManager::GetInstance().DrawZombiesPath();


	//DrawUIs();
	window.display();
}

#pragma region Draws

void Game::DrawWorldUIs()
{
	for (Canvas* _canvas : HUD::GetInstance().GetAllValues())
	{
		for (Widget* _widget : _canvas->GetWorldWidgets())
		{
			if (!_widget->IsVisible()) continue;
			const RenderStates& _render = _widget->CanApplyShader() ? brightness->shader : RenderStates::Default;
			window.draw(*_widget->GetDrawable(), _render);
		}
	}
}

void Game::DrawMap()
{
	for (ShapeObject* _drawable : map->GetAllDrawables())
	{
		window.draw(*_drawable->GetDrawable(), brightness->shader);
	}
}

void Game::DrawActors()
{
	for (Actor* _actor : ActorManager::GetInstance().GetAllValues())
	{
		window.draw(*_actor->GetDrawable(), brightness->shader);
	}
}

void Game::DrawUIs()
{
	View _view = window.getDefaultView();
	for (Canvas* _canvas : HUD::GetInstance().GetAllValues())
	{
		if (!_canvas->IsVisible()) continue;
		_view.setViewport(_canvas->GetRect());
		window.setView(_view);

		for (Widget* _widget : _canvas->GetUiWidgets())
		{
			if (!_widget->IsVisible()) continue;
			const RenderStates& _render = _widget->CanApplyShader() ? brightness->shader : RenderStates::Default;
			window.draw(*_widget->GetDrawable(), _render);
		}
	}
}

#pragma endregion

void Game::Stop()
{
	cout << "A bientot !" << endl;
}


void Game::Launch()
{
	Start();
	Update();
	Stop();
}

void Game::Close()
{
	window.close();
}