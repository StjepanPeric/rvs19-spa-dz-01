#include "Animation.h"
#include <ctime>
#include <cmath>


Animation::Animation()
{
	star = create_star(5, 30, 80);
}

sf::ConvexShape Animation::get_shape()
{
	return star;
}

sf::ConvexShape Animation::create_star(int star_points, int internal_radius, int external_radius)
{
	sf::ConvexShape star(2 * star_points);

	for (int i = 0; i < star_points; i++)
	{
		star.setPoint(2 * i, sf::Vector2f(external_radius * cos(2 * i * acos(-1) / star_points + acos(-1) / 2),
											external_radius * sin(2 * i * acos(-1) / star_points + acos(-1) / 2)));

		star.setPoint(2 * i + 1, sf::Vector2f(internal_radius * cos(2 * i * acos(-1) / star_points + acos(-1) / 2 + acos(-1) / star_points),
												internal_radius * sin(2 * i * acos(-1) / star_points + acos(-1) / 2 + acos(-1) / star_points)));
	}

	srand(time(nullptr));
	int star_shade_size = 3;

	star.setOutlineThickness(star_shade_size);
	star.setRotation(180);
	star.setPosition(85 + rand() % 635, 85 + rand() % 440);
	star.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
	star.setOutlineColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
	
	set_animation_parameters();
	clock.restart();

	return star;
}

void Animation::set_animation_parameters()
{
	int velocity = 3;
	move_x = velocity * direction();
	move_y = velocity * direction();
}

int Animation::direction()
{
	if (rand() % 2 == 0) return 1;
	return -1;
}

void Animation::move_star()
{
	star.move(sf::Vector2f(move_x, move_y));
}

void Animation::recolor_star()
{
	star.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
	star.setOutlineColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
}

void Animation::animate_star()
{
	int fps = 60;
	sf::Time vrijeme = sf::milliseconds(1000 / fps);

	if (clock.getElapsedTime() > vrijeme)
	{
		move_star();
		if (star.getPosition().x < 0 + 85 || star.getPosition().x > 800 - 80)
		{
			recolor_star();
			move_x *= -1;
		}
		if (star.getPosition().y < 0 + 85 || star.getPosition().y > 600 - 75)
		{
			recolor_star();
			move_y *= -1;
		}
		clock.restart();
	}
}


