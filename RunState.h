#pragma once
#include "State.h"


class RunState : public State
{
public:
	RunState();
	~RunState();

	void update(sf::Int64 deltaTime) override;

};

