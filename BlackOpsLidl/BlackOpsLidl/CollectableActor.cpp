#include "CollectableActor.h"
#include "Game.h"
#include "Kismet.h"
#include "Player.h"
#include "RecipeIngredient.h"
#include "PlayerInventoryComponent.h"

ItemData CollectableActor::GetItemData()
{
	return data;
}

CollectableActor::CollectableActor(const string& _name, const ShapeData& _data, const float _range,
								   const string& _title, const string& _text, const ItemType& _type) 
								 : Actor(_name, _data)
{
	range = _range;
	data = { _data.path, _title, _text, _type };
}

CollectableActor::CollectableActor(const string& _name, const ShapeData& _data, const float _range, const ItemType& _type) : Actor(_name, _data)
{
	range = _range;
	data = { _data.path, "", "", _type};


}


void CollectableActor::TryToCollect()
{
	if (!player)
		player = Game::GetPlayer();
	
	const Vector2f& _playerPos = player->GetShapePosition();
	if (Distance(GetShapePosition(), _playerPos) <= 100)
	{
		RecipeIngredient* _ingredient = dynamic_cast<RecipeIngredient*>(this);

		if (!_ingredient)
			return;
		
		PlayerInventoryComponent* _inventoryComponent = player->GetComponent<PlayerInventoryComponent>();

		if (!_inventoryComponent)
			return;
		
		_inventoryComponent->AddCraftPart(_ingredient);
		SetToRemove(true);
	}
}


void CollectableActor::Update(const float _deltaTime)
{
	Actor::Update(_deltaTime);

	TryToCollect();
}