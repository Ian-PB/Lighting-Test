#include "Obstical.h"

Obstical::Obstical()
{
	body.setPrimitiveType(sf::TriangleFan);
}

bool Obstical::make(sf::Vector2f t_mousePos, int& t_currentPoint)
{
	sf::Vertex point;
	// Color
	point.color = sf::Color::Red;

	// Get Point
	placePoint(t_mousePos, point);

	// Set point
	body.append(point);

	if (t_currentPoint < MAX_OBSTICAL_POINTS)
	{
		t_currentPoint++;

		return false;
	}
	else
	{
		return true;
	}
}

void Obstical::placePoint(sf::Vector2f t_mousePos, sf::Vertex& t_point)
{
	t_point.position = t_mousePos;
}

