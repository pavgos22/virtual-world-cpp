#pragma once
#include "Plant.h"

class Grass : public Plant {
public:
	Grass(World* world);
	Grass(World* world, int posX, int posY);
};