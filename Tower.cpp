#include "Tower.h"
#include <iostream>
/// @brief Defaultni konstruktor veze
Tower::Tower()
{
	this->size = 0;
	this->cubes = nullptr;
}
/// @brief Konstruktor veze
/// @param size Pocet kostek
/// @param cubes Pole s kostkami
Tower::Tower(int size, Cubes* cubes)
{
	this->size = size;
	this->cubes = cubes;
}
/// @brief Nacteni pocku a nasledne rozmery kostek
/// @param inputPath Cesta k souboru s daty
/// @return Spravnost otevreni souboru
bool Tower::loadData(const char* inputPath)
{
	FILE* f;
	int h = 0;
	int w = 0;
	int l = 0;
	errno_t err = fopen_s(&f, inputPath, "rt");
	if (~err == 0){
		std::cout << "File not found" << std::endl;
		fclose(f);
		return false;
	}
	fscanf_s(f, "%d", &this->size);
	this->cubes = new Cubes[size];
	for (int i = 0; i < this->size; i++){
		fscanf_s(f, "%d %d %d", &h, &w, &l);
		Cubes temp = Cubes(h, w, l);
		this->cubes[i] = temp;
	}
	fclose(f);
	return true;
}
/// @brief Vypis rozmeru kostek
void Tower::printCubes()
{
	for (size_t i = 0; i < this->size; i++){
		std::cout
			<< this->cubes[i].getHeight() << " "
			<< this->cubes[i].getWidth() << " "
			<< this->cubes[i].getLength()
			<< std::endl;
	}
}
/// @brief Porovnani rozmeru zakladen
/// @param a Kostka A
/// @param b Kostka B
/// @return Zakladna
int compareBase(const void* a, const void* b)
{
	return ((*(Cubes*)b).getLength() * (*(Cubes*)b).getWidth()) - ((*(Cubes*)a).getLength() * (*(Cubes*)a).getWidth());
}
/// @brief Vypocitani veze
void Tower::buildTower() {
	Tower tempTower = Tower(this->size * 3, new Cubes[this->size * 3]);
	int index = 0;
	int rotSize = this->size * 3;
	for (int i = 0; i < this->size; i++){
		tempTower.cubes[index].setHeight(this->cubes[i].getHeight());
		tempTower.cubes[index].setLength(std::max(this->cubes[i].getLength(), this->cubes[i].getWidth()));
		tempTower.cubes[index].setWidth(std::min(this->cubes[i].getLength(), this->cubes[i].getWidth()));
		index++;

		// Prvni rotace
		tempTower.cubes[index].setHeight(this->cubes[i].getWidth());
		tempTower.cubes[index].setLength(std::max(this->cubes[i].getHeight(), this->cubes[i].getLength()));
		tempTower.cubes[index].setWidth(std::min(this->cubes[i].getHeight(), this->cubes[i].getLength()));
		index++;

		// Druha rotace
		tempTower.cubes[index].setHeight(this->cubes[i].getLength());
		tempTower.cubes[index].setLength(std::max(this->cubes[i].getHeight(), this->cubes[i].getWidth()));
		tempTower.cubes[index].setWidth(std::min(this->cubes[i].getHeight(), this->cubes[i].getWidth()));
		index++;
	}

	// Serazeni podle zakladny
	qsort(tempTower.cubes, rotSize, sizeof(tempTower.cubes[0]), compareBase);

	// Vypis rotace

	std::cout << std::endl;
	for (int i = 0; i < rotSize; i++) {
		std::cout << tempTower.cubes[i].getHeight() << ":" << tempTower.cubes[i].getWidth() << ":" << tempTower.cubes[i].getLength() << std::endl;
	}

	// Prizazeni hodnot vysky
	int* meshes = new int[rotSize];
	for (int i = 0; i < rotSize; i++) {
		meshes[i] = tempTower.cubes[i].getHeight();
	}

	// Sestaveni kostek na sebe
	for (int i = 1; i < rotSize; i++) {
		for (int j = 0; j < i; j++) {
			if (tempTower.cubes[i].getWidth() < tempTower.cubes[j].getWidth() && tempTower.cubes[i].getLength() < tempTower.cubes[j].getLength() && meshes[i] < meshes[j] + tempTower.cubes[i].getHeight())
			{
				meshes[i] = meshes[j] + tempTower.cubes[i].getHeight();
			}
		}
	}

	// Vyhledani nejvyssi veze
	int max = -1;
	for (int i = 0; i < rotSize; i++) {
		if (max < meshes[i]) {
			max = meshes[i];
		}
	}
	std::cout << std::endl << "Size of the biggest tower: " << max << std::endl << std::endl;
}