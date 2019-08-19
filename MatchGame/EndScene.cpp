#include "EndScene.h"

EndScene::EndScene() : Scene(mainBackground)
{

}

EndScene::~EndScene()
{

}

void EndScene::Initialise(SDL_Renderer* renderer)
{
	if (IsPreviouslyInitialised())
	{
		delete btnReplay;
		btnReplay = NULL;
		delete btnQuit;
		btnQuit = NULL;
		delete lblEndState;
		lblEndState = NULL;
	}
	Scene::Initialise(renderer);
	btnReplay = AddSprite(textureManager->GetTexture(btnReplayTexture),2);
	btnReplay->SetPosition(20, 75);
	btnQuit = AddSprite(textureManager->GetTexture(btnQuitTexture), 2);
	btnQuit->SetPosition(20, 400);
	MatchGameUtil* util = MatchGameUtil::Instance();
	ENDSTATE state = util->GetEndState();
	LPCSTR stateStr = state == WIN ? "WIN" : "Lose";
	Texture* texture = textureManager->GetTexture(stateStr);
	if (!texture)
	{
		texture = textureManager->AddTexture(stateStr, fontmanager->GetFont(consolasFont)->CreateTextTexture(stateStr, SOLID));
	}
	lblEndState = AddSprite(texture, 2);
	lblEndState->SetPosition(500, 75);
}

void EndScene::Update(float deltaTime)
{

}

bool EndScene::MouseDown(SDL_MouseButtonEvent mousebutton)
{
	if (mousebutton.button == SDL_BUTTON_LEFT)
	{
		int x = mousebutton.x;
		int y = mousebutton.y;
		SDL_Point mpos = {x, y};
		if (btnReplay->Clicked(&mpos))
		{
			MatchGameUtil::Reset();
			SetNextScene(mainScene);
		}
		else if (btnQuit->Clicked(&mpos))
		{
			return false;
		}
	}
	return true;
}