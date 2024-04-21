#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Globals.h"

class Obstical
{
public:

	Obstical();

	// Pass through each corner of the obstical
	bool make(sf::Vector2f t_mousePos, int& t_currentPoint);
	void placePoint(sf::Vector2f t_mousePos, sf::Vertex& t_point);

	sf::VertexArray getBody() { return body; }

private:


	sf::VertexArray body;
};

