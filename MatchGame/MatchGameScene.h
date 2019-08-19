#ifndef _MATCHGAMESCENE_H
#define _MATCHGAMESCENE_H

#include "Scene.h"
#include "Constants.h"
#include "Tile.h"
#include "CSRand.h"
#include "MatchGameUtil.h"
#include "PointsCounter.h"

class MatchGameScene : public Scene
{
	public:
		MatchGameScene();
		~MatchGameScene();
		void Initialise(SDL_Renderer* renderer);
	private:
		void Update(float deltaTime);
		bool KeyDown(SDL_Keycode key);
		bool MouseDown(SDL_MouseButtonEvent mousebutton);
		static const int tileNo = 16;
		static const int width = 4;
		Tile* prevFlipped;
		Tile* tiles[tileNo];
		PointsCounter* mistakesCounter;
		CSRand* rand = new CSRand();
		int flipped = 0;
		int mistakes = 0;
		const int mistakeLimit = 15;
};

#endif