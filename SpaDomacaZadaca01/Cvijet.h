#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Animation.h"
#include "TileMap.h"
#include "Background.h"


class Cvijet
{
private:

	sf::RenderWindow* window;

	std::vector<sf::CircleShape> flower_elements;
	std::vector<sf::ConvexShape> leaves;
	std::vector< sf::RectangleShape> stem_leaf_ridges;
	void create_petals(int petals_number);
	void create_sepals(int sepals_number);
	void create_pistils();
	void create_stem();
	void create_leaves();

	void draw_leaves();
	void draw_stem_leaf_ridges();
	void draw_flower_elements();

	Animation animation;
	sf::ConvexShape star;
	void update_star();
	void draw_star();

	Background background;
	TileMap tilemap;
	void draw_background();

public:

	Cvijet(sf::RenderWindow* window);
	void draw();
};

