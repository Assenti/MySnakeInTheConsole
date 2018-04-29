#pragma once
#include <vector>
#include "Pixel.h"

class Snake
{
private:
	std::vector<Pixel> body;
	char sign;
public:
	Snake();
	enum Direction { Up, Down, Left, Right, Default };
	Direction direction;
	std::vector<Pixel> getBody();
	void draw();
	void move();
	void eat(Pixel);
	~Snake();

};

