# Virtual World Simulator in C++

## Project Overview

The goal of this project was to create a virtual world simulator using a grid structure with a fixed size of 20x20 displayed in console. In this world, simple life forms with different behaviors occupy individual cells on the grid. Each cell can contain at most one organism, and in case of a collision, one of the organisms is either removed or moved.

The simulator is turn-based. In each turn, all organisms in the world perform actions according to their type. Some organisms, like animals, move, while others, like plants, remain stationary. When two organisms end up on the same cell, a collision occurs, and one of them wins by either killing or repelling the other. The order in which organisms move during a turn depends on their initiative, with animals with higher initiative moving first. In cases where organisms have the same initiative, the older one moves first.

Victory in a collision primarily depends on the organism's strength, with some exceptions specified in the tables. When two organisms have equal strength, the one that attacks first wins.

A specific type of animal is the Human, which, unlike other animals, does not move randomly. The direction of its movement is determined by the player using the arrow keys on the keyboard.

When the program is started, several instances of each type of animal and plant appear on the grid. The application interface includes a text area where information about the results of battles, plant consumption, and other events occurring in the world is displayed.

## Class Implementation

### World Class

The `World` class manages gameplay and organisms. It includes methods such as `executeTurn()` and `drawWorld()`, as well as a field `organisms` that stores all the organisms present in the world.

### Organism Class

The `Organism` class is an abstract class from which two more abstract classes, `Plant` and `Animal`, are derived. The `Organism` class defines basic fields such as strength, initiative, position `(x, y)`, and a reference to the world in which it is located. It also includes methods such as `action()`, which determines the behavior of the organism during a turn, `collision()`, which defines the organism's behavior during contact with another organism, and `draw()`, which draws a symbolic representation of the organism.

### Animal Class

The `Animal` class implements behaviors common to most animals, such as basic movement, which in the `action()` method moves the animal to a randomly selected adjacent cell, and reproduction, which occurs in the `collision()` method when encountering an organism of the same species.

### Human Class

The `Human` class extends the `Animal` class and is controlled by the player. The Human does not reproduce and has a unique ability that the player can activate.

## Specific Behaviors of Organisms

Animals and plants have different specific `action()` and `collision()` methods that determine their behavior in the world:

- **Wolf [W]** (strength: 9, initiative: 5) and **Sheep [S]** (strength: 4, initiative: 4) have no special abilities in either the `action()` or `collision()` methods.
- **Fox [F]** (strength: 3, initiative: 7) has a keen sense of smell and never moves to a cell occupied by an organism stronger than itself.
- **Turtle [T]** (strength: 2, initiative: 1) in 75% of cases does not change its position and repels attacks from animals with strength less than 5.
- **Antelope [A]** (strength: 4, initiative: 4) has a movement range of two cells and a 50% chance to escape before a fight, moving to an unoccupied adjacent cell.

All plants have zero initiative and various effects related to being eaten:

- **Grass [G]** (strength: 0) and **Dandelion [D]** (strength: 0) can spread to adjacent cells, with Dandelion attempting to spread three times in one turn.
- **Guarana [U]** (strength: 0) increases the strength of the animal that eats it by 3.
- **Deadly Nightshade [N]** (strength: 99) kills the animal that eats it.
- **Giant Hogweed [H]** (strength: 10) kills all animals in its vicinity.

## Saving and Loading Game State

The virtual world simulator allows saving and loading the game state to/from a file. The player can save the current game state at any time by pressing the `S` key. The saved game state includes the positions of all organisms, their age, strength, and other relevant parameters. The player can also load a previously saved game state by pressing the `L` key, allowing them to continue the game from the point of the last save.

## Controls

The player controls the Human character in the game using the arrow keys on the keyboard:

- **Arrow Keys** - Move the Human in the specified direction (up, down, left, right).
- **S** - Save the current game state.
- **L** - Load the game state from a file.
- **Q** - Exit program
- **Any other key** - Proceed to the next turn without moving the Human.

## Summary

The C++ project includes a simulation of a virtual world where animals and plants interact according to the implemented rules. The game was designed using object-oriented programming principles, with a focus on polymorphism and inheritance. The virtual world is visualized in the console, and the player can interact with the simulation by controlling the Human character using the keyboard. Additionally, the program offers the ability to save and load the game state, enhancing its functionality and allowing the player to pause and resume the game at any point.
