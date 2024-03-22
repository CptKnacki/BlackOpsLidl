#include "Bullet.h"
#include "TextureManager.h"
#include "Macro.h"


Bullet::Bullet(const string& _name, const ShapeData& _data) : Actor(_name, _data, CT_NONE) 
{
	shapeBullet = new Sprite();
	movement = new BulletMovementComponent(this);
	components.push_back(movement);
}

