// -----------------------------------------------------------------------------
#ifndef GameConstants_H
#define GameConstants_H
// -----------------------------------------------------------------------------

/*
*
*	In the original Space Invaders the screen is 224x256
*	Everything in this game is scaled by 3. This game is 672x768.
*	Banners relate to the screen padding at the top and bottom where the score
*   and lives are held.
*
*/

//--INCLUDES--//

// -----------------------------------------------------------------------------

namespace GameConstants
{
	constexpr int WIDTH = 672;
	constexpr int HEIGHT = 768;
	constexpr int HALFW = WIDTH / 2;
	constexpr int HALFH = HEIGHT / 2;

	constexpr float TOP_BANNER = 96;
	constexpr float BOT_BANNER = 51;
	constexpr float LEFT_EDGE = 30;
	constexpr float RIGHT_EDGE = WIDTH - LEFT_EDGE;
}

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
#endif // !GameConstants_H