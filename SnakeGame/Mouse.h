#pragma once
#include "Pixel.h"

class Mouse
{
private:
	char sign;
	Pixel body;
public:
	Mouse();
	Pixel getBody();
	void draw();
	void rebirn();
	~Mouse();
};

