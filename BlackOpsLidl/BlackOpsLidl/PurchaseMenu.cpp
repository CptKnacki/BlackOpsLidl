#include "PurchaseMenu.h"
#include "Game.h"
#include "HUD.h"
#include "TextureManager.h"

#define PATH_SHOP "UIs/Shop/Shop.png"
#define PATH_DOLLAR "DollarBill.png"

PurchaseMenu::PurchaseMenu(Menu* _owner) : Menu("Purchase", _owner)
{
	buttons = vector<Button*>();
}


void PurchaseMenu::Init()
{
	const Vector2f& _windowSize = Game::GetWindowSize();
	const Vector2f& _halfWindowSize = Game::GetWindowSize() / 2.0f;

	#pragma region Background

	const Vector2f& _shopSize = Vector2f(_halfWindowSize.x, _windowSize.y);
	const Vector2f& _shopPos = Vector2f(_halfWindowSize.x, _halfWindowSize.y);
	ShapeWidget* _shop = new ShapeWidget(ShapeData(_shopPos, _shopSize, PATH_SHOP));
	canvas->AddWidget(_shop);

	#pragma endregion

	const float _titlePosY = _shopPos.y - _shopSize.y * 0.25f;
	title = new Label(TextData("", Vector2f(_shopPos.x, _titlePosY), FONT, 22));
	canvas->AddWidget(title);

	const float _itemPosY = _titlePosY + 75.0f;
	const Vector2f& _itemSize = Vector2f(135.0f, 85.0f);
	icon = new ShapeWidget(ShapeData(Vector2f(_shopPos.x, _itemPosY), _itemSize, ""));
	canvas->AddWidget(icon);

	const float _dollarPosY = _titlePosY + 130.0f;
	const Vector2f& _dollarSize = Vector2f(60.0f, 40.0f);
	ShapeWidget* _dollar = new ShapeWidget(ShapeData(Vector2f(_shopPos.x - 50.0f, _dollarPosY), _dollarSize, PATH_DOLLAR));
	canvas->AddWidget(_dollar);

	price = new Label(TextData("", Vector2f(_shopPos.x + 5.0f, _dollarPosY), FONT, 22));
	canvas->AddWidget(price);

	const float _questionPosY = _dollarPosY + 50.0f;
	Label* _question = new Label(TextData("Purchase this item ?", Vector2f(_shopPos.x, _questionPosY), FONT, 16));
	canvas->AddWidget(_question);

	const float _warnMessagePosY = _shopPos.y + _shopSize.y * 0.25f;
	warnMessage = new Label(TextData("", Vector2f(_shopPos.x, _warnMessagePosY), FONT, 16));
	warnMessage->SetVisible(false);
	canvas->AddWidget(warnMessage);

	#pragma region Grid

	struct ButtonData
	{
		string text;
		function<void()> callback;

		ButtonData(const string& _text, const function<void()>& _callback)
		{
			text = _text;
			callback = _callback;
		}
	};

	const vector<ButtonData>& _allData = {
		ButtonData("Yes", [&]() {
			if (canBuy)
			{
				BuyCurrentItem();
				SetStatus(false);
			}
		}),
		ButtonData("No", [&]() {
			SetStatus(false);
			dynamic_cast<ShopMenu*>(owner)->Open();
		}),
	};

	const Vector2f& _buttonSize = Vector2f(100.0f, 50.0f);
	const float _gridPosY = _questionPosY + 50.0f;
	const float _gapY = 0.0f;

	const int _buttonsCount = (int)_allData.size();
	for (int _index = 0; _index < _buttonsCount; _index++)
	{
		const float _buttonPosY = _gridPosY + _buttonSize.y * _index + _gapY * _index;
		const Vector2f& _buttonPos = Vector2f(_shopPos.x, _buttonPosY);
		Button* _button = new Button(ShapeData(_buttonPos, _buttonSize, ""));
		_button->GetData().hoveredCallback = [&]()
		{
			if (Button* _hoveredButton = HUD::GetInstance().GetHoveredButton(buttons))
			{
				MovePointers(_hoveredButton);
			}
		};
		_button->GetData().pressedCallback = _allData[_index].callback;
		_button->GetDrawable()->setFillColor(Color::Transparent);
		buttons.push_back(_button);
		canvas->AddWidget(_button);

		Label* _title = new Label(TextData(_allData[_index].text, Vector2f(_shopPos.x, _buttonPos.y), FONT, 20));
		_button->SetForeground(_title);
		canvas->AddWidget(_title);

		if (_index == 0)
		{
			buyLabel = _title;
		}
	}

	#pragma endregion

	#pragma region Pointer

	Menu::Init();
	MovePointers(buttons.front());

	#pragma endregion
}

void PurchaseMenu::SetItem(const SellItem& _item)
{
	item = _item;
	title->SetString(_item.title);
	TextureManager::GetInstance().Load(icon->GetObject(), _item.path);
	price->SetString(to_string(_item.price));

	SetCanBuyItem();


	buyLabel->GetDrawable()->setFillColor(canBuy ? Color::White : Color(96, 96, 96));
	warnMessage->SetString(canBuy ? "" : "You don't have enough money !");
}

void PurchaseMenu::SetCanBuyItem()
{
	int _playerMoney = Game::GetPlayer()->GetStats()->GetMoney();
	canBuy = (_playerMoney >= item.price);
	cout << to_string(canBuy);
}

void PurchaseMenu::BuyCurrentItem()
{
	// TODO ADD ITEM TO INVENTORY
	Game::GetPlayer()->GetStats()->UpdateMoney(-item.price);
}
