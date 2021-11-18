// -----------------------------------------------------------------------------
#ifndef Player_H
#define Player_H
// -----------------------------------------------------------------------------

/*
* 
*	In the original Space Invaders a player is 13x8 pixels. 
*	Everything in this game is scaled by 3. This player is 39x24 pixels.
*	Origin is set in the top middle at (20, 0)
* 
*/

//--INCLUDES--//
#include <SFML/Graphics.hpp>

// Forward Declares


// -----------------------------------------------------------------------------

class Player
{
public:
	Player();

	void update(const float& pDt);				// update logic
	void render(sf::RenderWindow& pWindow);		// render the sprite to the window

	const sf::Sprite& getSprite() const { return mSprite; }

private:
	void move(const float& pDeltaTime);
	void shoot(const float& pDeltaTime);
	void loseLife();

	void setPosForShot();

	sf::Sprite mSprite;
	sf::Sprite mShotMissedSprite;
	sf::RectangleShape mShot;

	float mTimeSinceLastDisplayed;

	bool mShotsFired;
	bool mShotDestroyed;
	bool mDisplayShotSplat;

	float mElapsedTime;
};

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
#endif // !Player_H