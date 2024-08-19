#include "DeadlyNightshade.h"

DeadlyNightshade::DeadlyNightshade(World* world) : Plant(world, 'N', 99, 0) {
}

DeadlyNightshade::DeadlyNightshade(World* world, int posX, int posY) : Plant(world, 'N', 99, 0, posX, posY) {
}

bool DeadlyNightshade::CollisionDefender(Organism* attacker) {
	int x = this->GetPosX();
	int y = this->GetPosY();
	string sc{ this->GetSymbol() };
	string sa{ attacker->GetSymbol() };
	string info = sc + " (" + int_to_str(this->GetPosX()) + ", " + int_to_str(this->GetPosY()) + ") was eaten by " + sa + " (" + int_to_str(attacker->GetPosX()) + ", " + int_to_str(attacker->GetPosY()) + ") \n" + sa + " (" + int_to_str(attacker->GetPosX()) + ", " + int_to_str(attacker->GetPosY()) + ") was poisoned by the deadly nightshade";
	this->GetWorld()->Information.push_back(info);
	this->SetIsDead(true);
	attacker->SetIsDead(true);

	return true;
}
