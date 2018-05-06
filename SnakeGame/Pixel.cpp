#include "Pixel.h"

short Pixel::getX()
{
	return x;
}

void Pixel::setX(short x)
{
	this->x = x;
}

short Pixel::getY()
{
	return y;
}

void Pixel::setY(short y)
{
	this->y = y;
}

Pixel::Pixel(short x, short y)
{
	this->x = x;
	this->y = y;
}

void Pixel::draw(const char & sign, int color)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);

	gotoXY(x, y);
	std::cout << sign;
}

Pixel::Pixel()
{
}


Pixel::~Pixel()
{
}

bool Pixel::operator==(const Pixel & pixel) const
{
	return x == pixel.x && y == pixel.y;
}

void Pixel::gotoXY(short x, short y)
{
	COORD position = { x, y };
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle, position);
}
