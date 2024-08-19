#pragma once
#include "Animal.h"

class Sheep : public Animal {
public:
	Sheep(World* world);
	Sheep(World* world, int posX, int posY);
};