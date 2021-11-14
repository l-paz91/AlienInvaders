// -----------------------------------------------------------------------------

//--INCLUDES--//
#include <SFML/Graphics.hpp>
#include <sstream>

#include "DebugHUD.h"
#include "GameConstants.h"
#include "Player.h"

#include "std_lib_facilities.h"
// -----------------------------------------------------------------------------

int main()
{
	using namespace sf;

	// create the main window
	RenderWindow window(VideoMode(GameConstants::WIDTH, GameConstants::HEIGHT), "Alien Invaders Window");
	
	// set framerate - Original Space Invaders ran at 60Hz so we want to try and mimic that
	window.setFramerateLimit(60);

	// Create Player
	Player player;

	// Create HUDs
	DebugHUD debugHUD;

	// clock for timing
	Clock clock;

	// start the game loop
	while (window.isOpen())
	{
		// Handle Timing
		Time dt = clock.restart();

		// ---- PROCESS EVENTS ----------------------------------------------------- //
		Event event;
		while (window.pollEvent(event))
		{
			// close the window: exit
			if (event.type == Event::Closed || event.key.code == Keyboard::Escape)
			{
				window.close();
			}
		}

		// ---- CLEAR SCREEN ------------------------------------------------------- //
		window.clear();


		// ---- UPDATE OBJECTS ----------------------------------------------------- //
		player.update(dt.asSeconds());

		// ---- UPDATE HUD --------------------------------------------------------- //
		//debugHUD.update(ss);

		// ---- RENDER OBJECTS ----------------------------------------------------- //
		player.render(window);


		// ---- RENDER HUD --------------------------------------------------------- //
		debugHUD.render(window);


		// ---- DISPLAY WINDOW ----------------------------------------------------- //
		window.display();
	}

	return 0;
}

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------