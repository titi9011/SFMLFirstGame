#include "Animation.h"

Animation::Animation(std::string& p_path, int p_nbSprites, int p_lenght, int p_height, float p_frameTime, int p_xOffset, int p_yOffset, int p_stepLenght)
	: m_nbSprites(p_nbSprites), m_lenght(p_lenght), m_height(p_height), m_frameTime(p_frameTime), m_xOffset(p_xOffset), m_yOffset(p_yOffset), m_stepLenght(p_stepLenght)
{
	m_texture.loadFromFile(p_path);
	m_sprite.setTexture(m_texture);
	m_sprite.setTextureRect(sf::IntRect(m_currentFrame * m_stepLenght + m_xOffset, m_yOffset, m_lenght, m_height));
	m_clock.restart();
}

Animation::Animation(const char* p_path, int p_nbSprites, int p_lenght, int p_height, float p_frameTime, int p_xOffset, int p_yOffset, int p_stepLenght)
	: m_nbSprites(p_nbSprites), m_lenght(p_lenght), m_height(p_height), m_frameTime(p_frameTime), m_xOffset(p_xOffset), m_yOffset(p_yOffset), m_stepLenght(p_stepLenght)
{
	const std::string path = p_path;
	m_texture.loadFromFile(path);
	m_sprite.setTexture(m_texture);
	m_sprite.setTextureRect(sf::IntRect(m_currentFrame * m_stepLenght + m_xOffset, m_yOffset, m_lenght, m_height));
	m_clock.restart();
}

Animation::~Animation()
{
}


sf::Sprite& Animation::getSprite()
{
	return m_sprite;
}

void Animation::updateAnimation()
{
	if (m_clock.getElapsedTime().asSeconds() > m_frameTime)
	{
		nextFrame();
		m_clock.restart();
	}
}

void Animation::nextFrame()
{
	m_sprite.setTextureRect(sf::IntRect(m_currentFrame * m_stepLenght + m_xOffset, m_yOffset, m_lenght, m_height));

	m_currentFrame++;

	if (m_currentFrame >= m_nbSprites)
	{
		m_currentFrame = 0;
	}
}



