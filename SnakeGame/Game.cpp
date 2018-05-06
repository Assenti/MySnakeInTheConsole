#include "Game.h"

Game::Game()
{
	state = Started;
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

PlayArea Game::getBox()
{
	return box;
}

void Game::addNewPlayer(std::string nick_name)
{
	players.push_back(Player(nick_name));
}

void Game::play()
{
	state = Playing;
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
		if (snakeEatsFood())
		{
			snake.eat(mouse.getBody());
			mouse.rebirn();
		}
		snake.move();
		snake.draw();
		mouse.draw();
		box.draw();
		Sleep(100);
	}
	system("cls");
	Pixel::gotoXY(5, 5);
	std::cout << "GAME OVER! YOUR RESULT: " << snake.getBody().size() - 1 << std::endl;
	players[0].setScore(snake.getBody().size() - 1);
	writePlayersScoreToFile(players[0]);
	if (isScoreMax(players[0]))
	{
		recordHighScore(players[0]);
		std::cout << "CONGRATULATIONS! YOU HAVE A NEW HIGH SCORE: " << snake.getBody().size() - 1 << std::endl;
	}
}

void Game::initialize()
{
	std::cout << "Enter your nick name: ";
	std::string nick_name;
	std::cin >> nick_name;
	addNewPlayer(nick_name);
	play();
}

void Game::writePlayersScoreToFile(Player & p)
{
	std::ofstream out("Scores.txt", std::ofstream::out | std::ofstream::app);
	out << p.getNickName() << ' ' << p.getScore() << '\n';
	out.close();
}

void Game::recordHighScore(Player & p)
{
	std::ofstream out("HighScore.txt");
	out << p.getScore();
	out.close();
}

bool Game::isScoreMax(Player & p)
{
	std::ifstream in("HighScore.txt");
	int max_score;
	in >> max_score;
	if (in.is_open())
	{
		if (p.getScore() > max_score)
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

bool Game::snakeEatsFood()
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
	for (Pixel pixel : box.getBody())
	{
		if (pixel == snake.getBody()[0])
		{
			return true;
		}
	}
	return false;
}

