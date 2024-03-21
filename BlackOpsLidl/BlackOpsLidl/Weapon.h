#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Bullet.h"

using namespace std;
using namespace sf;

class Weapon 
{
	Sprite* weaponSprite;
	//Texture textureWeapon;
	vector<Bullet*> bullets;

public:
	Weapon();
	Weapon(Vector2f _position);

public:
	void Shoot();

};

