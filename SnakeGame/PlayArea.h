#pragma once
#include "Pixel.h"
#include <vector>

class PlayArea
{
private:
	char sign;
	std::vector<Pixel> body;
public:
	PlayArea();
	~PlayArea();
	std::vector<Pixel> getBody();
	void draw();
};

