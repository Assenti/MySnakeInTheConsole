#pragma once
#include <string>

class Player
{
private:
	std::string nick_name;
	int score;
public:
	std::string getNickName();
	int getScore();
	void setScore(int);
	Player(std::string);
	Player(std::string, int);
	~Player();
};

