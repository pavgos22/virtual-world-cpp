#include "Fox.h"

Fox::Fox(World* world) : Animal(world, 'F', 3, 7) {
}

Fox::Fox(World* world, int posX, int posY) : Animal(world, 'F', 3, 7, posX, posY) {
}

void Fox::GoodSense(int& newX, int& newY) {
	int direction = rand() % 8;

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

void Fox::Collision(Organism* defender) {
	if (this->GetSymbol() == defender->GetSymbol()) {
		this->Reproduce();
		return;
	}

	if (this->GetStrength() >= defender->GetStrength()) {
		this->Kill(defender);
		this->SetPosX(defender->GetPosX());
		this->SetPosY(defender->GetPosY());
	}
	else {
		string sc{ this->GetSymbol() };
		string sa{ defender->GetSymbol() };
		string info = sc + " at position (" + int_to_str(this->GetPosX()) + ", " + int_to_str(this->GetPosY()) + ") uses Good Sense and avoids: " + sa + " (" + int_to_str(defender->GetPosX()) + ", " + int_to_str(defender->GetPosY()) + ")";
		cout << this->GetSymbol() << " at position (" << this->GetPosX() << ", " << this->GetPosY() << ") uses Good Sense and avoids: " << defender->GetSymbol() << " (" << defender->GetPosX() << ", " << defender->GetPosY() << ")" << endl;
	}
}

void Fox::Action(int key) {
	int newX = this->GetPosX();
	int newY = this->GetPosY();
	oldX = this->GetPosX();
	oldY = this->GetPosY();

	GoodSense(newX, newY);

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
