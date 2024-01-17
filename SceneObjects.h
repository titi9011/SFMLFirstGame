#pragma once

#include "Hero.h"
#include "CollisionManager.h"
#include "Environment.h"



class SceneObjects : public CollisionManager
{
public:
	SceneObjects();
	~SceneObjects();

	void tick(sf::Int64 deltaTime);

	void heroCollision(sf::Int64 deltaTime);

	Environment& getEnvironment();
	Hero& getHero();

private:
	Environment m_environment;
	Hero m_hero;
};

