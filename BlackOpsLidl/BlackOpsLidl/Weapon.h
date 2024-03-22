#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Bullet.h"
#include "ActorManager.h"

using namespace std;
using namespace sf;

class Weapon : public Actor
{
	Sprite* weaponSprite;
	//Texture textureWeapon;
	vector<Bullet*> bullets;

public:
	Weapon(const string& _name, const ShapeData& _data);


};

