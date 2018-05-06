#pragma once
#include "Snake.h"
#include "Mouse.h"
#include "PlayArea.h"
#include "Player.h"
#include <vector>
#include <fstream>
#include <iostream>

class Game
{
	enum State { Started, Playing, Pause, Quit };
private:
	std::vector<Player> players;
	Snake snake;
	Mouse mouse;
	PlayArea box;
	State state;
	bool snakeEatsFood();
	bool snakeEatSelf();
	bool outOfPlayArea();
	Game();
public:
	static Game & getInstance();
	std::vector<Player> getPlayers();
	Snake getSnake();
	Mouse getMouse();
	PlayArea getBox();
	void addNewPlayer(std::string);
	void play();
	void initialize();
	void writePlayersScoreToFile(Player &);
	void recordHighScore(Player &);
	bool isScoreMax(Player &);
	~Game();
};

