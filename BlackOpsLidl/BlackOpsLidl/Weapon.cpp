#include "Weapon.h"
#include "Weapon.h"
#include "TextureManager.h"
#include "Macro.h"

#include "Game.h"

#define PATH_WEAPON "Assets/Textures/Weapons/weapon1.png"


Weapon::Weapon(const string& _name, const ShapeData& _data) : Actor(_name, _data, CT_BLOCK)
{
	weaponSprite = new Sprite();
	TextureManager::GetInstance().Load(weaponSprite, PATH_WEAPON);
	weaponSprite->setPosition(0, 100);
}

//void Weapon::Shoot()
//{
//    Vector2f weaponPosition = GetPosition();
//
//    Bullet* bullet = new Bullet("Bullet", weaponPosition, ShapeData(Vector2f(0, 0), Vector2f(10, 10), "bullet_texture.png"));
//
//    bullet->Init();
//
//    ActorManager::GetInstance().Add(bullet->GetId(), bullet);
//}
// 

