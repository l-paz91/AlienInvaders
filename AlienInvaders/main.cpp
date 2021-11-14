// -----------------------------------------------------------------------------

//--INCLUDES--//
#include <SFML/Graphics.hpp>

#include "std_lib_facilities.h"

// -----------------------------------------------------------------------------

int main()
{
	using namespace sf;

	// create the main window
	RenderWindow window(VideoMode(672, 768), "Alien Invaders Window");

	// start the game loop
	while (window.isOpen())
	{
		// process events
		Event event;
		while (window.pollEvent(event))
		{
			// close the window: exit
			if (event.type == Event::Closed)
			{
				window.close();
			}

			// clear the screen
			window.clear();

			// draw sprites

			// draw text

			// update the window
			window.display();
		}
	}

	return 0;
}

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------