#include "Environment.h"
#include <iostream>

Environment::Environment()
{
	m_floor.loadFromFile("assets/PNG/environment/layers/tilesets.png", sf::IntRect(128, 16, 16, 16));
	m_vertices.setPrimitiveType(sf::TrianglesStrip);

    for (int i = 0; i < 800/16; i++)
    {
        m_vertices.append(sf::Vertex(sf::Vector2f(i*16.f, 600.f - 16.f), sf::Vector2f(0.f, 0.f)));
        m_vertices.append(sf::Vertex(sf::Vector2f((i+1.f)*16.f, 600.f - 16.f), sf::Vector2f(16.f, 0.f)));
        m_vertices.append(sf::Vertex(sf::Vector2f(i * 16.f, 600.f), sf::Vector2f(0.f, 16.f)));
        m_vertices.append(sf::Vertex(sf::Vector2f((i+1.f)*16.f, 600.f), sf::Vector2f(16.f, 16.f)));
    }

    //for (int i = 0; i < 600 / 16; i++)
    //{
    //    m_vertices.append(sf::Vertex(sf::Vector2f(800.f-16.f, i*16.f), sf::Vector2f(0.f, 0.f)));
    //    m_vertices.append(sf::Vertex(sf::Vector2f(800.f, i*16.f), sf::Vector2f(16.f, 0.f)));
    //    m_vertices.append(sf::Vertex(sf::Vector2f(800.f - 16.f, (i + 1.f) * 16.f), sf::Vector2f(0.f, 16.f)));
    //    m_vertices.append(sf::Vertex(sf::Vector2f(800.f, (i+1.f)*16.f), sf::Vector2f(16.f, 16.f)));
    //}




    m_renderStates.texture = &m_floor;

}

Environment::~Environment()
{
}

sf::RenderStates& Environment::getRenderState()
{
    return m_renderStates;
}

void Environment::setRenderState(sf::RenderStates& p_renderStates)
{
    m_renderStates = p_renderStates;
}

sf::VertexArray& Environment::getVertices()
{
    return m_vertices;
}

void Environment::setVertices(sf::VertexArray& p_vertices)
{
    m_vertices = p_vertices;
}

