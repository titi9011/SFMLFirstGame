#pragma once
#include <SFML/Graphics.hpp>

class GameObject;

class State
{
public:
	State();
	~State();

	virtual void update(sf::Int64 deltaTime);
	void setGameObject(GameObject* p_gameObject);
	GameObject* getGameObject();

	bool getFirstTick();
	void setFirstTick(bool p_firstTick);

private:
	GameObject* m_gameObject = nullptr;

	bool m_firstTick = true;
};

