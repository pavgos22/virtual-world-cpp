#pragma once
#include "Animal.h"

class Wolf : public Animal {
public:
	Wolf(World* world);
	Wolf(World* world, int posX, int posY);
};