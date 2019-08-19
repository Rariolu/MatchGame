#ifndef _MATCHGAMEGAME_H
#define _MATCHGAMEGAME_H

#include "Game.h"
#include "MatchGameScene.h"
#include "EndScene.h"

class MatchGameGame : public Game
{
	public:
		static MatchGameGame* Instance();
		~MatchGameGame();
		void Run();
		void ResourceSetup(SDL_Renderer* sdlrenderer);
	private:
		MatchGameGame();
		static MatchGameGame* instance;
};

#endif