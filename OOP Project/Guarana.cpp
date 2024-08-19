#include "Guarana.h"

Guarana::Guarana(World* world) : Plant(world, 'U', 0, 0) {
}

Guarana::Guarana(World* world, int posX, int posY) : Plant(world, 'U', 0, 0, posX, posY) {
}

bool Guarana::CollisionDefender(Organism* attacker) {
	attacker->SetStrength(attacker->GetStrength() + 3);
	string sc{ attacker->GetSymbol() };
	string info = sc + "(" + int_to_str(attacker->GetPosX()) + ", " + int_to_str(attacker->GetPosY()) + ") eats Guarana (" + int_to_str(this->GetPosX()) + ", " + int_to_str(this->GetPosY()) + ") Its strength increases by 3!";
	this->GetWorld()->Information.push_back(info);

	return false;
}
