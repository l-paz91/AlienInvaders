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

struct DestroyedEvent
{
	DestroyedEvent() : mSprite(), mElapsedTime(0.0f) {}

	sf::Sprite mSprite;
	float mElapsedTime;
};

// -----------------------------------------------------------------------------

class Alien
{
public:
	Alien();

	void init();
	void update(const float& pDt);				// update logic
	void render(sf::RenderWindow& pWindow);		// render the sprite to the window
	void alienDestroyedEvent(const Invader& pInvader);

	std::vector<Invader> mAliens;
	std::vector<DestroyedEvent> mDestroyedSprites;

	float mSpeed;
	int mAlienToUpdate;
	int mAliensHit;

private:
	void move(const float& pDeltaTime);
	void shoot(const float& pDeltaTime);
};

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
#endif // !Alien_H