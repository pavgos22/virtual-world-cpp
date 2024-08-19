#pragma once
#include "Plant.h"

class DeadlyNightshade : public Plant {
public:
	DeadlyNightshade(World* world);
	DeadlyNightshade(World* world, int posX, int posY);
	bool CollisionDefender(Organism* attacker) override;
};