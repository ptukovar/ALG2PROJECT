#pragma once
#include "Cubes.h"
class Tower
{
private:
	int size;
	Cubes* cubes;
public:
	Tower();
	Tower(int size, Cubes* cubes);
	bool loadData(const char* filePath);
	void printCubes();
	void buildTower();
};
