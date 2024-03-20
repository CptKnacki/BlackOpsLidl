#include "Bullet.h"

Bullet::Bullet()
{
}

Bullet::Bullet(const Texture* _texture, const float _posX, const float _posY, const float _x, const float _y, const float _movementSpeed)
{
	shapeBullet.setTexture(*_texture);
	shapeBullet.setScale(0.1f, 0.1f);
	shapeBullet.setPosition(_posX, _posY);
	direction.x = _x;
	direction.y = _y;
	movementSpeed = _movementSpeed;
}

Bullet::~Bullet()
{
}

FloatRect Bullet::GetBounds() const
{
	return shapeBullet.getGlobalBounds();
}

void Bullet::Update()
{
	shapeBullet.move(direction * movementSpeed);
}

void Bullet::Render(RenderTarget* _target)
{
	_target->draw(shapeBullet);
}
