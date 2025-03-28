#include "ShopMenu.h"
#include "Merchand.h"
#include "Game.h"
#include "HUD.h"

#define PATH_AK47 "Weapons/AK-47.png"
#define PATH_TEC9 "Weapons/TEC-9.png"
#define PATH_MP9 "Weapons/MP9.png"
#define PATH_SCOUT "Weapons/SCOUT.png"
#define PATH_VEKTOR2 "Weapons/VEKTOR-2.png"
#define PATH_BARRET50 "Weapons/BARRET-50.png"

#define PATH_SHOP "UIs/Shop/Shop.png"
#define PATH_DOLLAR "DollarBill.png"

ShopMenu::ShopMenu(Menu* _owner, Merchand* _merchand) : Menu("Shop", _owner)
{
	timeBeforeOpenShop = 1.0f;
	buttons = vector<Button*>();
	descriptionTitle = nullptr;
	descriptionText = nullptr;
	timer = nullptr;
	merchand = _merchand;
	purchase = new PurchaseMenu(this);
}


void ShopMenu::Init()
{
	const Vector2f& _windowSize = Game::GetWindowSize();
	const Vector2f& _halfWindowSize = Game::GetWindowSize() / 2.0f;

	#pragma region Background

	const Vector2f& _shopSize = Vector2f(_halfWindowSize.x, _windowSize.y);
	const Vector2f& _shopPos = Vector2f(_halfWindowSize.x, _halfWindowSize.y);
	ShapeWidget* _shop = new ShapeWidget(ShapeData(_shopPos, _shopSize, PATH_SHOP));
	canvas->AddWidget(_shop);

	#pragma endregion

	#pragma region Grid

	items = {
		{
			PATH_TEC9,
			850,
			"TEC-9",
			"A small full auto handgun but with a very \n bad temper."
		},
		{
			PATH_MP9,
			1600,
			"MP9",
			"A popular submachine gun easy to control \n but not to handle."
		},
		{
			PATH_VEKTOR2,
			1850,
			"Vektor-2",
			"A cool submachine gun known for his incredible \n fire rate."
		},
		{
			PATH_SCOUT,
			2100,
			"Scout",
			"A Simple sniper rifle that may or may not help \n you bunny hop."
		},
		{
			PATH_AK47,
			2700,
			"AK-47",
			"The one and only legendary rifle."
		},
		{
			PATH_BARRET50,
			3500,
			"Barret-50",
			"A massive sniper rifle that can pierce throught \n almost anything."
		},

	};

	const float _widgetPosX = _shopPos.x - _shopSize.x * 0.35f;
	const Vector2f& _widgetSize = Vector2f(120.0f, 60.0f);
	const float _dollarPosX = _widgetPosX + _widgetSize.x;
	const Vector2f& _dollarSize = Vector2f(60.0f, 40.0f);
	const float _dollarTextPosX = _dollarPosX + _dollarSize.x * 0.8f;
	const float _startPosY = _shopPos.y - _shopSize.y * 0.275f;
	const float _gapY = 10.0f;
	const Vector2f& _buttonSize = Vector2f(_shopSize.x * 0.4f, _widgetSize.y + _widgetSize.y * 0.7f);
	const float _buttonPosX = _widgetPosX + _buttonSize.x * 0.2f;
	int _index = 0;

	for (const SellItem& _item : items)
	{
		const float _posY = _startPosY + _index * _widgetSize.y + _gapY * _index;

		Button* _button = new Button(ShapeData(Vector2f(_buttonPosX, _posY), _buttonSize));
		_button->GetDrawable()->setFillColor(Color::Transparent);
		_button->GetData().hoveredCallback = [&]()
		{
			if (Button* _hoveredButton = HUD::GetInstance().GetHoveredButton(buttons))
			{
				MovePointers(_hoveredButton);

				if (ItemWidget* _itemWidget = dynamic_cast<ItemWidget*>(_hoveredButton->GetForeground()))
				{
					descriptionTitle->SetString(_itemWidget->GetTitle());
					descriptionText->SetString(_itemWidget->GetText());
				}
			}
		};
		_button->GetData().pressedCallback = [&]() {
			if (Button* _hoveredButton = HUD::GetInstance().GetHoveredButton(buttons))
			{
				const SellItem& _item = GetSellItemByButton(_hoveredButton);
				purchase->SetItem(_item);
			}
			SetStatus(false);
			purchase->SetStatus(true);
		};
		buttons.push_back(_button);
		canvas->AddWidget(_button);

		ItemWidget* _widget = new ItemWidget(ShapeData(Vector2f(_widgetPosX, _posY), _widgetSize, _item.path),
											 _item.title, _item.text);
		canvas->AddWidget(_widget);
		_button->SetForeground(_widget);

		ShapeWidget* _dollar = new ShapeWidget(ShapeData(Vector2f(_dollarPosX, _posY), _dollarSize, PATH_DOLLAR));
		canvas->AddWidget(_dollar);

		Label* _dollarText = new Label(TextData(to_string(_item.price), Vector2f(_dollarTextPosX, _posY - 3.5f), FONT), AT_CENTER);
		canvas->AddWidget(_dollarText);

		_index++;
	}

	#pragma region Pointer

	Menu::Init();
	MovePointers(buttons.front());

	#pragma endregion

	#pragma endregion

	#pragma region Description

	const Vector2f& _descriptionSize = Vector2f(_shopSize.x / 2.0f, _shopSize.y * 0.6f);
	const Vector2f& _descriptionPos = _shopPos + Vector2f(_descriptionSize.x * 0.3f, 0.0f);
	/*ShapeWidget* _description = new ShapeWidget(ShapeData(_descriptionPos, _descriptionSize, ""));
	canvas->AddWidget(_description);*/

	#pragma region Title

	const float _descriptionTitlePosX = _descriptionPos.x;
	const float _descriptionTitlePosY = _descriptionPos.y - _descriptionPos.y / 2.0f;
	const Vector2f& _descriptionTitlePos = Vector2f(_descriptionTitlePosX, _descriptionTitlePosY);
	descriptionTitle = new Label(TextData("", _descriptionTitlePos, FONT, 22), AT_CENTER);
	canvas->AddWidget(descriptionTitle);

	#pragma endregion

	#pragma region Text

	const float _descriptionTextPosX = _descriptionPos.x - _descriptionSize.x * 0.45f;
	const float _descriptionTextPosY = _descriptionTitlePosY + _descriptionSize.y * 0.15f;
	const Vector2f& _descriptionLabelPos = Vector2f(_descriptionTextPosX, _descriptionTextPosY);
	descriptionText = new Label(TextData("", _descriptionLabelPos, FONT, 13), AT_LEFT);
	canvas->AddWidget(descriptionText);

	#pragma endregion

	#pragma endregion
}

void ShopMenu::SetStatus(const bool _status, const bool _applyToWidgets)
{
	if (!_status)
	{
		timer = nullptr;
		Menu::SetStatus(false);
		purchase->SetStatus(false);
	}

	else
	{
		timer = new Timer([&]() {
			merchand->CloseDiscussion();
			Open();
		}, seconds(timeBeforeOpenShop));
	}
}

void ShopMenu::Open()
{
	Menu::SetStatus(true);
}