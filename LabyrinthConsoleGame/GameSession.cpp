#include "pch.h"
#include "GameSession.h"

GameSession::GameSession ()
{
	// Reset basic variables
	gameOver = false;
	gameWin = false;

	CreatePlayer ();
	CreateExit ();
}

#pragma region Init

void GameSession::CreatePlayer ()
{
	player.symbol = charPlayer;
	player.posX = 1;
	player.posY = 1;
}

void GameSession::CreateExit ()
{
	exit.symbol = charExit;
	exit.posY = 49;
	exit.posX = 50;
}

#pragma endregion

#pragma region GameLoop Methods

void GameSession::ProcessInputs ()
{
	if (_kbhit ())
	{
		char current = _getch ();

		switch (current)
		{
			case'a':
				if (gameMap[player.posY][player.posX - 1] != charBorder) // Detect collision
				{
					player.posX--;
					DrawGameWorld ();
					GameLogicOutputs ();
				}
				break;

			case'd':
				if (gameMap[player.posY][player.posX + 1] != charBorder) // Detect collision
				{
					player.posX++;
					DrawGameWorld ();
					GameLogicOutputs ();
				}
				break;

			case'w':
				if (gameMap[player.posY - 1][player.posX] != charBorder) // Detect collision
				{
					player.posY--;
					DrawGameWorld ();
					GameLogicOutputs ();
				}
				break;

			case's':
				if (gameMap[player.posY + 1][player.posX] != charBorder) // Detect collision
				{
					player.posY++;
					DrawGameWorld ();
					GameLogicOutputs ();
				}
				break;

			case'q':
				gameOver = true;
				break;

			default:
				break;
		}
	}
}

void GameSession::DrawGameWorld ()
{
	system ("cls");
	HANDLE console = GetStdHandle (STD_OUTPUT_HANDLE);

	// Draw game tip
	std::cout << "Press 'Q' to exit" << std::endl;
	std::cout << std::endl;

	// Draw game World
	for (int yCoord = 0; yCoord < HEIGHT; yCoord++)
	{
		for (int xCoord = 0; xCoord < WIDTH; xCoord++)
		{
			// Player
			if (xCoord == player.posX && yCoord == player.posY)
			{
				SetConsoleTextAttribute (console, FOREGROUND_RED | FOREGROUND_INTENSITY);
				std::cout << player.symbol;
				SetConsoleTextAttribute (console, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			}

			// Exit
			else if (xCoord == exit.posX && yCoord == exit.posY)
			{
				SetConsoleTextAttribute (console, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				std::cout << exit.symbol;
				SetConsoleTextAttribute (console, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			}

			// Border
			else
			{
				std::cout << gameMap[yCoord][xCoord];
			}
		}
		std::cout << std::endl;
	}
}

void GameSession::GameLogicOutputs ()
{
	if (player.posX == exit.posX && player.posY == exit.posY)
	{
		gameOver = true;
		gameWin = true;
	}
}

void GameSession::RunGameSession ()
{
	DrawGameRules ();

	while (!gameOver)
	{
		ProcessInputs ();
	}

	DrawGameEndText ();
}

void GameSession::DrawGameRules ()
{
	std::cout << "Welcome to the Labyrinth Game!!!" << std::endl;
	std::cout << "Controller Inputs: " << std::endl;
	std::cout << "W - up" << std::endl;
	std::cout << "S - down" << std::endl;
	std::cout << "D - right" << std::endl;
	std::cout << "A - left" << std::endl;
	std::cout << "Q - exit" << std::endl;
	
	std::cout << std::endl;
	std::cout << "Press 'A' to start game." << std::endl;
}

void GameSession::DrawGameEndText ()
{
	if (gameWin)
	{
		HANDLE console = GetStdHandle (STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute (console, FOREGROUND_GREEN | FOREGROUND_INTENSITY);

		std::cout << std::endl;
		std::cout << "Congratulations you're win!!!" << std::endl;
		std::cout << std::endl;

		SetConsoleTextAttribute (console, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	}
	else
	{
		HANDLE console = GetStdHandle (STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute (console, FOREGROUND_RED | FOREGROUND_INTENSITY);

		std::cout << std::endl;
		std::cout << "Maybe in the next time..." << std::endl;
		std::cout << std::endl;

		SetConsoleTextAttribute (console, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	}
}

#pragma endregion
