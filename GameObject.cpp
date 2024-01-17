#include "GameObject.h"
#include "State.h"

GameObject::GameObject()
{
}


GameObject::~GameObject()
{
}

void GameObject::tick(sf::Int64 deltaTime)
{
}

void GameObject::addAnimation(std::unique_ptr<Animation> animation)
{
	m_vanimation.push_back(std::move(animation));
}


sf::Sprite& GameObject::getCurrentSprite()
{
	return m_vanimation[m_animation]->getSprite();
}

void GameObject::updateAnimation()
{
	m_vanimation[m_animation]->updateAnimation();
}

void GameObject::setAnimation(int p_animation)
{
	m_animation = p_animation;
}

State* GameObject::getState()
{
	return m_state;
}

void GameObject::setPosition(float x, float y)
{
	m_position.x = x;
	m_position.y = y;
}

sf::Vector2f& GameObject::getPosition()
{
	return m_position;
}

void GameObject::setSpeed(sf::Vector2f p_speed)
{
	m_speed = p_speed;
}


sf::Vector2f& GameObject::getSpeed()
{
	return m_speed;
}

void GameObject::transitionTo(State* p_state)
{
	if (m_state)
	{
		delete m_state;
	}
	m_state = p_state;
	m_state->setGameObject(this);
}

bool GameObject::getIsRight()
{
	return m_isRight;
}

void GameObject::setIsRight(bool p_isRight)
{
	m_isRight = p_isRight;
}

bool GameObject::getIsGrounded()
{
	return m_isGrounded;
}

void GameObject::setIsGrounded(bool p_isGrounded)
{
	m_isGrounded = p_isGrounded;
}