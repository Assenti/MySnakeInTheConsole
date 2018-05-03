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
		if (snakeEatSelf() || outOfPlayArea())
		{
			state = Quit;
			break;
		}
		if (snakeEatsFood())
		{
			snake.eat(mouse.getBody());
			score++;
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
	std::cout << "GAME OVER! YOUR RESULT: " << score << std::endl;
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


