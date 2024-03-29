#ifndef GameSession_h
#define GameSession_h

#include <iostream>

#include <windows.h>
#include <conio.h>

#include "Character.h"

class GameSession
{
private:
	// Basic
	bool gameOver;
	bool gameWin;
	bool startGame;

	char startChar;

	// Map
	const char charBorder = '#';
	const char charEmptySpace = ' ';
	const char charExit = 'E';
	const char charPlayer = 'P';

	// Characters
	Character player;
	Character exit;

#pragma region Map

	// The map properties
	static const char HEIGHT = 51, WIDTH = 51;
	unsigned char gameMap[HEIGHT][WIDTH] =
	{
		'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#', // 1
' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ','#',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ','#',' ','#',
'#',' ','#','#','#','#','#','#','#','#','#','#','#',' ','#',' ','#',' ','#','#','#',' ','#',' ','#',' ','#','#','#',' ','#','#','#','#','#','#','#',' ','#',' ','#',' ','#',' ','#','#','#',' ','#',' ','#',
'#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ','#',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ','#',' ','#',' ','#',' ',' ',' ',' ',' ','#',' ','#',
'#',' ','#',' ','#',' ','#',' ','#','#','#',' ','#',' ','#','#','#',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' ','#',' ','#',' ','#','#','#',' ','#','#','#','#','#','#','#',' ','#',
'#',' ','#',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ','#',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ','#',' ','#',' ','#',' ','#',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ','#',
'#',' ','#',' ','#','#','#','#','#','#','#',' ','#',' ','#',' ','#','#','#',' ','#','#','#',' ','#',' ','#','#','#',' ','#',' ','#',' ','#',' ','#','#','#',' ','#','#','#','#','#','#','#',' ','#',' ','#',
'#',' ','#',' ','#',' ',' ',' ','#',' ','#',' ','#',' ','#',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ',' ',' ',' ','#',' ','#',' ','#',
'#',' ','#','#','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#','#','#',' ','#','#','#','#','#',' ','#',' ','#','#','#',' ','#',' ','#','#','#','#','#',' ','#',' ','#',' ','#',
'#',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ',' ',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ','#',' ','#', // 10
'#',' ','#',' ','#','#','#','#','#','#','#',' ','#','#','#','#','#','#','#',' ','#','#','#',' ','#',' ','#',' ','#',' ','#','#','#',' ','#',' ','#','#','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',
'#',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',
'#',' ','#','#','#','#','#','#','#',' ','#',' ','#','#','#',' ','#',' ','#','#','#','#','#','#','#','#','#','#','#',' ','#',' ','#',' ','#','#','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#','#','#',
'#',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ','#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ',' ',' ','#',
'#',' ','#','#','#',' ','#',' ','#','#','#',' ','#',' ','#','#','#','#','#',' ','#',' ','#','#','#','#','#','#','#','#','#','#','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',
'#',' ','#',' ',' ',' ','#',' ','#',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ','#',' ',' ',' ','#',' ','#',' ','#',
'#',' ','#',' ','#','#','#',' ','#',' ','#','#','#','#','#','#','#',' ','#',' ','#','#','#','#','#',' ','#','#','#','#','#',' ','#',' ','#','#','#','#','#',' ','#',' ','#','#','#','#','#',' ','#',' ','#',
'#',' ',' ',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ','#',' ','#',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ','#',' ','#',' ',' ',' ',' ',' ','#',' ','#',
'#',' ','#','#','#','#','#','#','#',' ','#',' ','#',' ','#','#','#','#','#',' ','#',' ','#',' ','#','#','#',' ','#','#','#','#','#','#','#','#','#','#','#','#','#',' ','#',' ','#','#','#','#','#',' ','#',
'#',' ',' ',' ',' ',' ','#',' ',' ',' ','#',' ','#',' ','#',' ',' ',' ',' ',' ',' ',' ','#',' ','#',' ','#',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ','#',' ',' ',' ',' ',' ','#',' ','#', // 20
'#','#','#','#','#',' ','#','#','#','#','#',' ','#',' ','#',' ','#','#','#',' ','#','#','#',' ','#',' ','#',' ','#','#','#','#','#',' ','#',' ','#','#','#',' ','#',' ','#','#','#','#','#',' ','#',' ','#',
'#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ','#',' ','#',' ',' ',' ','#',' ','#',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ','#',' ','#',' ','#',
'#',' ','#','#','#','#','#',' ','#','#','#','#','#','#','#','#','#',' ','#',' ','#',' ','#','#','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#','#','#',' ','#','#','#',' ','#',' ','#',' ','#',' ','#',
'#',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ','#',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ','#',' ','#',
'#','#','#','#','#','#','#','#','#','#','#',' ','#',' ','#',' ','#','#','#','#','#','#','#',' ','#',' ','#','#','#',' ','#',' ','#','#','#','#','#',' ','#',' ','#',' ','#',' ','#','#','#',' ','#',' ','#',
'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','#',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ','#',' ','#',' ','#',' ',' ',' ',' ',' ','#',' ','#',
'#',' ','#',' ','#','#','#','#','#','#','#','#','#','#','#','#','#',' ','#','#','#','#','#','#','#','#','#',' ','#',' ','#','#','#',' ','#',' ','#',' ','#','#','#',' ','#','#','#','#','#','#','#',' ','#',
'#',' ','#',' ',' ',' ',' ',' ','#',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ','#',' ','#',' ','#',' ',' ',' ',' ',' ','#',' ','#',' ',' ',' ',' ',' ',' ',' ','#',
'#',' ','#','#','#','#','#',' ','#',' ','#',' ','#','#','#','#','#','#','#',' ','#',' ','#','#','#',' ','#','#','#','#','#',' ','#',' ','#','#','#','#','#',' ','#',' ','#',' ','#','#','#','#','#','#','#',
'#',' ','#',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ','#',' ','#',' ',' ',' ','#',' ','#',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ','#',' ','#',' ',' ',' ',' ',' ','#', // 30
'#',' ','#',' ','#','#','#','#','#','#','#',' ','#','#','#',' ','#','#','#','#','#',' ','#',' ','#','#','#',' ','#',' ','#',' ','#','#','#',' ','#',' ','#','#','#',' ','#',' ','#',' ','#','#','#',' ','#',
'#',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ','#',' ','#',' ','#',' ','#',' ',' ',' ','#',' ',' ',' ','#',
'#',' ','#','#','#',' ','#',' ','#',' ','#','#','#',' ','#',' ','#',' ','#','#','#','#','#',' ','#','#','#',' ','#',' ','#','#','#',' ','#','#','#',' ','#',' ','#',' ','#','#','#','#','#',' ','#','#','#',
'#',' ',' ',' ','#',' ','#',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ','#',' ','#',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ','#',
'#','#','#',' ','#',' ','#',' ','#','#','#',' ','#','#','#','#','#',' ','#','#','#','#','#','#','#',' ','#','#','#','#','#',' ','#','#','#',' ','#',' ','#','#','#','#','#',' ','#','#','#','#','#',' ','#',
'#',' ',' ',' ','#',' ','#',' ','#',' ','#',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ','#',
'#',' ','#','#','#',' ','#',' ','#',' ','#','#','#',' ','#','#','#',' ','#','#','#',' ','#','#','#','#','#','#','#','#','#',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' ','#',' ','#',
'#',' ','#',' ','#',' ','#',' ','#',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',
'#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#','#','#','#','#','#','#',' ','#','#','#','#','#',' ','#',' ','#',' ','#','#','#',' ','#',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',
'#',' ',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ','#',' ','#',' ','#',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ',' ',' ','#', // 40
'#',' ','#','#','#',' ','#','#','#','#','#',' ','#','#','#',' ','#',' ','#','#','#','#','#',' ','#',' ','#',' ','#',' ','#',' ','#','#','#','#','#',' ','#',' ','#','#','#',' ','#',' ','#','#','#',' ','#',
'#',' ',' ',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ',' ','#',
'#','#','#','#','#','#','#',' ','#',' ','#','#','#',' ','#','#','#','#','#',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' ','#',' ','#','#','#','#','#',' ','#','#','#',
'#',' ',' ',' ',' ',' ','#',' ','#',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','#',' ',' ',' ',' ',' ',' ',' ','#',
'#',' ','#','#','#','#','#',' ','#','#','#',' ','#',' ','#','#','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#','#','#','#','#',' ','#','#','#','#','#',' ','#',' ','#','#','#','#','#',' ','#',
'#',' ','#',' ',' ',' ',' ',' ','#',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ','#',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ','#',
'#',' ','#',' ','#',' ','#','#','#',' ','#','#','#',' ','#',' ','#',' ','#',' ','#',' ','#','#','#','#','#',' ','#','#','#',' ','#',' ','#','#','#',' ','#',' ','#','#','#',' ','#',' ','#',' ','#','#','#',
'#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ','#',' ','#',' ','#',
'#','#','#','#','#','#','#',' ','#',' ','#','#','#','#','#',' ','#','#','#','#','#',' ','#','#','#',' ','#',' ','#','#','#',' ','#',' ','#',' ','#','#','#','#','#','#','#','#','#',' ','#',' ','#',' ','#',
'#',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ', // 50
'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#', // 51

	};

#pragma endregion

public:
	GameSession ();

	// Init 
	void CreatePlayer ();
	void CreateExit ();

	// The GameLoop methods
	void ProcessInputs ();
	void DrawGameWorld ();
	void GameLogicOutputs ();
	void RunGameSession ();

	void DrawGameRules ();
	void DrawGameEndText ();
};

#endif // !GameSession_h

