#include "Game.h"

Game::Game()
{
	state = Started;
	speed = 100;
	level = 1;
}

Game::~Game()
{
}

Game & Game::getInstance()
{
	static Game instance;
	return instance;
}

std::vector<Player> Game::getPlayers()
{
	return players;
}

Snake Game::getSnake()
{
	return snake;
}

Mouse Game::getMouse()
{
	return mouse;
}

std::vector<PlayArea> Game::getPlayAreas()
{
	return playAreas;
}

void Game::CreatePlayAreas()
{
	playAreas.push_back(PlayArea());
	playAreas.push_back(PlayArea());
	playAreas.push_back(PlayArea());
	playAreas.push_back(PlayArea());
}

int Game::getSpeed()
{
	return speed;
}

void Game::levelLoader(int snake_size)
{
	if (snake_size <= 4)
	{
		playAreas[0].deserializeDataToMap(1);
		playAreas[0].draw();
	}
	else if (snake_size > 4 && snake_size <= 8)
	{
		level = 2;
		playAreas[1].deserializeDataToMap(2);
		playAreas[1].draw();
	}
	else if (snake_size > 8 && snake_size <= 16)
	{
		level = 3;
		playAreas[2].deserializeDataToMap(3);
		playAreas[2].draw();
	}
	else if (snake_size > 16)
	{
		level = 4;
		playAreas[3].deserializeDataToMap(4);
		playAreas[3].draw();
	}
}

void Game::addNewPlayer(std::string nick_name)
{
	players.push_back(Player(nick_name));
}

void Game::play()
{
	state = Playing;
	CreatePlayAreas();
	while (state == Playing)
	{
		system("cls");
		if (_kbhit())
		{
			char action = _getch();
			switch (action)
			{
			case 'w':
				snake.direction = Snake::Up;
				break;
			case 's':
				snake.direction = Snake::Down;
				break;
			case 'a':
				snake.direction = Snake::Left;
				break;
			case 'd':
				snake.direction = Snake::Right;
				break;
			default:
				break;
			}
		}
		if (snakeEatSelf() || outOfPlayArea())
		{
			state = Quit;
			break;
		}
		if (snakeEatsMouse())
		{
			snake.eat(mouse.getBody());
			mouse.rebirn();
			//Speed decreases in 2 units with every eaten mouse
			speed -= 2;
		}
		snake.move();
		snake.draw();
		mouse.draw();
		levelLoader(snake.getBody().size());
		Sleep(speed);
	}
	system("cls");
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 15); //return console color to white
	Pixel::gotoXY(5, 5); //set cursor 
	std::cout << "GAME OVER! YOUR RESULT: " << snake.getBody().size() - 1 << std::endl;
	players[0].setScore(snake.getBody().size() - 1);
	writePlayersScoreToFile();
	if (isScoreMax())
	{
		recordHighScore();
		std::cout << "CONGRATULATIONS! YOU HAVE A NEW HIGH SCORE: "
			<< snake.getBody().size() - 1 << std::endl;
	}
	showAllPlayersResult();
}

void Game::initialize()
{
	std::cout << "Enter your nick name: ";
	std::string nick_name;
	std::cin >> nick_name;
	addNewPlayer(nick_name);
	play();
}

void Game::writePlayersScoreToFile()
{
	std::ofstream out("Scores.txt", std::ofstream::out | std::ofstream::app);
	out << players[0].getNickName() << ' ' << players[0].getScore() << '\n';
	out.close();
}

void Game::recordHighScore()
{
	std::ofstream out("HighScore.txt");
	out << players[0].getScore();
	out.close();
}

bool Game::isScoreMax()
{
	std::ifstream in("HighScore.txt");
	int max_score;
	in >> max_score;
	if (in.is_open())
	{
		if (players[0].getScore() > max_score)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return true;
	}
}

std::vector<Player> Game::deserializePlayers()
{
	std::ifstream in("Scores.txt");
	std::string nick_name;
	int score;
	while (!(in.eof()))
	{
		in >> nick_name >> score;
		if (nick_name != "")
		{
			players.push_back(Player(nick_name, score));
			nick_name = "";
		}
	}
	in.close();
	return players;
}

void Game::showAllPlayersResult()
{
	deserializePlayers();
	std::cout << "Players scores:\n";
	for (int i = 1; i < players.size(); i++)
	{
		std::cout << players[i].getNickName() << " " << players[i].getScore() << std::endl;
	}
}

bool Game::snakeEatsMouse()
{
	return (snake.getBody()[0] == mouse.getBody());
}

bool Game::snakeEatSelf()
{
	for (int i = 1; i < snake.getBody().size(); i++)
	{
		if (snake.getBody()[0] == snake.getBody()[i])
		{
			return true;
		}
	}
	return false;
}

bool Game::outOfPlayArea()
{
	switch(level)
	{
	case 1:
		for (Pixel pixel : playAreas[0].getBody())
		{
			if (pixel == snake.getBody()[0])
			{
				return true;
			}
		}
		break;
	case 2:
		for (Pixel pixel : playAreas[1].getBody())
		{
			if (pixel == snake.getBody()[0])
			{
				return true;
			}
		}
		break;
	case 3:
		for (Pixel pixel : playAreas[2].getBody())
		{
			if (pixel == snake.getBody()[0])
			{
				return true;
			}
		}
		break;
	case 4:
		for (Pixel pixel : playAreas[3].getBody())
		{
			if (pixel == snake.getBody()[0])
			{
				return true;
			}
		}
		break;
	default:
		break;
	}
	
	return false;
}

