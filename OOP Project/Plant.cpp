#include "Plant.h"

using namespace std;

Plant::Plant(World* world, char symbol, int strength, int initiative) : Organism(world, symbol, strength, initiative) {
	SetCollisionR(true);
}

Plant::Plant(World* world, char symbol, int strength, int initiative, int posX, int posY) : Organism(world, symbol, strength, initiative, posX, posY) {
	SetCollisionR(true);
}

void Plant::Collision(Organism* attacker) {
	int x = this->GetPosX();
	int y = this->GetPosY();

	this->SetIsDead(true);
	string sc{ this->GetSymbol() };
	string sa{ attacker->GetSymbol() };
	string info = sc + " was eaten by " + sa + " (" + int_to_str(attacker->GetPosX()) + ", " + int_to_str(attacker->GetPosY()) + ")";
	this->GetWorld()->Information.push_back(info);
}

void Plant::Spread(int& x, int& y) {
	int sX = x;
	int sY = y;
	Move(x, y);

	int spreadChance = rand() % 10;
	if (spreadChance == 1) {
		Organism* organismAtPosition = this->GetWorld()->GetOrganism(x, y);

		if (organismAtPosition == NULL) {
			this->GetWorld()->AddOrganism(this->GetSymbol(), x, y);
			string sc{ this->GetSymbol() };
			string info = sc + " (" + int_to_str(sX) + ", " + int_to_str(sY) + ") has spread and grown at position: (" + int_to_str(x) + ", " + int_to_str(y) + ")";
			this->GetWorld()->Information.push_back(info);
		}
		return;
	}
}

void Plant::Action(int key) {
	int x = this->GetPosX();
	int y = this->GetPosY();

	Spread(x, y);

	this->SetAge(this->GetAge() + 1);
}
