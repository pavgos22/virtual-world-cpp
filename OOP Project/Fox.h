#pragma once
#include "Animal.h"

class Fox : public Animal {
public:
	Fox(World* world);
	Fox(World* world, int posX, int posY);
	void GoodSense(int& x, int& y);
	void Action(int key) override;
	void Collision(Organism* defender) override;
};