// -----------------------------------------------------------------------------
#ifndef GameEvents_H
#define GameEvents_H
// -----------------------------------------------------------------------------

/*
*
*	Space Invaders has 5 game objects processed by interrupt routines.
*	(1) Player at the bottom of the screen
*   (2) The player's shot
*	(3) "Rolling" alien shot
*	(4) "Plunger" alien shot
*	(5) "Squiggly" alien shot OR Bonus Flying Saucer ship
* 
*/

//--INCLUDES--//


// -----------------------------------------------------------------------------

enum class GameEvents
{
	ePLAYER_HIT,
	ePLAYER_FIRE,
	eROLLING_ALIEN_SHOT,
	ePLUNGING_ALIEN_SHOT,
	eSQUIGGLY_ALIEN_SHOT,
	eFLYING_SAUCER,
};

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
#endif // !GameEvents_H