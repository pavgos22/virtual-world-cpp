#pragma once
#include "Animal.h"

class Human : public Animal {
public:
	Human(World* world);
	Human(World* world, int posX, int posY);
	void Control(int& newY, int& newX, int key);
	void Action(int key) override;
	bool CollisionDefender(Organism* attacker) override;
	void SaveOrganism(fstream& file) override;
	void LoadOrganism(int strength, int age, int activationTime) override;
private:
	int activationTime;
};