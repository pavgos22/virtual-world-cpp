#include "Organism.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

Organism::Organism(World* world, char symbol, int strength, int initiative) {
	this->world = world;
	this->symbol = symbol;
	this->strength = strength;
	this->initiative = initiative;
	this->world->RandomFreePosition(this->posX, this->posY);
}

Organism::Organism(World* world, char symbol, int strength, int initiative, int posX, int posY) : Organism(world, symbol, strength, initiative) {
	this->posX = posX;
	this->posY = posY;
}

string Organism::int_to_str(int num) {
	stringstream ss;
	ss << num;
	string s;
	ss >> s;
	return s;
}

int Organism::GetStrength() {
	return strength;
}

void Organism::SetStrength(int strength) {
	this->strength = strength;
}

int Organism::GetInitiative() {
	return initiative;
}

void Organism::SetInitiative(int initiative) {
	this->initiative = initiative;
}

void Organism::SetPosX(int pos) {
	posX = pos;
}

void Organism::SetPosY(int pos) {
	posY = pos;
}

bool Organism::IsDead() {
	return isDead;
}

bool Organism::GetCollisionZ() {
	return collisionZ;
}

bool Organism::GetCollisionR() {
	return collisionR;
}

void Organism::SetIsDead(bool isDead) {
	this->isDead = isDead;
}

void Organism::SetCollisionZ(bool collisionZ) {
	this->collisionZ = collisionZ;
}

void Organism::SetCollisionR(bool collisionR) {
	this->collisionR = collisionR;
}

int Organism::GetPosX() {
	return posX;
}

int Organism::GetPosY() {
	return posY;
}

void Organism::Draw() {
	cout << symbol;
}

World* Organism::GetWorld() {
	return world;
}

void Organism::Collision(Organism* defender) {
	if (this->GetSymbol() == defender->GetSymbol()) {
		this->Reproduce();
		return;
	}

	bool stopCollision = defender->CollisionDefender(this);

	if (stopCollision)
		return;

	if (this->GetStrength() >= defender->GetStrength()) {
		this->Kill(defender);
		SetPosX(defender->GetPosX());
		this->SetPosY(defender->GetPosY());

	}
	else {
		defender->Kill(this);
	}
}

char Organism::GetSymbol() {
	return symbol;
}

void Organism::Move(int& newX, int& newY) {
	int direction = rand() % 8;

	if (direction == 0 && newX < this->GetWorld()->GetSizeX() - 1) {
		newX++;
	}
	if (direction == 1 && newX > 0) {
		newX--;
	}
	if (direction == 2 && newY < this->GetWorld()->GetSizeY() - 1) {
		newY++;
	}
	if (direction == 3 && newY > 0) {
		newY--;
	}
	if (direction == 4 && newX < this->GetWorld()->GetSizeX() - 1 && newY < this->GetWorld()->GetSizeY() - 1) {
		newY++;
		newX++;
	}
	if (direction == 5 && newX > 0 && newY < this->GetWorld()->GetSizeY() - 1) {
		newY++;
		newX--;
	}
	if (direction == 6 && newX < this->GetWorld()->GetSizeX() - 1 && newY > 0) {
		newY--;
		newX++;
	}
	if (direction == 7 && newX > 0 && newY > 0) {
		newY--;
		newX--;
	}
}

void Organism::Reproduce() {
	int newX = this->GetPosX();
	int newY = this->GetPosY();

	Move(newX, newY);

	Organism* organismAtPosition = this->GetWorld()->GetOrganism(newX, newY);

	if (organismAtPosition == NULL) {
		string sc{ this->GetSymbol() };
		string info = sc + " (" + int_to_str(this->GetPosX()) + ", " + int_to_str(this->GetPosY()) + ") reproduced and appeared at position: (" + int_to_str(newX) + ", " + int_to_str(newY) + ")";
		GetWorld()->Information.push_back(info);
		this->GetWorld()->AddOrganism(this->GetSymbol(), newX, newY);
	}
}

void Organism::Kill(Organism* victim) {
	string sc{ this->GetSymbol() };
	string so{ victim->GetSymbol() };
	if (!victim->GetCollisionR()) {
		string info = sc + "(" + int_to_str(this->GetPosX()) + ", " + int_to_str(this->GetPosY()) + ") kills " + so + "(" + int_to_str(victim->GetPosX()) + ", " + int_to_str(victim->GetPosY()) + ")";
		GetWorld()->Information.push_back(info);
	}
	else {
		string info = sc + "(" + int_to_str(this->GetPosX()) + ", " + int_to_str(this->GetPosY()) + ") eats " + so + "(" + int_to_str(victim->GetPosX()) + ", " + int_to_str(victim->GetPosY()) + ")";
		GetWorld()->Information.push_back(info);
	}
	victim->SetIsDead(true);
}

bool Organism::CollisionDefender(Organism* attacker) {
	return false;
}

int Organism::GetAge() {
	return age;
}

void Organism::SetAge(int age) {
	this->age = age;
}

void Organism::SaveOrganism(fstream& file) {
	file << this->GetSymbol() << " " << this->GetPosX() << " " << this->GetPosY() << " " << this->GetStrength() << " " << this->GetAge() << endl;
}

void Organism::LoadOrganism(int strength, int age, int activationTime) {
	this->SetStrength(strength);
	this->SetAge(age);
}
