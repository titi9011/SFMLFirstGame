#pragma once
#include <SFML/Graphics.hpp>
#include "CollisionManager.h"


class Environment
{
public:
	Environment();
	~Environment();

	
	sf::RenderStates& getRenderState();
	void setRenderState(sf::RenderStates& p_renderStates);

	sf::VertexArray& getVertices();
	void setVertices(sf::VertexArray& p_vertices);


private:
	sf::Texture m_floor;
	sf::VertexArray m_vertices;
	sf::RenderStates m_renderStates;
	
};

