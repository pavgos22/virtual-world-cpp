#pragma once
#include "Plant.h"

class Dandelion : public Plant {
public:
	Dandelion(World* world);
	Dandelion(World* world, int posX, int posY);
	void Action(int key) override;
};
