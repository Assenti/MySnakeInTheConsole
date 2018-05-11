#include "PlayArea.h"

PlayArea::PlayArea()
{
	sign = '#';
}

PlayArea::~PlayArea()
{
}

std::vector<Pixel> PlayArea::getBody()
{
	return body;
}

void PlayArea::deserializeDataToMap(int level)
{
	std::string levelMap;
	switch (level)
	{
	case 1:
		levelMap = "Level1.txt";
		break;
	case 2:
		levelMap = "Level2.txt";
		break;
	case 3:
		levelMap = "Level3.txt";
		break;
	case 4:
		levelMap = "Level4.txt";
		break;
	default:
		break;
	}

	std::ifstream in(levelMap);
	int start, end;
	in >> start >> end;
	for (int i = start; i <= end; i++)
	{
		body.push_back(Pixel(start, i));
		body.push_back(Pixel(i, start));
		body.push_back(Pixel(end, i));
		body.push_back(Pixel(i, end));
	}
}

void PlayArea::draw()
{
	for (Pixel pixel : body)
	{
		pixel.draw(sign, 9);
	}
}
