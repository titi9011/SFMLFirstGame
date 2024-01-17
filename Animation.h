#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Animation
{
public: 
	Animation(std::string& p_path, int p_nbSprites, int p_lenght, int p_height, float p_frameTime, int p_xOffset, int p_yOffset, int p_stepLenght);
	Animation(const char* p_path, int p_nbSprites, int p_lenght, int p_height, float p_frameTime, int p_xOffset, int p_yOffset, int p_stepLenght);
	~Animation();

	sf::Sprite& getSprite();
	void updateAnimation();
	void nextFrame();

private:
	sf::Sprite m_sprite;
	sf::Texture m_texture;

	int m_nbSprites;
	int m_lenght;
	int m_height;

	int m_xOffset;
	int m_yOffset; 

	int m_stepLenght;

	int m_currentFrame = 0;
	float m_frameTime;

	sf::Clock m_clock;


};

