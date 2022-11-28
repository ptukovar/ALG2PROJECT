// PUK0023
#include <iostream>
#include "Tower.h"
#include "Cubes.h"
int main()
{
	Tower tower = Tower();
	tower.loadData("SetOfBlocks1.txt");
	tower.printCubes();
	tower.buildTower();

	tower.loadData("SetOfBlocks2.txt");
	tower.printCubes();
	tower.buildTower();
}