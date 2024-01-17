#include "CollisionManager.h"

CollisionManager::CollisionManager()
{
}

CollisionManager::~CollisionManager()
{
}

bool CollisionManager::isColliding(GameObject& p_objectA, GameObject& p_objectB)
{
    sf::FloatRect rectA = p_objectA.getCurrentSprite().getGlobalBounds();
    return p_objectB.getCurrentSprite().getGlobalBounds().intersects(rectA);
}

bool CollisionManager::isColliding(GameObject& p_objectA, sf::VertexArray& p_vertexArray)
{
    sf::FloatRect rectA = p_objectA.getCurrentSprite().getGlobalBounds();
    return p_vertexArray.getBounds().intersects(rectA);
}


bool CollisionManager::isOnlyCollidingX(GameObject& p_objectA, GameObject& p_objectB)
{
    if (isColliding(p_objectA, p_objectB))
    {
        float leftA = p_objectA.getCurrentSprite().getGlobalBounds().left;
        float rightA = leftA + p_objectA.getCurrentSprite().getGlobalBounds().width;
        float leftB = p_objectB.getCurrentSprite().getGlobalBounds().left;
        float rightB = leftB + p_objectB.getCurrentSprite().getGlobalBounds().width;

        if (((leftA < rightB) && !(rightA > leftB)) || (!(leftA < rightB) && (rightA > leftB)))
        {
            return true;
        }
    }
    return false;
}


    bool CollisionManager::isOnlyCollidingY(GameObject & p_objectA, GameObject & p_objectB)
    {
        if (isColliding(p_objectA, p_objectB) && !isOnlyCollidingX(p_objectA, p_objectB))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

   