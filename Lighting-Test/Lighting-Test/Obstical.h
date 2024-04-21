#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Globals.h"

class Obstical
{
public:

	Obstical();

	// Pass through each corner of the obstical
	void setup(int t_pointsAmount, sf::Vector2f t_mousePos, bool& t_placing, int& t_currentPoint);
	void placePoint(sf::Vector2f t_mousePos, sf::Vertex& t_point);

	sf::VertexArray getBody() { return body; }

private:


	sf::VertexArray body;
	sf::Vertex tempPoint[MAX_OBSTICAL_POINTS];
};

