#include "State.h"
#include "GameObject.h"

State::State()
{
}

State::~State()
{
}

void State::update(sf::Int64 deltaTime)
{
}

void State::setGameObject(GameObject* p_gameObject)
{
	m_gameObject = p_gameObject;
}

GameObject* State::getGameObject()
{
	return m_gameObject;
}


bool State::getFirstTick()
{
	return m_firstTick;
}

void State::setFirstTick(bool p_firstTick)
{
	m_firstTick = p_firstTick;
}
