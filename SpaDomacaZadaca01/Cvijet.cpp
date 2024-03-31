#include "Cvijet.h"


Cvijet::Cvijet(sf::RenderWindow* window)
{
	tilemap = background.get_tilemap();
	this->window = window;
	create_stem();
	create_leaves();
	create_sepals(12);
	create_petals(12);
	create_pistils();
}

void Cvijet::create_petals(int petals_number)
{
	int petal_size = 47;
	int petal_shade_size = 50;

	sf::CircleShape petal;
	petal.setPosition(125, 125);
	
	for (int i = 0; i < petals_number; i++)
	{
		petal.setRadius(petal_shade_size);
		petal.setScale(1, 0.5);
		petal.setRotation(360 / petals_number * i);
		petal.setFillColor(sf::Color(255, 223, 0));

		flower_elements.push_back(petal);

		petal.setRadius(petal_size);
		petal.setFillColor(sf::Color(255, 255, 0));

		flower_elements.push_back(petal);
	}
}

void Cvijet::create_sepals(int sepals_number)
{
	int sepal_size = 50;
	int sepal_shade_size = 3;
	int sepal_points = 3;

	sf::CircleShape sepal(sepal_size, sepal_points);
	sepal.setOutlineThickness(sepal_shade_size);
	sepal.setPosition(125, 125);
	sepal.setFillColor(sf::Color(1, 50, 32));
	sepal.setOutlineColor(sf::Color(0, 128, 0));

	for (int i = 0; i < sepals_number; i++)
	{
		sepal.setRotation(23 + 360 / sepals_number * i);

		flower_elements.push_back(sepal);
	}
}

void Cvijet::create_pistils()
{
	int pistils_size = 40;
	int pistils_shade_size = 3;

	sf::CircleShape pistils(pistils_size);
	pistils.setOutlineThickness(pistils_shade_size);
	pistils.setFillColor(sf::Color(85, 45, 20));
	pistils.setOutlineColor(sf::Color(128, 128, 0));
	pistils.setPosition(85, 85);

	flower_elements.push_back(pistils);
}

void Cvijet::create_stem()
{
	int stem_width = 13;
	int stem_height = 350;
	int stem_shade_size = 4;

	sf::RectangleShape stem(sf::Vector2f(stem_width, stem_height));
	stem.setOutlineThickness(stem_shade_size);
	stem.setFillColor(sf::Color(0, 128, 0));
	stem.setOutlineColor(sf::Color(1, 50, 32));
	stem.setPosition(135, 200);
	stem.setRotation(-10);

	stem_leaf_ridges.push_back(stem);
}

void Cvijet::create_leaves()
{
	int leaf_points = 6;
	int leaf_shade_size = 3;

	sf::ConvexShape leaf(leaf_points);
	leaf.setOutlineThickness(leaf_shade_size);
	leaf.setFillColor(sf::Color(0, 128, 0));
	leaf.setOutlineColor(sf::Color(1, 50, 32));

	leaf.setPoint(0, sf::Vector2f(0, 0));
	leaf.setPoint(1, sf::Vector2f(30, 40));
	leaf.setPoint(2, sf::Vector2f(15, 70));
	leaf.setPoint(3, sf::Vector2f(0, 130));
	leaf.setPoint(4, sf::Vector2f(-25, 70));
	leaf.setPoint(5, sf::Vector2f(-30, 40));
	leaf.setPosition(245, 240);
	leaf.setRotation(30);

	leaves.push_back(leaf);

	leaf.setPoint(0, sf::Vector2f(0, 0));
	leaf.setPoint(1, sf::Vector2f(30, 40));
	leaf.setPoint(2, sf::Vector2f(25, 70));
	leaf.setPoint(3, sf::Vector2f(0, 130));
	leaf.setPoint(4, sf::Vector2f(-15, 70));
	leaf.setPoint(5, sf::Vector2f(-30, 40));
	leaf.setPosition(52, 340);
	leaf.setRotation(-60);

	leaves.push_back(leaf);

	int ridge_width = 3;
	int ridge_height = 90;

	sf::RectangleShape leaf_ridge(sf::Vector2f(ridge_width, ridge_height));
	leaf_ridge.setFillColor(sf::Color(1, 50, 32));

	leaf_ridge.setPosition(235, 250);
	leaf_ridge.setRotation(30);

	stem_leaf_ridges.push_back(leaf_ridge);

	leaf_ridge.setPosition(67, 348);
	leaf_ridge.setRotation(-60);

	stem_leaf_ridges.push_back(leaf_ridge);
}

void Cvijet::draw_leaves()
{
	for (int i = 0; i < leaves.size(); i++)
	{
		window->draw(leaves[i]);
	}
}

void Cvijet::draw_stem_leaf_ridges()
{
	for (int i = 0; i < stem_leaf_ridges.size(); i++)
	{
		window->draw(stem_leaf_ridges[i]);
	}
}

void Cvijet::draw_flower_elements()
{
	for (int i = 0; i < flower_elements.size(); i++)
	{
		window->draw(flower_elements[i]);
	}
}

void Cvijet::update_star()
{
	animation.animate_star();
	star = animation.get_shape();
}

void Cvijet::draw_star()
{
	window->draw(star);
}

void Cvijet::draw_background()
{
	window->draw(tilemap);
}

void Cvijet::draw()
{
	draw_background();
	draw_leaves();
	draw_stem_leaf_ridges();
	draw_flower_elements(); 
	update_star();
	draw_star();
}
