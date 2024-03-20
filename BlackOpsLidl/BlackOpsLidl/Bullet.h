#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class Bullet
{
	Sprite shapeBullet;

	Vector2f direction;
	float movementSpeed;


public:
	Bullet();
	Bullet(const Texture* _texture, const float _posX, const float _posY, float _x, const float _y, const float _movementSpeed);
	~Bullet();

public:
	FloatRect GetBounds() const;
	void Update();
	void Render(RenderTarget* _target);
};


