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
	std::vector<PlayArea> playAreas;
	State state;
	bool snakeEatsMouse();
	bool snakeEatSelf();
	bool outOfPlayArea();
	void recordHighScore();
	bool isScoreMax();
	Game();
	int speed;
	int level;
public:
	static Game & getInstance();
	std::vector<Player> getPlayers();
	Snake getSnake();
	Mouse getMouse();
	std::vector<PlayArea> getPlayAreas();
	void CreatePlayAreas();
	int getSpeed();
	void levelLoader(int);
	void addNewPlayer(std::string);
	void play();
	void initialize();
	void writePlayersScoreToFile();
	std::vector<Player> deserializePlayers();
	void showAllPlayersResult();
	~Game();
};

