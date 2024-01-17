#include "IdleState.h"
#include "Hero.h"
#include "GameObject.h"
#include "RunState.h"
#include <iostream>
#include <cmath>
#include "JumpState.h"

IdleState::IdleState() : State()
{
}

IdleState::~IdleState()
{
}

void IdleState::update(sf::Int64 deltaTime)
{
	GameObject* gameObject = getGameObject();
	gameObject->setAnimation(HeroState::Idle);

	if (getFirstTick())
	{
		if (!gameObject->getIsRight())
		{
			gameObject->getCurrentSprite().setScale(sf::Vector2f(-1.f, 1.f));
		}
		else
		{
			gameObject->getCurrentSprite().setScale(sf::Vector2f(1.f, 1.f));
		}
		setFirstTick(false);
	}


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		gameObject->transitionTo(new JumpState);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		gameObject->transitionTo(new RunState);
	}



	gameObject->getCurrentSprite().setPosition(gameObject->getPosition());
}
