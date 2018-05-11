#include "Mouse.h"
#include "Game.h"
#include "PlayArea.h"

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
	body.draw(sign, 13);
}

void Mouse::rebirn(short border)
{
	body = { rand() % (border-2) + 2, rand() % (border - 2) + 2 };
	for (Pixel & pixel : Game::getInstance().getSnake().getBody())
	{
		if (body == pixel)
		{
			rebirn(border);
		}
	}
}

Mouse::~Mouse()
{
}
