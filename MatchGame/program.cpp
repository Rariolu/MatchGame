#include "MatchGameGame.h"
#include "Tile.h"
#include "icon.c"

MatchGameGame* game = MatchGameGame::Instance();

int main(int argc, char *argv[])
{
	return game->CreateGameWindow(WindowTitle, WindowWidth, WindowHeight, matchgame_icon);
}