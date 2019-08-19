#ifndef _ENDSCENE_H
#define _ENDSCENE_H

#include "Scene.h"
#include "Constants.h"
#include "MatchGameUtil.h"

class EndScene : public Scene
{
	public:
		EndScene();
		~EndScene();
		void Initialise(SDL_Renderer* renderer);
	private:
		void Update(float deltaTime);
		bool MouseDown(SDL_MouseButtonEvent mousebutton);
		Sprite* btnReplay;
		Sprite* btnQuit;
		Sprite* lblEndState;
};

#endif