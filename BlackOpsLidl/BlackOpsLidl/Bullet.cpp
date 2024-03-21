#include "Bullet.h"
#include "TextureManager.h"
#include "Macro.h"

#define PATH_BULLET "Assets/Textures/Animations/lazer.png"


Bullet::Bullet(Vector2f _positionSpawn, Vector2f _directionToShoot, const float _movementSpeed) 
{
	shapeBullet = new Sprite();
	shapeBullet->setScale(0.1f, 0.1f);
	shapeBullet->setPosition(_positionSpawn);
	direction = _directionToShoot;
	movementSpeed = _movementSpeed;
	TextureManager::GetInstance().Load(shapeBullet, PATH_BULLET);
}


Bullet::~Bullet()
{
}

FloatRect Bullet::GetBounds() const
{
	return shapeBullet->getGlobalBounds();
}

void Bullet::Update()
{
	shapeBullet->move(direction * movementSpeed);
}

void Bullet::Render(RenderTarget* _target)
{
	_target->draw(*shapeBullet);
}
