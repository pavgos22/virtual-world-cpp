#pragma once
#include "Plant.h"

class Guarana : public Plant {
public:
	Guarana(World* world);
	Guarana(World* world, int posX, int posY);
	bool CollisionDefender(Organism* attacker) override;
};