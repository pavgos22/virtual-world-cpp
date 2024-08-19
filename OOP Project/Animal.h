#pragma once
#include "Organism.h"

class Animal : public Organism {
public:
	Animal(World* world, char symbol, int strength, int initiative);
	Animal(World* world, char symbol, int strength, int initiative, int posX, int posY);
	void Action(int key) override;
protected:
	int oldX, oldY;
};