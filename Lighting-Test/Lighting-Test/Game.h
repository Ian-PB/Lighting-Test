/// <summary>
/// author Pete Lowe May 2019
/// you need to change the above line or lose marks
/// </summary>
#ifndef GAME_HPP
#define GAME_HPP
/// <summary>
/// include guards used so we don't process this file twice
/// same as #pragma once
/// Don't forget the endif at the bottom
/// </summary>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Obstical.h"
#include "Globals.h"
#include "Player.h"
#include "Lighting.h"

class Game
{
public:
	Game();
	~Game();
	/// <summary>
	/// main method for game
	/// </summary>
	void run();

private:

	void processEvents();
	void processKeys(sf::Event t_event);
	void processMouseDown(sf::Event t_event);
	void processMouseMove(sf::Event t_event);

	void update(sf::Time t_deltaTime);
	void render();

	void setupObjects();
	
	// Obsticals
	Obstical obsticals[MAX_OBSTICALS];

	// Player
	Player player;
	Lighting playerLights[MAX_OBSTICALS];

	bool placing = true;
	int currentPoint = 0;
	int currentObject = 0;
	bool nextObject = false;

	sf::Vector2f mousePos;


	sf::RenderWindow m_window; // main SFML window
	bool m_exitGame; // control exiting game

};

#endif // !GAME_HPP

