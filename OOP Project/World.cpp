#pragma once
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <fstream>
#include <sstream>
#include "World.h"
#include "Wolf.h"
#include "Antelope.h"
#include "Turtle.h"
#include "Sheep.h"
#include "Fox.h"
#include "Grass.h"
#include "Dandelion.h"
#include "Guarana.h"
#include "DeadlyNightshade.h"
#include "GiantHogweed.h"
#include "Human.h"

using namespace std;

World::World(int sizeX, int sizeY) {
	this->sizeX = sizeX;
	this->sizeY = sizeY;
	turnNumber = 0;

	Organisms.push_back(new Wolf(this));
	Organisms.push_back(new Wolf(this));
	Organisms.push_back(new Fox(this));
	Organisms.push_back(new Fox(this));
	Organisms.push_back(new Fox(this));
	Organisms.push_back(new Fox(this));
	Organisms.push_back(new Sheep(this));
	Organisms.push_back(new Sheep(this));
	Organisms.push_back(new Sheep(this));
	Organisms.push_back(new Sheep(this));
	Organisms.push_back(new Antelope(this));
	Organisms.push_back(new Antelope(this));
	Organisms.push_back(new Antelope(this));
	Organisms.push_back(new Antelope(this));
	Organisms.push_back(new Turtle(this));
	Organisms.push_back(new Turtle(this));
	Organisms.push_back(new Turtle(this));
	Organisms.push_back(new Turtle(this));
	Organisms.push_back(new Turtle(this));
	Organisms.push_back(new Turtle(this));
	Organisms.push_back(new Turtle(this));
	Organisms.push_back(new Turtle(this));
	Organisms.push_back(new Grass(this));
	Organisms.push_back(new Grass(this));
	Organisms.push_back(new Grass(this));
	Organisms.push_back(new Dandelion(this));
	Organisms.push_back(new Dandelion(this));
	Organisms.push_back(new Guarana(this));
	Organisms.push_back(new Guarana(this));
	Organisms.push_back(new Guarana(this));
	Organisms.push_back(new Guarana(this));
	Organisms.push_back(new Guarana(this));
	Organisms.push_back(new Guarana(this));
	Organisms.push_back(new Guarana(this));
	Organisms.push_back(new DeadlyNightshade(this));
	Organisms.push_back(new DeadlyNightshade(this));
	Organisms.push_back(new DeadlyNightshade(this));
	Organisms.push_back(new DeadlyNightshade(this));
	Organisms.push_back(new GiantHogweed(this));
	Organisms.push_back(new Human(this));
}

World::~World() {
}

int World::GetSizeX() {
	return sizeX;
}

int World::GetSizeY() {
	return sizeY;
}

const int World::GetTurnNumber() {
	return turnNumber;
}

void World::ExecuteTurn(int key) {
	sort(Organisms.begin(), Organisms.end(), [](Organism* l, Organism* r) {
		if (l->GetInitiative() == r->GetInitiative())
			return l->GetAge() > r->GetAge();
		return l->GetInitiative() > r->GetInitiative();
		});

	for (int i = 0; i < Organisms.size(); i++) {
		if (!Organisms[i]->IsDead())
			Organisms[i]->Action(key);
	}

	for (int i = 0; i < NewbornOrganisms.size(); i++) {
		if (!NewbornOrganisms[i]->IsDead())
			Organisms.push_back(NewbornOrganisms[i]);
	}

	vector<int> deadIndices;

	for (int i = 0; i < Organisms.size(); i++) {
		if (Organisms[i]->IsDead())
			deadIndices.push_back(i);
	}

	for (int i = deadIndices.size() - 1; i >= 0; i--) {
		Organisms.erase(Organisms.begin() + deadIndices[i]);
	}

	NewbornOrganisms.clear();

	turnNumber++;
}

void World::Narrator() {
	for (int i = 0; i < Information.size(); i++)
		cout << Information[i] << endl;
	Information.clear();
}

void World::DrawWorld() {
	cout << "Turn: " << turnNumber << endl;
	for (int i = 0; i < sizeY; i++) {
		for (int j = 0; j < sizeX; j++) {
			Organism* organismAtPosition = GetOrganism(j, i);
			if (organismAtPosition == NULL)
				cout << ".";
			else
				organismAtPosition->Draw();
		}
		cout << endl;
	}
	Narrator();
}

Organism* World::GetOrganism(int x, int y, Organism* caller) {
	for (int i = 0; i < Organisms.size(); i++) {
		if (caller != Organisms[i] && !Organisms[i]->IsDead() && Organisms[i]->GetPosX() == x && Organisms[i]->GetPosY() == y) {
			return Organisms[i];
		}
	}

	for (int i = 0; i < NewbornOrganisms.size(); i++) {
		if (caller != NewbornOrganisms[i] && !NewbornOrganisms[i]->IsDead() && NewbornOrganisms[i]->GetPosX() == x && NewbornOrganisms[i]->GetPosY() == y) {
			return NewbornOrganisms[i];
		}
	}
	return NULL;
}

bool World::IsOrganismAt(int x, int y) {
	for (int i = 0; i < Organisms.size(); i++) {
		if (Organisms[i]->GetPosX() == x && Organisms[i]->GetPosY() == y)
			return true;
	}
	return false;
}

void World::RandomFreePosition(int& x, int& y) {
	x = rand() % sizeX;
	y = rand() % sizeY;

	while (GetOrganism(x, y) != NULL) {
		x = rand() % sizeX;
		y = rand() % sizeY;
	}
}

void World::AddOrganism(char symbol, int x, int y) {
	if (symbol == 'W')
		NewbornOrganisms.push_back(new Wolf(this, x, y));
	if (symbol == 'A')
		NewbornOrganisms.push_back(new Antelope(this, x, y));
	if (symbol == 'T')
		NewbornOrganisms.push_back(new Turtle(this, x, y));
	if (symbol == 'S')
		NewbornOrganisms.push_back(new Sheep(this, x, y));
	if (symbol == 'F')
		NewbornOrganisms.push_back(new Fox(this, x, y));
	if (symbol == 'G')
		NewbornOrganisms.push_back(new Grass(this, x, y));
	if (symbol == 'D')
		NewbornOrganisms.push_back(new Dandelion(this, x, y));
	if (symbol == 'U')
		NewbornOrganisms.push_back(new Guarana(this, x, y));
	if (symbol == 'N')
		NewbornOrganisms.push_back(new DeadlyNightshade(this, x, y));
	if (symbol == 'H')
		NewbornOrganisms.push_back(new GiantHogweed(this, x, y));
	if (symbol == '@')
		NewbornOrganisms.push_back(new Human(this, x, y));
}

void World::Save() {
	fstream file("save.txt", ios::out);

	file << sizeX << " " << sizeY << " " << turnNumber << " " << Organisms.size() << endl;

	for (int i = 0; i < Organisms.size(); i++) {
		Organisms[i]->SaveOrganism(file);
	}

	file.close();
}

void World::Load() {
	Organisms.clear();
	NewbornOrganisms.clear();
	fstream file("save.txt", ios::in);
	int organismsSize;
	file >> sizeX >> sizeY >> turnNumber >> organismsSize;

	for (int i = 0; i < organismsSize; i++) {
		char symbol;
		int x, y, age, strength, activationTime;

		file >> symbol >> x >> y >> strength >> age;

		AddOrganism(symbol, x, y);

		if (symbol == '@')
			file >> activationTime;
		else
			activationTime = 0;

		NewbornOrganisms[i]->LoadOrganism(strength, age, activationTime);
	}

	file.close();
}
