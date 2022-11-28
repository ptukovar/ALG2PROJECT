#include "Cubes.h"
/// @brief Defaultni konstruktor
Cubes::Cubes()
{
	this->h = 0;
	this->w = 0;
	this->l = 0;
}
/// @brief Konstruktor
/// @param h Vyska
/// @param w Sirka
/// @param l Delka
Cubes::Cubes(int h, int w, int l)
{
	this->h = h;
	this->w = w;
	this->l = l;
}
/// @brief Ziskani vysky
/// @return Vyska
int Cubes::getHeight()
{
	return this->h;
}
/// @brief Ziskani sirky
/// @return Sirka
int Cubes::getWidth()
{
	return this->w;
}
/// @brief Ziskani delky
/// @return Delka
int Cubes::getLength()
{
	return this->l;
}
/// @brief Nastaveni vysky
/// @param h hodnota vysky
void Cubes::setHeight(int h)
{
	this->h = h;
}
/// @brief Nastaveni sirky
/// @param w hodnota sirky
void Cubes::setWidth(int w)
{
	this->w = w;
}
/// @brief Nastaveni delky
/// @param l hodnota delky
void Cubes::setLength(int l)
{
	this->l = l;
}