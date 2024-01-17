#pragma once
#include "State.h"

class GameObject;

class IdleState : public State
{
public:
	IdleState();
	~IdleState();

	void update(sf::Int64 deltaTime) override;

};
