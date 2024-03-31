#pragma once
#include "TileMap.h"


class Background
{
private:

	void create_background(int width, int height);
	TileMap background;

public:

	Background();
	TileMap get_tilemap();
};

