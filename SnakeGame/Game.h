#pragma once
#include "Snake.h"
#include "Mouse.h"
#include "PlayArea.h"

class Game
{
	enum State { Started, Playing, Pause, Quit };
private:
	Snake snake;
	Mouse mouse;
	PlayArea box;
	State state;
	bool snakeEatsFood();
	bool snakeEatSelf();
	bool outOfPlayArea();
	Game();
	int score;
public:
	static Game & getInstance();
	int getScore();
	Snake getSnake();
	Mouse getMouse();
	PlayArea getBox();
	void play();
	~Game();
};

