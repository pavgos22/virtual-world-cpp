#pragma once
#include "Organism.h"

class Plant : public Organism {
public:
	Plant(World* world, char symbol, int strength, int initiative);
	Plant(World* world, char symbol, int strength, int initiative, int posX, int posY);
	void Spread(int& x, int& y);
	void Action(int key) override;
	void Collision(Organism* attacker) override;

protected:
	int oldX, oldY;
};