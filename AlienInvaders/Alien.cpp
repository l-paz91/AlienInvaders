// -----------------------------------------------------------------------------

//--INCLUDES--//
#include "GameConstants.h"
#include "TextureManager.h"

#include "Alien.h"

#include "std_lib_facilities.h"

// -----------------------------------------------------------------------------

namespace
{
	namespace AlienPrivate
	{
		const string alienSpritesheet = "Graphics/AlienSpriteSheet.png";
		const sf::IntRect octopus1 = sf::IntRect(0, 0, 36, 24);
		const sf::IntRect octopus2 = sf::IntRect(36, 0, 36, 24);

		const sf::IntRect crab1 = sf::IntRect(0, 24, 32, 24);
		const sf::IntRect crab2 = sf::IntRect(36, 24, 32, 24);

		const sf::IntRect squid1 = sf::IntRect(0, 48, 24, 24);
		const sf::IntRect squid2 = sf::IntRect(36, 48, 24, 24);

		const sf::IntRect destroyed = sf::IntRect(0, 72, 32, 24);

		const int RIGHT_EDGE = 117;
	}
}

// -----------------------------------------------------------------------------

Invader::Invader()
	: mSprite(Sprite(TextureManager::getTexture(AlienPrivate::alienSpritesheet)))
	, mType(AlienType::eOCTOPUS)
	, mDisplay(true)
	, mStep(true)
{

}

// -----------------------------------------------------------------------------

void Invader::animate()
{
	using namespace AlienPrivate;

	switch (mType)
	{
	case AlienType::eOCTOPUS:
		if(mStep)
			mSprite.setTextureRect(octopus2);
		else
			mSprite.setTextureRect(octopus1);
		break;
	case AlienType::eCRAB:
		if (mStep)
			mSprite.setTextureRect(crab2);
		else
			mSprite.setTextureRect(crab1);
		break;
	case AlienType::eSQUID:
		if (mStep)
			mSprite.setTextureRect(squid2);
		else
			mSprite.setTextureRect(squid1);
		break;
	default:
		break;
	}
}

// -----------------------------------------------------------------------------

Alien::Alien()
	: mSpeed(6.0f)
{
	init();
}

// -----------------------------------------------------------------------------

void Alien::init()
{
	Vector2f startPos = Vector2f(GameConstants::LEFT_EDGE, 474);
	float x = 75.0f;
	float y = 426.0f;

	using namespace AlienPrivate;

	if (!mAliens.empty())
	{
		mAliens.clear();
	}
	mAliens.resize(55);
	
	for (uint32 i = 0; i < 22; ++i)
	{
		mAliens[i].mSprite.setTextureRect(octopus2);
		mAliens[i].mType = AlienType::eOCTOPUS;
	}

	for (uint32 i = 22; i < 44; ++i)
	{
		mAliens[i].mSprite.setTextureRect(crab2);
		mAliens[i].mType = AlienType::eCRAB;
	}

	for (uint32 i = 44; i < 55; ++i)
	{
		mAliens[i].mSprite.setTextureRect(squid2);
		mAliens[i].mType = AlienType::eSQUID;
	}

	// set positions
	for (uint32 i = 0; i < mAliens.size(); ++i)
	{
		// start a new row after 11 aliens
		if (i % 11 == 0)
		{
			y -= 48;
			x = 75.0f;
		}

		mAliens[i].mSprite.setPosition(Vector2f(x, y));
		x += 48;
	}
}

// -----------------------------------------------------------------------------

void Alien::update(const float& pDt)
{
	// the aliens move one after another in reference to the bottom left alien
	// in a wave style pattern, aliens move 2 (therefore 6) pixels each frame
	// all aliens must have moved in 55 frames (1 each)
	// this is why the aliens speed up as they are destroyed
	static int alienToUpdate = 0;
	Invader& alien = mAliens[alienToUpdate];

	// check to see if ref alien has hit an edge
	if (alienToUpdate == 0)
	{
		const float x = alien.mSprite.getPosition().x;
		if (x < GameConstants::LEFT_EDGE || x > AlienPrivate::RIGHT_EDGE)
		{
			// drop the aliens by 1 row
			for (Invader& i : mAliens)
			{
				i.mSprite.move(Vector2f(0, 48));
			}

			// set reverse speed
			mSpeed *= -1.0f;
		}
	}

	// move it over
	alien.mSprite.move(Vector2f(mSpeed, 0));
	alien.mStep = !alien.mStep;
	alien.animate();
	
	++alienToUpdate;
	if (alienToUpdate == mAliens.size())
	{
		alienToUpdate = 0;
	}
}

// -----------------------------------------------------------------------------

void Alien::render(sf::RenderWindow& pWindow)
{
	for (const Invader& i : mAliens)
	{
		if (i.mDisplay)
		{
			pWindow.draw(i.mSprite);
		}
	}
}

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


