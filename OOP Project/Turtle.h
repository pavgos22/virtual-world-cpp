#pragma once
#include "Animal.h"

class Turtle : public Animal {
public:
	Turtle(World* world);
	Turtle(World* world, int posX, int posY);
	void Action(int key) override;
	bool CollisionDefender(Organism* attacker) override;
};