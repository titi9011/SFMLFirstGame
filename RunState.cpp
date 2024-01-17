#include "RunState.h"
#include "Hero.h"
#include "GameObject.h"
#include "IdleState.h"
#include <iostream>
#include "JumpState.h"

RunState::RunState() : State()
{
}

RunState::~RunState()
{
}


void RunState::update(sf::Int64 deltaTime)
{
	GameObject* gameObject = getGameObject();
	gameObject->setAnimation(HeroState::Run);


	if (getFirstTick())
	{
		setFirstTick(false);

		if (!gameObject->getIsRight())
		{
			gameObject->getCurrentSprite().setScale(sf::Vector2f(-1.f, 1.f));
		}
		else
		{
			gameObject->getCurrentSprite().setScale(sf::Vector2f(1.f, 1.f));
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		gameObject->transitionTo(new JumpState);
	}
	else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		gameObject->transitionTo(new IdleState);
	}


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if (!gameObject->getIsRight())
		{
			gameObject->getCurrentSprite().setScale(sf::Vector2f(1.f, 1.f));
			gameObject->setIsRight(true);
		}
		gameObject->setPosition(gameObject->getPosition().x + 0.0005f * deltaTime, gameObject->getPosition().y);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (gameObject->getIsRight())
		{
			gameObject->getCurrentSprite().setScale(sf::Vector2f(-1.f, 1.f));
			gameObject->setIsRight(false);
		}
		gameObject->setPosition(gameObject->getPosition().x - 0.0005f * deltaTime, gameObject->getPosition().y);
	}

	gameObject->getCurrentSprite().setPosition(gameObject->getPosition());
}

