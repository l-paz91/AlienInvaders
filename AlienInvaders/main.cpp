// -----------------------------------------------------------------------------

//--INCLUDES--//
#include "GameConstants.h"
#include "GameManager.h"

// -----------------------------------------------------------------------------

int main()
{
	using namespace sf;

	// create the main window
	RenderWindow window(VideoMode(GameConstants::WIDTH, GameConstants::HEIGHT), "Alien Invaders Window");
	
	// set framerate - Original Space Invaders ran at 60Hz so we want to try and mimic that
	window.setFramerateLimit(60);

	// Create the Game Manager
	GameManager gameManager;

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
		gameManager.updateObjects(dt.asSeconds());

		// ---- UPDATE HUD --------------------------------------------------------- //
		gameManager.updateHUDs();

		// ---- RENDER OBJECTS ----------------------------------------------------- //
		gameManager.renderObjects(window);

		// ---- RENDER HUD --------------------------------------------------------- //
		gameManager.renderHUDs(window);

		// ---- DISPLAY WINDOW ----------------------------------------------------- //
		window.display();
	}

	return 0;
}

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------