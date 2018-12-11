#include "pch.h"
#include "GameSession.h"

int main()
{
	// Start a Game Session
	GameSession * gameSession = new GameSession();
	gameSession->RunGameSession ();

	// Get a character after the end of the game
	system ("pause");
	return 0;
}