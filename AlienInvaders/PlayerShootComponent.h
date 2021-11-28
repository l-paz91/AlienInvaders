// -----------------------------------------------------------------------------
#ifndef PlayerShootComponent_H
#define PlayerShootComponent_H
// -----------------------------------------------------------------------------

/*
*
*	In Space Invaders, the player shooting uses the 2nd Game Object interrupt ID
*	The Y co-ordinate of the object depends which interrupt ID it can use
*
*/

//--INCLUDES--//
#include "Player.h"
#include "ShootComponent.h"

// -----------------------------------------------------------------------------

class PlayerShootComponent : public ShootComponent<Player>
{
public:
	PlayerShootComponent();

	virtual void update(Player& pPlayer, float pDeltaTime);
	virtual void render(sf::RenderWindow& pWindow);

	void setPosForShot(const Player& pPlayer);

	// on hit function
	// event hit alien, screen edge, saucer, barrier or alien shot

private:
	sf::Sprite mSprite;
	sf::Sprite mShotMissedSprite;

public:
	sf::RectangleShape mShotRect;

	float mElapsedTime;

	bool mShotsFired;
	bool mShotDestroyed;
	bool mDisplayShotSplat;
};

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
#endif // !PlayerShootComponent_H