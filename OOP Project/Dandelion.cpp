#include "Dandelion.h"

Dandelion::Dandelion(World* world) : Plant(world, 'D', 0, 0) {
}

Dandelion::Dandelion(World* world, int posX, int posY) : Plant(world, 'D', 0, 0, posX, posY) {
}

void Dandelion::Action(int key) {
	int x = this->GetPosX();
	int y = this->GetPosY();

	if (GetWorld()->GetOrganism(x, y) != NULL && !GetWorld()->GetOrganism(x, y)->GetCollisionR()) {
		this->Collision(GetWorld()->GetOrganism(x, y));
		return;
	}

	Move(x, y);

	for (int i = 1; i <= 3; i++) {
		int spreadChance = rand() % 6;
		if (spreadChance == 1) {
			Organism* organismAtPosition = this->GetWorld()->GetOrganism(x, y);

			if (organismAtPosition == NULL) {
				this->GetWorld()->AddOrganism(this->GetSymbol(), x, y);
				string sx = int_to_str(x);
				string sy = int_to_str(y);
				string si = int_to_str(i);
				string sc{ this->GetSymbol() };
				string info = sc + " has spread and grown at position: ";
				info.append("(" + sx);
				info.append(", " + sy);
				info.append(") [after " + si);
				info.append(" attempt]");
				info.append(")");

				this->GetWorld()->Information.push_back(info);
			}
			return;
		}
	}

	this->SetAge(this->GetAge() + 1);
}
