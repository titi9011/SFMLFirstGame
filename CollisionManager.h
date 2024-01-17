#pragma once
#include "GameObject.h"

class CollisionManager
{
public:
	CollisionManager();
	~CollisionManager();

	bool isColliding(GameObject& p_objectA, GameObject& p_objectB);
	bool isColliding(GameObject& p_objectA, sf::VertexArray& p_vertexArray);

	bool isOnlyCollidingX(GameObject& p_objectA, GameObject& p_objectB);

	bool isOnlyCollidingY(GameObject& p_objectA, GameObject& p_objectB);
};

