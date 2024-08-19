#pragma once
#include <sstream>
#include <iostream>
#include "World.h"

class World;

using namespace std;

class Organism {
private:
	int strength, initiative, posX, posY;
	bool isDead, collisionZ, collisionR;
	char symbol;
	World* world;
	int age;
public:
	Organism(World* world, char symbol, int strength, int initiative);
	Organism(World* world, char symbol, int strength, int initiative, int posX, int posY);
	virtual void Action(int key) = 0;
	virtual void Collision(Organism* defender);
	virtual bool CollisionDefender(Organism* attacker);
	string int_to_str(int n);
	void Kill(Organism* victim);
	void Draw();
	int GetStrength();
	int GetInitiative();
	int GetPosX();
	int GetPosY();
	bool IsDead();
	bool GetCollisionZ();
	bool GetCollisionR();
	void SetStrength(int s);
	void SetInitiative(int i);
	void SetPosX(int pos);
	void SetPosY(int pos);
	void SetIsDead(bool u);
	void SetCollisionZ(bool z);
	void SetCollisionR(bool r);
	void CheckPosition(int& x, int& y);
	void Move(int& x, int& y);
	World* GetWorld();
	char GetSymbol();
	void Reproduce();
	int GetAge();
	void SetAge(int age);
	virtual void SaveOrganism(fstream& file);
	virtual void LoadOrganism(int strength, int age, int activationTime);
};