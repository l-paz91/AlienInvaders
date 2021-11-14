// -----------------------------------------------------------------------------

//--INCLUDES--//
#include <SFML/Graphics.hpp>

#include "GameConstants.h"
#include "Player.h"

#include "std_lib_facilities.h"
// -----------------------------------------------------------------------------

int main()
{
	using namespace sf;

	// create the main window
	RenderWindow window(VideoMode(GameGlobals::WIDTH, GameGlobals::HEIGHT), "Alien Invaders Window");

	// Create Player
	Player player;

	// clock for timing
	Clock clock;

	// start the game loop
	while (window.isOpen())
	{
		// Handle Timing
		Time dt = clock.restart();

		// process events
		Event event;
		while (window.pollEvent(event))
		{
			// close the window: exit
			if (event.type == Event::Closed || event.key.code == Keyboard::Escape)
			{
				window.close();
			}

			// update player input
			player.updateInput(event);
		}

		// clear the screen
		window.clear();

		// draw sprites
		player.render(window);

		// draw text

		// update the window
		window.display();
	}

	return 0;
}

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------