#pragma once
#include "Animal.h"

class Antelope : public Animal {
public:
	Antelope(World* world);
	Antelope(World* world, int posX, int posY);
	void Action(int key) override;
	bool CollisionDefender(Organism* attacker) override;
};