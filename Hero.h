#pragma once
#include "GameObject.h"
#include "CollisionManager.h"


enum HeroState
{
	Idle,
	Run,
	Jump,
	Down
};

class Hero : public GameObject
{
public:
	Hero();
	~Hero();

	void tick(sf::Int64 deltaTime);

	void addGravity(sf::Int64 deltaTime);



};

