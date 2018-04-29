#include "PlayArea.h"

PlayArea::PlayArea()
{
	sign = '#';
	for (int i = 0; i < areaLimit; i++)
	{
		body.push_back(Pixel(0, i));
		body.push_back(Pixel(i, 0));
		body.push_back(Pixel(areaLimit-1, i));
		body.push_back(Pixel(i, areaLimit-1));
	}
}

PlayArea::~PlayArea()
{
}

int PlayArea::getAreaLimit()
{
	return areaLimit;
}

void PlayArea::draw()
{
	for (Pixel pixel : body)
	{
		pixel.draw(sign);
	}
}
