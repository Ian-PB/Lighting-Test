#include "Lighting.h"

Lighting::Lighting()
{
	lines.setPrimitiveType(sf::Lines);
	axis.setPrimitiveType(sf::Lines);

	highestLine.setPrimitiveType(sf::Lines);
	lowestLine.setPrimitiveType(sf::Lines);

	extendedLow.setPrimitiveType(sf::Lines);
	extendedHigh.setPrimitiveType(sf::Lines);

	lowestPoint.setFillColor(sf::Color::Blue);
	lowestPoint.setRadius(5);
	lowestPoint.setOrigin(5, 5);
	highestPoint.setFillColor(sf::Color::Yellow);
	highestPoint.setRadius(5);
	highestPoint.setOrigin(5, 5);

	// Shadow
	shadow.setPrimitiveType(sf::TrianglesFan);

}

void Lighting::drawOuterLines(sf::RenderWindow& t_window)
{
	t_window.draw(lowestLine);
	t_window.draw(highestLine);
}

void Lighting::moveLines(sf::VertexArray t_obstical, sf::Vector2f t_sourcePos)
{
	lines.clear();

	for (int i = 0; i < t_obstical.getVertexCount(); i++)
	{
		lines.append(t_sourcePos);
		lines.append(t_obstical[i]);
	}

	// Set the color
	for (int i = 0; i < lines.getVertexCount(); i++)
	{
		lines[i].color = sf::Color::White;
	}

	// Angles
	float previousHighest = 0.0f;
	float previousLowest = 400.0f;
	sf::Vector2f pos1 = {};
	sf::Vector2f pos2 = {};

	for (int l = 0; l < lines.getVertexCount(); l++)
	{
		// Get the coords needed
		for (int i = 0; i < 2; i++)
		{
			if (i == 0) // First coords
			{
				pos1.x = t_sourcePos.x;
				pos1.y = t_sourcePos.y;
			}
			else // Second coords
			{
				pos2.x = lines[l + 1].position.x;
				pos2.y = lines[l + 1].position.y;

				l += 1;
			}
		}
		

		// Get Angles of lines
		sf::Vector2f direction = {};

		direction.x = (pos2.x) - pos1.x;
		direction.y = (pos2.y) - pos1.y;

		float angleR = atan2(direction.y, direction.x);
		float angleD = angleR * (180 / 3.14f);
		angleD *= -1;

		if (angleD > 90 && angleD <= 180)
		{
			angleD = 360 + ((angleD - 90) * (-1));
		}
		else
		{
			angleD = (angleD - 90) * -1;
		}


		// Get the highest angle and pos
		if (angleD > highestAngle)
		{
			highestAngle = angleD;
			highestPos = pos2;
		}


		// HIGHEST
		if (previousHighest < 270)
		{
			if (angleD > previousHighest)
			{
				// Clear vertex array
				highestLine.clear();

				// Points
				highestLine.append(pos2);
				highestLine[0].color = sf::Color::Yellow;

				previousHighest = angleD;
			}
		}
		else if (previousHighest < 360 && previousHighest > 270 && previousLowest < 270 && previousLowest > 180)
		{
			if (angleD > previousHighest)
			{
				// Clear vertex array
				highestLine.clear();

				// Points
				highestLine.append(pos2);
				highestLine[0].color = sf::Color::Yellow;

				previousHighest = angleD;
			}
		}
		else 
		{
			if (angleD < previousHighest && angleD > 180)
			{
				// Clear vertex array
				highestLine.clear();
				highestLine.clear();

				// Points
				highestLine.append(pos2);
				highestLine[0].color = sf::Color::Yellow;

				previousHighest = angleD;
			}
		}



		// LOWEST
		if (previousHighest < 360 && previousHighest > 270 && previousLowest < 180 && previousLowest >= 0)
		{
			if (angleD < 90 && angleD > 0)
			{

				if (angleD > previousLowest && angleD <= 180)
				{
					// Clear vertex array
					lowestLine.clear();

					// Points
					lowestLine.append(pos2);
					lowestLine[0].color = sf::Color::Blue;

					previousLowest = angleD;
				}
			}
		}
		// THIS NEEDS TO CHECK IF THE LOWEST IS FROM 0-90 AND THE HIGHEST IS FROM 270-360
		else if (previousHighest > 270 && previousHighest < 360 && previousLowest > 0 && previousLowest < 90)
		{
			if (!changed)
			{
				previousLowest = 0.0f;
				changed = true;
			}

			if (angleD < previousLowest && angleD <= 180)
			{
				// Clear vertex array
				lowestLine.clear();

				// Points
				lowestLine.append(pos2);
				lowestLine[0].color = sf::Color::Blue;

				previousLowest = angleD;
			}
		}
		else if (previousHighest < 360 && previousHighest > 270 && previousLowest < 360 && previousLowest >= 270)
		{

			if (angleD < previousLowest)
			{

				// Clear vertex array
				lowestLine.clear();

				// Points
				lowestLine.append(pos2);
				lowestLine[0].color = sf::Color::Blue;

				previousLowest = angleD;
			}

			if (previousHighest == previousLowest)
			{
				if (angleD > previousLowest)
				{
					// Clear vertex array
					lowestLine.clear();

					// Points
					lowestLine.append(highestPos);
					lowestLine[0].color = sf::Color::Blue;

					previousLowest = angleD;


					highestAngle = 0;
				}
			}
		}
		else
		{
			// Check if it's Lower
			if (angleD < previousLowest)
			{
				// Clear vertex array
				lowestLine.clear();

				// Points
				lowestLine.append(pos2);
				lowestLine[0].color = sf::Color::Blue;

				previousLowest = angleD;
			}
		}


		// Plot from source origin
		lowestLine.append(t_sourcePos);
		highestLine.append(t_sourcePos);
	}
}

void Lighting::axisLines(sf::Vector2f t_sourcePos)
{
	// Axis
	if (axisOn)
	{
		axis.clear();

		up.position = { t_sourcePos.x, 0 };
		up.color = sf::Color::Green;
		axis.append(t_sourcePos);
		axis.append(up);

		down.position = { t_sourcePos.x, SCREEN_SIZE };
		down.color = sf::Color::Green;
		axis.append(t_sourcePos);
		axis.append(down);

		left.position = { 0, t_sourcePos.y };
		left.color = sf::Color::Green;
		axis.append(t_sourcePos);
		axis.append(left);

		right.position = { SCREEN_SIZE, t_sourcePos.y };
		right.color = sf::Color::Green;
		axis.append(t_sourcePos);
		axis.append(right);
	}
}

void Lighting::getExtendedPoints()
{
	extendedLow.clear();
	extendedHigh.clear();
	// Assign line
	extendedHigh = highestLine;
	extendedLow = lowestLine;

	float length = 0.0f;

	/// Lowest Point ///

	// Lowest Slope
	float lowestSlope = (lowestLine[0].position.y - lowestLine[1].position.y) / (lowestLine[0].position.x - lowestLine[1].position.x);


	// Make the point
	float lowestX = lowestLine[0].position.x - lowestLine[1].position.x;
	float lowestY = lowestLine[0].position.y - lowestLine[1].position.y;

	length = std::sqrt(lowestX * lowestX + lowestY * lowestY);

	lowestX /= length;
	lowestY /= length;

	// Make the point
	lowestExtended.x = lowestX;
	lowestExtended.y = lowestY;

	extendedLow[0].position.x += extendDistance * lowestX;
	extendedLow[0].position.y += extendDistance * lowestY;


	/// Highest Point ///
	
	// Lowest Slope
	float highestSlope = (highestLine[0].position.y - highestLine[1].position.y) / (highestLine[0].position.x - highestLine[1].position.x);


	float highestX = highestLine[0].position.x - highestLine[1].position.x;
	float highestY = highestLine[0].position.y - highestLine[1].position.y;

	length = std::sqrt(highestX * highestX + highestY * highestY);

	highestX /= length;
	highestY /= length;

	// Make the point
	highestExtended.x = highestX;
	highestExtended.y = highestY;

	// Make the line
	extendedHigh[0].position.x += extendDistance * highestX;
	extendedHigh[0].position.y += extendDistance * highestY;

	

	// Highest Extended
	highestExtended = extendedHigh[0].position;
	// Lowest Extended
	lowestExtended = extendedLow[0].position;

	highestPoint.setPosition(highestExtended);
	lowestPoint.setPosition(lowestExtended);
}
void Lighting::drawExtended(sf::RenderWindow& t_window)
{
	t_window.draw(extendedHigh);
	t_window.draw(extendedLow);

	t_window.draw(lowestPoint);
	t_window.draw(highestPoint);
}

void Lighting::makeShadow()
{
	shadow.clear();

	// Add each point
	shadow.append(highestLine[0]);
	shadow.append(lowestLine[0]);
	shadow.append(lowestExtended);
	shadow.append(highestExtended);

	for (int i = 0; i < shadow.getVertexCount(); i++)
	{
		shadow[i].color = shadowColor;
	}


}
