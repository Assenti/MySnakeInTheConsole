#include "Game.h"

Game::Game()
{
	state = Started;
	score = 0;
}

Game::~Game()
{
}

Game & Game::getInstance()
{
	static Game instance;
	return instance;
}

int Game::getScore()
{
	return score;
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
		if (snakeEatsFood()) 
		{
			snake.eat(mouse.getBody());
			score++;
			mouse.rebirn();
		}
		if (snakeEatSelf() || outOfPlayArea())
		{
			state = Quit;
		}
		box.draw();
		snake.move();
		snake.draw();
		mouse.draw();
		Sleep(100);
	}
	system("cls");
	Pixel::gotoXY(5, 5);
	std::cout << "GAME OVER! YOUR RESULT: " << score << std::endl;
}

bool Game::snakeEatsFood()
{
	return (snake.getBody()[0] == mouse.getBody());
}

bool Game::snakeEatSelf()
{
	for (int i = 3; i < snake.getBody().size(); i++)
	{
		if (snake.getBody()[0].getX() == snake.getBody()[i].getX()
			&& snake.getBody()[0].getY() == snake.getBody()[i].getY())
		{
			return true;
		}
	}
	return false;
}

bool Game::outOfPlayArea()
{
	if ((snake.getBody()[0].getX() == 0 || snake.getBody()[0].getY() == 0) ||
		(snake.getBody()[0].getX() == box.getAreaLimit() || snake.getBody()[0].getX() == box.getAreaLimit()))
	{
		return true;
	}
	else
	{
		return false;
	}
}


