#pragma once
#include"settings.h"
#include <SFML/Graphics.hpp>
struct Bet {
	sf::RectangleShape shape;
	float speedx, speedy;
	int leftScore, rightScore;
};