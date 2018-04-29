#pragma once
#include "Pixel.h"
#include <vector>

class PlayArea
{
private:
	char sign;
	std::vector<Pixel> body;
	int areaLimit = 20;
public:
	PlayArea();
	~PlayArea();
	int getAreaLimit();
	void draw();
};

