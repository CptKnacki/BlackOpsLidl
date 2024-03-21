#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Actor.h"


using namespace std;
using namespace sf;

class Bullet 
{
	Sprite *shapeBullet;
	Vector2f direction;
	float movementSpeed;


public:
	Bullet(Vector2f _positionSpawn, Vector2f _directionToShoot, const float _movementSpeed);

	~Bullet();

public:
	FloatRect GetBounds() const;
	void Update();
	void Render(RenderTarget* _target);
};


