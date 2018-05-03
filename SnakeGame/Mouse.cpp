#include "Mouse.h"
#include "Game.h"

Mouse::Mouse()
{
	sign = '@';
	body = { 3, 3 };
}

Pixel Mouse::getBody()
{
	return body;
}

void Mouse::draw()
{
	body.draw(sign);
}

void Mouse::rebirn()
{
	body = { rand() % 23 + 2, rand() % 23 + 2 };
	for (Pixel & pixel : Game::getInstance().getSnake().getBody())
	{
		if (body == pixel)
		{
			rebirn();
		}
	}
}


Mouse::~Mouse()
{
}
