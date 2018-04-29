#pragma once
#include <windows.h>
#include <conio.h>
#include <iostream>
class Pixel
{
private:
	short x, y;
public:
	short getX();
	void setX(short);
	short getY();
	void setY(short);
	Pixel(short, short);
	void draw(const char & sign);
	Pixel();
	~Pixel();
	bool operator ==(const Pixel &) const;
	static void gotoXY(short x, short y);
};

