#include "Snake.h"

Snake::Snake()
{
	sign = '*';
	body.push_back(Pixel(5, 5));
	body.push_back(Pixel(5, 6));
	direction = Default;
}

std::vector<Pixel> Snake::getBody()
{
	return body;
}

void Snake::draw()
{
	for (Pixel pixel : body) {
		pixel.draw(sign);
	}
}

void Snake::move()
{
	int x = 0, y = 0;
	switch (direction) {
	case Up:
		y = -1;
		break;
	case Down:
		y = 1;
		break;
	case Left:
		x = -1;
		break;
	case Right:
		x = 1;
		break;
	}
	for (int i = body.size() - 1; i > 0; i--) 
	{
		body[i].setX(body[i - 1].getX());
		body[i].setY(body[i - 1].getY());
	}
	body[0].setX(body[0].getX() + x);
	body[0].setY(body[0].getY() + y);
}

void Snake::eat(Pixel pixel)
{
	body.push_back(pixel);
}


Snake::~Snake()
{
}

