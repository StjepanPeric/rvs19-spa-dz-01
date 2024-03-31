#pragma once
#include <SFML/Graphics.hpp>


class Animation
{
private:

	sf::ConvexShape star;
	sf::ConvexShape create_star(int star_points, int internal_radius, int external_radius);
	sf::Clock clock;

	void set_animation_parameters();
	int direction();
	int move_x;
	int move_y;
	void move_star();
	void recolor_star();

public:

	Animation();
	sf::ConvexShape get_shape();
	void animate_star();
};

