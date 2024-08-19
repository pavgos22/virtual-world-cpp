#include <conio.h>
#include <fstream>
#include "Human.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

Human::Human(World* world) : Animal(world, '@', 5, 4) {
	activationTime = 0;
}

Human::Human(World* world, int posX, int posY) : Animal(world, '@', 5, 4, posX, posY) {
	activationTime = 0;
}

void Human::Control(int& newY, int& newX, int key) {
	switch (key) {
	case KEY_UP:
		if (newY > 0) {
			newY--;
			break;
		}
	case KEY_DOWN:
		if (newY < GetWorld()->GetSizeY() - 1) {
			newY++;
			break;
		}
	case KEY_LEFT:
		if (newX > 0) {
			newX--;
			break;
		}
	case KEY_RIGHT:
		if (newX < GetWorld()->GetSizeX() - 1) {
			newX++;
			break;
		}
	case '-':
		if (activationTime == 0 || this->GetAge() - activationTime > 10) {
			cout << "ACTIVATION" << endl;
			activationTime = this->GetAge();
		}
	default:
		cout << endl << "null" << endl;
		break;
	}
}

void Human::Action(int key) {
	this->SetAge(this->GetAge() + 1);
	int newX = this->GetPosX();
	int newY = this->GetPosY();

	Control(newY, newX, key);

	Organism* organismAtPosition = this->GetWorld()->GetOrganism(newX, newY, this);

	if (organismAtPosition == NULL) {
		this->SetPosX(newX);
		this->SetPosY(newY);
	}
	else {
		this->Collision(organismAtPosition);
	}
}

bool Human::CollisionDefender(Organism* attacker) {
	if (activationTime == 0 || this->GetAge() - 5 > activationTime)
		return false;

	int pX = this->GetPosX();
	int pY = this->GetPosY();
	Move(pX, pY);

	if (this->GetWorld()->GetOrganism(pX, pY, this) != NULL)
		return false;

	attacker->SetPosX(pX);
	attacker->SetPosY(pY);
	return true;
}

void Human::SaveOrganism(fstream& file) {
	file << this->GetSymbol() << " " << this->GetPosX() << " " << this->GetPosY() << " " << this->GetStrength() << " " << this->GetAge() << " " << this->activationTime << endl;
}

void Human::LoadOrganism(int strength, int age, int activationTime) {
	this->SetStrength(strength);
	this->SetAge(age);
	this->activationTime = activationTime;
}
