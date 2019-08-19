#include "MatchGameScene.h"

MatchGameScene::MatchGameScene() : Scene(mainBackground)
{

}

MatchGameScene::~MatchGameScene()
{
	delete rand;
	rand = NULL;
}

void MatchGameScene::Initialise(SDL_Renderer* renderer)
{
	if (IsPreviouslyInitialised())
	{
		flipped = 0;
		mistakes = 0;
		prevFlipped = NULL;
		delete mistakesCounter;
		mistakesCounter = NULL;
		for (int i = 0; i < tileNo; i++)
		{
			delete tiles[i];
			tiles[i] = NULL;
		}
	}
	Scene::Initialise(renderer);
	std::vector<TileType> types;
	for (int i = 0; i < 8; i++)
	{
		types.push_back((TileType)i);
		types.push_back((TileType)i);
	}
	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < width; y++)
		{
			int index = rand->Next(types.size());
			TileType type = types[index];
			types.erase(types.begin() + index);
			Tile* tile = new Tile(type);
			tile->SetPosition(x*TileWidth, y*TileHeight);
			tiles[(x * width) + y] = tile;
			AddRenderable(tile,3);
		}
	}
	mistakesCounter = new PointsCounter(fontmanager->GetFont(consolasFont),2);
	for (DigitSprite* ds : mistakesCounter->DigitSprites())
	{
		AddRenderable(ds, 3);
	}
	mistakesCounter->SetPosition(575, 20);
}

void MatchGameScene::Update(float deltaTime)
{
	for (Tile* tile : tiles)
	{
		tile->Update(deltaTime);
	}
}

bool MatchGameScene::KeyDown(SDL_Keycode key)
{
	if (key == SDLK_ESCAPE)
	{
		return false;
	}
	return true;
}

bool MatchGameScene::MouseDown(SDL_MouseButtonEvent mousebutton)
{
	if (mousebutton.button == SDL_BUTTON_LEFT)
	{
		int x = mousebutton.x;
		int y = mousebutton.y;
		SDL_Point mpos = { x,y };
		for (Tile* t : tiles)
		{
			if (t->Clicked(&mpos))
			{
				if (!t->FaceUp())
				{
					t->Flip();
					if (!prevFlipped)
					{
						prevFlipped = t;
					}
					else
					{
						TileType aType = prevFlipped->GetTileType();
						TileType bType = t->GetTileType();
						if (aType != bType)
						{
							prevFlipped->Flip();
							t->Flip();
							mistakes++;
							mistakesCounter->SetValue(mistakes);
							if (mistakes >= mistakeLimit)
							{
								MatchGameUtil::Instance()->SetEndState(LOSE);
								SetNextScene(endScene);
							}
						}
						else
						{
							flipped += 2;
							//t->Flip();
						}
						prevFlipped = NULL;
					}
					if (flipped >= tileNo)
					{
						MatchGameUtil::Instance()->SetEndState(WIN);
						SetNextScene(endScene);
					}
				}
				break;
			}
		}
	}
	return true;
}