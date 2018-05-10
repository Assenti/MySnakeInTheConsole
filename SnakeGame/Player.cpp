#include "Player.h"

std::string Player::getNickName()
{
	return nick_name;
}

int Player::getScore()
{
	return score;
}

void Player::setScore(int score)
{
	this->score = score;
}

Player::Player(std::string nick_name)
{
	this->nick_name = nick_name;
}

Player::Player(std::string nick_name, int score) : Player(nick_name)
{
	this->score = score;
}

Player::~Player()
{
}
