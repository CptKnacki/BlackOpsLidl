#include "Weapon.h"
#include "TextureManager.h"
#include"Macro.h"

#define PATH_WEAPON "Assets/Textures/Weapons/weapon1.png"

Weapon::Weapon()
{



}

Weapon::Weapon(Vector2f _position) 
{
	weaponSprite = new Sprite();
	//textureWeapon.loadFromFile(PATH_WEAPON);
	//weaponSprite->setTexture(textureWeapon);
	TextureManager::GetInstance().Load(weaponSprite, PATH_WEAPON);
	weaponSprite->setPosition(0, 0);
}

void Weapon::Shoot()
{
	new Bullet(weaponSprite->getPosition(), {100, 100}, 1);
}
 