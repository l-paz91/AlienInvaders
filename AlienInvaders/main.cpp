// -----------------------------------------------------------------------------

//--INCLUDES--//
#include <SFML/Graphics.hpp>

#include "std_lib_facilities.h"

constexpr int WIDTH = 672;
constexpr int HEIGHT = 768;
constexpr int HALFW = WIDTH/2;
constexpr int HALFH = HEIGHT/2;
constexpr float TOP_BANNER = 96;
constexpr float BOT_BANNER = 51;
constexpr float LEFT_EDGE = 30;
constexpr float RIGHT_EDGE = WIDTH - LEFT_EDGE;

// -----------------------------------------------------------------------------

int main()
{
	using namespace sf;

	// create the main window
	RenderWindow window(VideoMode(672, 768), "Alien Invaders Window");

	// load a sprite to display
	Texture playerTexture;
	if (!playerTexture.loadFromFile("Graphics/PlayerSprite.png"))
		return EXIT_FAILURE;

	Sprite playerSprite(playerTexture);
	playerSprite.setOrigin(20, 0);
	playerSprite.setPosition(HALFW, HEIGHT - BOT_BANNER);

	int playerSpeed = 300;

	Clock clock;

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
		}

		// Handle Timing
		Time dt = clock.restart();

		// use left and right arrow to move player
		if (event.key.code == Keyboard::Left)
		{
			playerSprite.setPosition(
				playerSprite.getPosition().x - (playerSpeed * dt.asSeconds()), 
				playerSprite.getPosition().y);
		}
		if (event.key.code == Keyboard::Right)
		{
			playerSprite.setPosition(
				playerSprite.getPosition().x + (playerSpeed * dt.asSeconds()),
				playerSprite.getPosition().y);
		}


		// clear the screen
		window.clear();

		// draw sprites
		window.draw(playerSprite);

		// draw text

		// update the window
		window.display();
	}

	return 0;
}

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------