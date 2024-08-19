#pragma once
#include <iostream>
#include <vector>
#include "Organism.h"

class Organism;

using namespace std;

class World {
private:
	vector<Organism*> Organisms;
	vector<Organism*> NewbornOrganisms;
	int sizeY, sizeX;
	bool gameOver;
	int turnNumber;
public:
	vector<string> Information;
	World(int sizeX, int sizeY);
	~World();
	void ExecuteTurn(int key);
	void DrawWorld();
	int GetSizeX();
	int GetSizeY();
	const int GetTurnNumber();
	Organism* GetOrganism(int x, int y, Organism* caller = NULL);
	void RandomFreePosition(int& x, int& y);
	void AddOrganism(char symbol, int x, int y);
	bool IsOrganismAt(int x, int y);
	void Narrator();
	void Save();
	void Load();
};