#pragma once
class Cubes
{
private:
	int h;
	int w;
	int l;
public:
	Cubes();
	Cubes(int h, int w, int l);
	int getHeight();
	int getWidth();
	int getLength();
	void setHeight(int h);
	void setWidth(int w);
	void setLength(int l);
};
