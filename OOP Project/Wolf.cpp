#include "Wolf.h"

Wolf::Wolf(World* world) : Animal(world, 'W', 9, 5) {
}

Wolf::Wolf(World* world, int posX, int posY) : Animal(world, 'W', 9, 5, posX, posY) {
}
