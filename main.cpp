#include <SFML/Graphics.hpp>
#include <filesystem>
#include <iostream>
#include "GameObject.h"
#include "Hero.h"
#include "Environment.h"
#include "SceneObjects.h"


int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Image Example");

    sf::Clock clock;

    SceneObjects sceneObjects = SceneObjects();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        sf::Int64 deltaTime = clock.getElapsedTime().asMicroseconds();
        clock.restart();

        sceneObjects.tick(deltaTime);


        window.clear();
        window.draw(sceneObjects.getHero().getCurrentSprite());
        window.draw(sceneObjects.getEnvironment().getVertices(), sceneObjects.getEnvironment().getRenderState());
        window.display();

    }

    return 0;
}
