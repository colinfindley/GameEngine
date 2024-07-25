//--------------------------------------------------------------

//--------------------------------------------------------------

#include "Game.h"

using namespace Azul;

// HACK
Game *poGame = nullptr;

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE prevInstance, LPWSTR cmdLine, int cmdShow)
{
	int ValueReturn;

	poGame = new Game("Week 10", 2*400, 2*300);
	ValueReturn = poGame->wWinMain(hInstance, prevInstance, cmdLine, cmdShow);

	delete poGame;

	return ValueReturn;
}

// --- End of File ---
