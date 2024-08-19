#pragma once
#include "Plant.h"

class GiantHogweed : public Plant {
public:
	GiantHogweed(World* world);
	GiantHogweed(World* world, int posX, int posY);
	void KillAdjacent(int x, int y);
	void Action(int key) override;
};