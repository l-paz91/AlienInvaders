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


// Forward Declares
class sf::Event;
class sf::RenderWindow;
class sf::Sprite;

// -----------------------------------------------------------------------------

class Player
{
public:
	Player();
	~Player();

	void update(const float& pDt);				// update logic
	void render(sf::RenderWindow& pWindow);		// render the sprite to the window

private:
	sf::Sprite* mSprite;
};

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
#endif // !Player_H