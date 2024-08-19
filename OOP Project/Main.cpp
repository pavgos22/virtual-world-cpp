#include <iostream>
#include <ctime>
#include <cstdio>
#include <conio.h>
#include "World.h"
#include "Organism.h"
#include "Animal.h"
#include "Plant.h"

using namespace std;

int main() {
	srand(time(NULL));

	int key = 0;
	World world(40, 20);

	while (key != 'q') {
		world.DrawWorld();
		key = _getch();
		if (key == 's' || key == 'S') {
			cout << "SAVED SUCCESSFULLY" << endl;
			world.Save();
		}
		else if (key == 'l' || key == 'L') {
			cout << "LOADED SUCCESSFULLY" << endl;
			world.Load();
		}
		else if (key != 224) {
			system("cls");
			world.ExecuteTurn(key);
		}
	}

	return 0;
}
