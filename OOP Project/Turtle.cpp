#include "Turtle.h"

Turtle::Turtle(World* world) : Animal(world, 'T', 2, 1) {
}

Turtle::Turtle(World* world, int posX, int posY) : Animal(world, 'T', 2, 1, posX, posY) {
}

void Turtle::Action(int key) {
	int newX = this->GetPosX();
	int newY = this->GetPosY();

	int moveChance = rand() % 4;
	int direction = rand() % 8;

	if (moveChance == 0) {
		if (direction == 0 && newX < this->GetWorld()->GetSizeX() - 1) {
			newX++;
		}
		if (direction == 1 && newX > 0) {
			newX--;
		}
		if (direction == 2 && newY < GetWorld()->GetSizeY() - 1) {
			newY++;
		}
		if (direction == 3 && newY > 0) {
			newY--;
		}
		if (direction == 4 && newX < GetWorld()->GetSizeX() - 1 && newY < GetWorld()->GetSizeY() - 1) {
			newY++;
			newX++;
		}
		if (direction == 5 && newX > 0 && newY < GetWorld()->GetSizeY() - 1) {
			newY++;
			newX--;
		}
		if (direction == 6 && newX < GetWorld()->GetSizeX() - 1 && newY > 0) {
			newY--;
			newX++;
		}
		if (direction == 7 && newX > 0 && newY > 0) {
			newY--;
			newX--;
		}
	}

	Organism* organismAtPosition = this->GetWorld()->GetOrganism(newX, newY, this);

	if (organismAtPosition == NULL) {
		this->SetPosX(newX);
		this->SetPosY(newY);
	}
	else {
		this->Collision(organismAtPosition);
	}

	this->SetAge(this->GetAge() + 1);
}

bool Turtle::CollisionDefender(Organism* attacker) {
	if (attacker->GetStrength() < 5) {
		string sc{ this->GetSymbol() };
		string sa{ attacker->GetSymbol() };
		string info = sc + " at position: (" + int_to_str(this->GetPosX()) + ", " + int_to_str(this->GetPosY()) + ") defended itself using its shell against: " + sa + " (" + int_to_str(attacker->GetPosX()) + ", " + int_to_str(attacker->GetPosY()) + ")";
		return true;
	}
	return false;
}
