#include "MatchGameGame.h"

MatchGameGame* MatchGameGame::instance = 0;

MatchGameGame::MatchGameGame()
{

}

MatchGameGame::~MatchGameGame()
{

}

MatchGameGame* MatchGameGame::Instance()
{
	if (!instance)
	{
		return instance = new MatchGameGame();
	}
	return instance;
}

void MatchGameGame::Run()
{
	Game::Run(mainScene);
}

void MatchGameGame::ResourceSetup(SDL_Renderer* sdlrenderer)
{
	textureManager->AddTexture(circleTexture, "Textures\\Circle.png");
	textureManager->AddTexture(downArrowTexture, "Textures\\DownArrow.png");
	textureManager->AddTexture(heartTexture, "Textures\\Heart.png");
	textureManager->AddTexture(rightArrowTexture, "Textures\\RightArrow.png");
	textureManager->AddTexture(squareTexture, "Textures\\Square.png");
	textureManager->AddTexture(starTexture, "Textures\\Star.png");
	textureManager->AddTexture(triangleTexture, "Textures\\Triangle.png");
	textureManager->AddTexture(upArrowTexture, "Textures\\UpArrow.png");
	textureManager->AddTexture(mainBackground, "Textures\\background.png");
	textureManager->AddTexture(backFace, "Textures\\backFace.png");
	textureManager->AddTexture(btnReplayTexture, "Textures\\btnReplay.png");
	textureManager->AddTexture(btnQuitTexture, "Textures\\btnQuit.png");

	Font* consolas = new Font("Fonts\\consolaz.ttf", 50, sdlrenderer);
	fontManager->AddFont(consolasFont, consolas);

	sceneManager->AddScene(mainScene, new MatchGameScene());
	sceneManager->AddScene(endScene, new EndScene());
}