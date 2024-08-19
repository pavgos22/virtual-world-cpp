#include "Antelope.h"

Antelope::Antelope(World* world) : Animal(world, 'A', 4, 4) {
}

Antelope::Antelope(World* world, int posX, int posY) : Animal(world, 'A', 4, 4, posX, posY) {
}

void Antelope::Action(int key) {
	int newX = this->GetPosX();
	int newY = this->GetPosY();

	int direction = rand() % 8;

	if (direction == 0 && newX < this->GetWorld()->GetSizeX() - 2) {
		newX += 2;
	}
	if (direction == 1 && newX > 1) {
		newX -= 2;
	}
	if (direction == 2 && newY < GetWorld()->GetSizeY() - 2) {
		newY += 2;
	}
	if (direction == 3 && newY > 1) {
		newY -= 2;
	}
	if (direction == 4 && newX < GetWorld()->GetSizeX() - 2 && newY < GetWorld()->GetSizeY() - 2) {
		newY += 2;
		newX += 2;
	}
	if (direction == 5 && newX > 1 && newY < GetWorld()->GetSizeY() - 2) {
		newY += 2;
		newX -= 2;
	}
	if (direction == 6 && newX < GetWorld()->GetSizeX() - 2 && newY > 1) {
		newY -= 2;
		newX += 2;
	}
	if (direction == 7 && newX > 1 && newY > 1) {
		newY -= 2;
		newX -= 2;
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

bool Antelope::CollisionDefender(Organism* attacker) {
	int chance = rand() % 2;
	int pX = this->GetPosX();
	int pY = this->GetPosY();
	string sc{ this->GetSymbol() };
	string sa{ attacker->GetSymbol() };
	Move(pX, pY);
	if (chance == 0 && GetWorld()->GetOrganism(pX, pY) == NULL) {
		string info = sc + " at position: (" + int_to_str(this->GetPosX()) + ", " + int_to_str(this->GetPosY()) + ") escaped from: " + sa + " (" + int_to_str(attacker->GetPosX()) + ", " + int_to_str(attacker->GetPosY()) + ")";
		attacker->SetPosX(this->GetPosX());
		attacker->SetPosY(this->GetPosY());
		this->SetPosX(pX);
		this->SetPosY(pY);
		info += " and escaped to (" + int_to_str(pX) + ", " + int_to_str(pY) + ")";
		this->GetWorld()->Information.push_back(info);

		return true;
	}
	else if (chance == 0 && GetWorld()->GetOrganism(pX, pY) != NULL) {
		string info = sc + " at position: (" + int_to_str(this->GetPosX()) + ", " + int_to_str(this->GetPosY()) + ") attempted to escape, but failed (position was occupied)";
		this->GetWorld()->Information.push_back(info);
	}
	else if (chance != 0) {
		string info = sc + " at position: (" + int_to_str(this->GetPosX()) + ", " + int_to_str(this->GetPosY()) + ") did not attempt to escape";
		this->GetWorld()->Information.push_back(info);
	}
	return false;
}
