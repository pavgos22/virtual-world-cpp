#include "Grass.h"

Grass::Grass(World* world) : Plant(world, 'G', 0, 0) {
}

Grass::Grass(World* world, int posX, int posY) : Plant(world, 'G', 0, 0, posX, posY) {
}
