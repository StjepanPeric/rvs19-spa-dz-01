#include "Background.h"


Background::Background()
{
	create_background(800, 600);
}


TileMap Background::get_tilemap()
{
	return background;
}

void Background::create_background(int width, int height)
{
	int tile_size_x = 32;
	int tile_size_y = 32;
	int row_tiles = width / tile_size_x + 1;
	int column_tiles = height / tile_size_y + 1;

	int* tiles_array = new int[row_tiles * column_tiles];

	for (int i = 0; i < column_tiles; i++)
	{
		for (int j = 0; j < row_tiles; j++)
		{
			if (j < 8)
			{
				tiles_array[i * row_tiles + j] = 0;
				continue;
			}
			if (j > 7 && i == 12 || j == 8 && i > 12)
			{
				tiles_array[i * row_tiles + j] = 3;
				continue;
			}
			if (j > 8 && i > 12)
			{
				tiles_array[i * row_tiles + j] = 1;
				continue;
			}
			tiles_array[i * row_tiles + j] = 2;
		}
	}

	if (!background.load("tileset.png", sf::Vector2u(32, 32), tiles_array, row_tiles, column_tiles))
		return;

	delete[] tiles_array;
}

