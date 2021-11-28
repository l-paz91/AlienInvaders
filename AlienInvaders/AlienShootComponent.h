// -----------------------------------------------------------------------------
#ifndef AlienShootComponent_H
#define AlienShootComponent_H
// -----------------------------------------------------------------------------

/*
*
*	In Space Invaders, aliens use 3 of the 5 game objects for firing
*	(3) "Rolling" Shot
*	(4) "Plunger" Shot
*	(5) "Squiggly" Shot
*	- Event 5 is shared with the Flying saucer. Only 1 can appear at a time.
*	- Only 1 shot is processed per interrupt (frame) and only 3 shots can be on screen at a time.
*	- Shots move down 4 pixels down per step.
*	- When there are < 8 aliens, the Y delta changes to 5 pixels per step.
*	- Aliens have a "reload rate" that increases as the game progresses.
*	- When there is 1 Alien left, Event 4 is disabled.
*/

//--INCLUDES--//
#include "Alien.h"

#include <vector>

// -----------------------------------------------------------------------------

enum class ShotType
{
	eROLLING,
	ePLUNGER,
	eSQUIGGLY
};

// -----------------------------------------------------------------------------

struct AlienShot
{
	AlienShot(ShotType pType);

	sf::Sprite mSprite;
	int mSpeed;
	ShotType mType;
};

// -----------------------------------------------------------------------------

class AlienShootComponent
{
public:
	AlienShootComponent();

	void update(Invader& pInvader, float pDeltaTime);
	void render(sf::RenderWindow& pWindow);

private:
	void setPosForShot(const Alien& pAlien);

	std::vector<AlienShot> mShots;

	float mElapsedTime;
	int mNumOfShots;
};

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
#endif // !AlienShootComponent_H