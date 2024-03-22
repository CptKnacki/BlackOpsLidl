#include <SFML/Graphics.hpp>
#include "TextureManager.h"
#include "ActorManager.h"
#include "BulletMovementComponent.h"

using namespace sf;

#define BULLET_PATH "Assets/Textures/Weapons/lazer.png"

class Bullet : public Actor
{
public:
    Sprite* shapeBullet;
    Vector2f currVelocity;
    float maxSpeed;
    BulletMovementComponent* movement = nullptr;


public:

    Bullet(const string& _name, const ShapeData& _data);

};

