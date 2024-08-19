#include "GiantHogweed.h"

GiantHogweed::GiantHogweed(World* world) : Plant(world, 'H', 10, 0) {
}

GiantHogweed::GiantHogweed(World* world, int posX, int posY) : Plant(world, 'H', 10, 0, posX, posY) {
}

void GiantHogweed::KillAdjacent(int x, int y) {
	for (int i = x - 1; i <= x + 1; i++) {
		for (int j = y - 1; j <= y + 1; j++) {
			if (this->GetWorld()->GetOrganism(i, j) != NULL && this->GetWorld()->GetOrganism(i, j)->GetCollisionZ()) {
				string sc{ this->GetWorld()->GetOrganism(i, j)->GetSymbol() };
				string ux = int_to_str(this->GetWorld()->GetOrganism(i, j)->GetPosX());
				string uy = int_to_str(this->GetWorld()->GetOrganism(i, j)->GetPosY());
				string info = sc + " (" + ux + ", " + uy + ")" + " stepped on Giant Hogweed: (" + int_to_str(x) + ", " + int_to_str(y) + ") [instant death]";
				this->GetWorld()->Information.push_back(info);
				this->GetWorld()->GetOrganism(i, j)->SetIsDead(true);
			}
		}
	}
}

void GiantHogweed::Action(int key) {
	Plant::Action(key);
	int x = this->GetPosX();
	int y = this->GetPosY();

	KillAdjacent(x, y);
}
