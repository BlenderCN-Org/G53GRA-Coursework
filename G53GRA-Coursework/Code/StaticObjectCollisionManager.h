#pragma once
#include <vector>
#include "Objects/CollisionCube.h"


class StaticObjectCollisionManager
{
public:
	static void StaticObjectCollisionManager::AddCollisionCube(std::vector<float> minPos, std::vector<float> maxPos);
	static void RestrainMovement(float currentPos[], float direction[], float size[]);
private:
	static std::vector<CollisionCube*> _collisionCubes;
};

