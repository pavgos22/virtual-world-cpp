#include "Animal.h"

using namespace std;

Animal::Animal(World* world, char symbol, int strength, int initiative) : Organism(world, symbol, strength, initiative) {
	SetCollisionZ(true);
	SetCollisionR(false);
}

Animal::Animal(World* world, char symbol, int strength, int initiative, int posX, int posY) : Organism(world, symbol, strength, initiative, posX, posY) {
	SetCollisionZ(true);
	SetCollisionR(false);
}

void Animal::Action(int key) {
	int newX = this->GetPosX();
	int newY = this->GetPosY();
	oldX = this->GetPosX();
	oldY = this->GetPosY();

	Move(newX, newY);

	Organism* organismOnPosition = this->GetWorld()->GetOrganism(newX, newY, this);

	if (organismOnPosition == NULL) {
		this->SetPosX(newX);
		this->SetPosY(newY);
	}
	else {
		this->Collision(organismOnPosition);
	}

	this->SetAge(this->GetAge() + 1);
}
