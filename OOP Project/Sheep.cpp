#include "Sheep.h"

Sheep::Sheep(World* world) : Animal(world, 'S', 4, 4) {
}

Sheep::Sheep(World* world, int posX, int posY) : Animal(world, 'S', 4, 4, posX, posY) {
}
