#pragma once

#include <SFML/Graphics.hpp>

#include "Obstical.h"

class Lighting
{
public:
	Lighting();

	sf::VertexArray getLines() { return lines; }
	sf::VertexArray getAxis() { return axis; }
	sf::VertexArray getShadow() { return shadow; }

	// Outer lines
	void drawOuterLines(sf::RenderWindow& t_window);

	void moveLines(sf::VertexArray t_obstical, sf::Vector2f t_sourcePos);
	void axisLines(sf::Vector2f t_sourcePos);

	// Extended
	void getExtendedPoints();
	void drawExtended(sf::RenderWindow& t_window);

	// Shadow
	void makeShadow();

private:

	sf::VertexArray lines;
	sf::VertexArray lowestLine; // Lowest Line
	sf::VertexArray highestLine; // Highest Line

	// Axis
	bool axisOn = true;
	sf::VertexArray axis;
	sf::Vertex up;
	sf::Vertex down;
	sf::Vertex left;
	sf::Vertex right;

	bool changed = false;

	sf::Vector2f highestPos = {};
	float highestAngle = 0.0f;

	// Extended points position
	sf::VertexArray extendedLow;
	sf::VertexArray extendedHigh;
	sf::CircleShape lowestPoint;
	sf::CircleShape highestPoint;
	sf::Vector2f lowestExtended = {};
	sf::Vector2f highestExtended = {};

	// Shadow
	sf::VertexArray shadow;
	const sf::Color shadowColor = { 0, 0, 0, 150 };

	float extendDistance = 1200;
};

