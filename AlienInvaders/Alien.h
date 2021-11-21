// -----------------------------------------------------------------------------
#ifndef Alien_H
#define Alien_H
// -----------------------------------------------------------------------------

//--INCLUDES--//
#include <SFML/Graphics.hpp>

#include <vector>

// Forward Declares


// -----------------------------------------------------------------------------

enum class AlienType
{
	eOCTOPUS,	// large invader
	eCRAB,		// medium invader
	eSQUID		// small invader
};

// -----------------------------------------------------------------------------

struct Invader
{
	Invader();
	void animate();

	sf::Sprite mSprite;
	AlienType mType;
	bool mDisplay;
	bool mStep;		// flip between animations
};

// -----------------------------------------------------------------------------

class Alien
{
public:
	Alien();

	void init();
	void update(const float& pDt);				// update logic
	void render(sf::RenderWindow& pWindow);		// render the sprite to the window

private:
	void move(const float& pDeltaTime);
	void shoot(const float& pDeltaTime);

	std::vector<Invader> mAliens;
	float mSpeed;
};

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
#endif // !Alien_H