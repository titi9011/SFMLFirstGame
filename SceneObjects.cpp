#include "SceneObjects.h"
#include <iostream>

SceneObjects::SceneObjects() : m_hero(), m_environment(), CollisionManager()
{

}

SceneObjects::~SceneObjects()
{
}

void SceneObjects::tick(sf::Int64 deltaTime)
{
	m_hero.tick(deltaTime);
	heroCollision(deltaTime);
}

void SceneObjects::heroCollision(sf::Int64 deltaTime)
{
    if (isColliding(m_hero, m_environment.getVertices()))
	{
		m_hero.setPosition(m_hero.getPosition().x, m_hero.getPosition().y - m_hero.getSpeed().y * deltaTime);
		m_hero.setSpeed(sf::Vector2f(m_hero.getSpeed().x, 0.f));
		m_hero.setIsGrounded(true);
	}
	else
	{
		m_hero.setIsGrounded(false);
	}
}

Environment& SceneObjects::getEnvironment()
{
    return m_environment;
}

Hero& SceneObjects::getHero()
{
    return m_hero;
}
