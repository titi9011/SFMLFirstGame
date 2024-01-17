#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include <memory>

class State;

class GameObject
{
public:
	GameObject();
	~GameObject();

	virtual void tick(sf::Int64 deltaTime);
	void addAnimation(std::unique_ptr<Animation> animation);
	sf::Sprite& getCurrentSprite();
	void updateAnimation();
	void setAnimation(int p_animation);
	State* getState();

	void setPosition(float x, float y);
	sf::Vector2f& getPosition();

	void setSpeed(sf::Vector2f p_speed);
	sf::Vector2f& getSpeed();

	void transitionTo(State* p_state);

	bool getIsRight();
	void setIsRight(bool p_isRight);

	bool getIsGrounded();
	void setIsGrounded(bool p_isGrounded);


private:
	State* m_state = nullptr;
	int m_animation = 0;
	std::vector<std::unique_ptr<Animation>> m_vanimation;
	sf::Vector2f m_position = sf::Vector2f(0.f, 0.f);
	sf::Vector2f m_speed = sf::Vector2f(0.f, 0.f);

	bool m_isRight = true;
	bool m_isGrounded = false;

};

