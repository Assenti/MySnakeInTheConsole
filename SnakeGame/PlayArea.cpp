#include "PlayArea.h"

PlayArea::PlayArea()
{
	sign = '#';
	for (int i = 0; i <= 25; i++)
	{
		body.push_back(Pixel(0, i));
		body.push_back(Pixel(i, 0));
		body.push_back(Pixel(25, i));
		body.push_back(Pixel(i, 25));
	}
}

PlayArea::~PlayArea()
{
}

std::vector<Pixel> PlayArea::getBody()
{
	return body;
}


void PlayArea::draw()
{
	for (Pixel pixel : body)
	{
		pixel.draw(sign);
	}
}
