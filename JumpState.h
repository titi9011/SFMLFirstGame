#pragma once
#include "State.h"


class JumpState : public State
{
public:
	JumpState();
	~JumpState();

	void update(sf::Int64 deltaTime) override;
};

