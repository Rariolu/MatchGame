#ifndef _TILE_H
#define _TILE_H

#include "Sprite.h"
#include "Constants.h"

enum TileType
{
	CIRCLE,
	DOWNARROW,
	HEART,
	RIGHTARROW,
	SQUARE,
	STAR,
	TRIANGLE,
	UPARROW
};

class Tile : public Sprite
{
	public:
		Tile();
		Tile(TileType type);
		~Tile();
		TileType GetTileType();
		bool FaceUp();
		void Flip();
	private:
		Animation* flipForward;
		Animation* flipBackward;
		TileType tileType;
		bool faceUp = false;
		Texture* forwardFace;
		Texture* backwardFace;
		static std::map<TileType, String> names;
};

#endif