#include "JumpState.h"
#include "GameObject.h"
#include "Hero.h"
#include "IdleState.h"
#include <iostream>
#include "RunState.h"

JumpState::JumpState()
{
}

JumpState::~JumpState()
{
}

void JumpState::update(sf::Int64 deltaTime)
{
	GameObject* gameObject = getGameObject();
	gameObject->setAnimation(HeroState::Jump);

	if (getFirstTick())
	{
		gameObject->setSpeed(sf::Vector2f(gameObject->getSpeed().x, gameObject->getSpeed().y - 0.0005f));
		gameObject->setPosition(gameObject->getPosition().x, gameObject->getPosition().y + gameObject->getSpeed().y * deltaTime);
		gameObject->setIsGrounded(false);
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
	
	if (gameObject->getIsGrounded())
	{
		if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			gameObject->transitionTo(new IdleState);
		}
		else
		{
			gameObject->transitionTo(new RunState);
		}
	}


	gameObject->getCurrentSprite().setPosition(gameObject->getPosition());
}
