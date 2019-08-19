#include "Tile.h"

std::map<TileType,String> Tile::names =
{
	{ CIRCLE,"circle" },
	{ DOWNARROW,"downarrow" },
	{ HEART,"heart" },
	{ RIGHTARROW,"rightarrow" },
	{ SQUARE,"square" },
	{ STAR,"star" },
	{ TRIANGLE,"triangle" },
	{ UPARROW,"uparrow" }
};

Tile::Tile() : Tile(CIRCLE)
{

}

Tile::Tile(TileType type) : Sprite(backFace)
{
	tileType = type;
	forwardFace = texturemanager->GetTexture(names[type]);
	backwardFace = texturemanager->GetTexture(backFace);
	flipBackward = new Animation();
	flipBackward->frames.push_back(forwardFace);
	flipBackward->frames.push_back(backwardFace);
	flipForward = new Animation();
	flipForward->frames.push_back(backwardFace);
	flipForward->frames.push_back(forwardFace);
	flipBackward->frameDuration = flipForward->frameDuration = 1.75F;
}

Tile::~Tile()
{
	delete flipBackward;
	flipBackward = NULL;
	delete flipForward;
	flipForward = NULL;
}

TileType Tile::GetTileType()
{
	return tileType;
}

bool Tile::FaceUp()
{
	return faceUp;
}

void Tile::Flip()
{
	faceUp = !faceUp;
	PlayAnimation(faceUp ? flipForward : flipBackward);
	//SetTexture(faceUp ? forwardFace : backwardFace);
}