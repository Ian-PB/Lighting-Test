#include "Obstical.h"

Obstical::Obstical()
{
	body.setPrimitiveType(sf::TriangleFan);
}

void Obstical::setup(int t_pointsAmount, sf::Vector2f t_mousePos, bool& t_placing, int& t_currentPoint)
{
	// Color
	tempPoint[t_currentPoint].color = sf::Color::Red;

	// Get Point
	placePoint(t_mousePos, tempPoint[t_currentPoint]);
	// Set point
	tempPoint[t_currentPoint].position = { t_mousePos.x, t_mousePos.y };
	body.append(tempPoint[t_currentPoint]);

	if (t_currentPoint <= body.getVertexCount())
	{
		t_currentPoint++;
	}
}

void Obstical::placePoint(sf::Vector2f t_mousePos, sf::Vertex& t_point)
{
	t_point.position = t_mousePos;
}

