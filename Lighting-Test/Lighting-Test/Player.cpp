#include "Player.h"

Player::Player()
{
	setup();
}

void Player::setup()
{
	// Body
	position = { SCREEN_SIZE / 2, SCREEN_SIZE / 2 };
	body.setPosition(position);
	body.setRadius(radius);
	body.setOrigin(radius, radius);
	body.setFillColor(sf::Color::Blue);
}

void Player::checkBoundries()
{
	if (position.x < radius / 2)
	{
		position.x = radius / 2;
	}
	else if (position.x > SCREEN_SIZE - (radius / 2))
	{
		position.x = SCREEN_SIZE - (radius / 2);
	}

	if (position.y < radius / 2)
	{
		position.y = radius / 2;
	}
	else if (position.y > SCREEN_SIZE - (radius / 2))
	{
		position.y = SCREEN_SIZE - (radius / 2);
	}
}

void Player::checkDirection()
{
	direction = Direction::None;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		direction = Direction::Up;
		move();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		direction = Direction::Down;
		move();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		direction = Direction::Left;
		move();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		direction = Direction::Right;
		move();
	}
}

void Player::move()
{
	sf::Vector2f movement = { 0.0f, 0.0f };

	switch (direction)
	{
	case Direction::None:
		break;

	case Direction::Up:
		movement.y = -speed;
		break;

	case Direction::Down:
		movement.y = speed;
		break;

	case Direction::Left:
		movement.x = -speed;
		break;

	case Direction::Right:
		movement.x = speed;
		break;
	}
	position += movement;
	body.setPosition(position); // Change hitbox position

	checkBoundries();
}
