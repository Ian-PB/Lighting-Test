#pragma once

#include <SFML/Graphics.hpp>

#include "Globals.h"

enum class Direction
{
	None,
	Up,
	Down,
	Left,
	Right
};

class Player
{
public:

	Player();
	void setup();

	sf::CircleShape getBody() { return body; }

	void checkBoundries();
	void checkDirection();
	void move();


private:

	sf::CircleShape body;
	float radius = 20.0f;

	sf::Vector2f position;

	int speed = 5;
	Direction direction;

};

