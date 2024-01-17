#pragma once
#include "Hero.h"
#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include "IdleState.h"
#include "Environment.h"

Hero::Hero() : GameObject()
{
	auto idleState = std::make_unique<Animation>("assets/PNG/spritesheets/player/player-idle.png", 4, 40, 44, 0.2f, 20, 20, 80);
	auto runState = std::make_unique<Animation>("assets/PNG/spritesheets/player/player-run.png", 10, 40, 44, 0.08f, 20, 20, 80);
	auto jumpState = std::make_unique<Animation>("assets/PNG/spritesheets/player/player-jump.png", 6, 40, 44, 0.1f, 20, 20, 80);
	auto downState = std::make_unique<Animation>("assets/PNG/spritesheets/player/player-duck.png", 1, 40, 44, 1.f, 20, 20, 80);

	addAnimation(std::move(idleState));
	addAnimation(std::move(runState));
	addAnimation(std::move(jumpState));
	addAnimation(std::move(downState));


	transitionTo(new IdleState);


	

}

Hero::~Hero()
{

}

void Hero::tick(sf::Int64 deltaTime)
{
	getCurrentSprite().setOrigin(20, 22);
	addGravity(deltaTime);
	getState()->update(deltaTime);
	updateAnimation();

}

void Hero::addGravity(sf::Int64 deltaTime)
{
	float gravity = 0.000000001f;
	float newYSpeed = getSpeed().y + gravity*deltaTime;
	setSpeed(sf::Vector2f(getSpeed().x, newYSpeed));
	setPosition(getPosition().x, getPosition().y + getSpeed().y * deltaTime);

}