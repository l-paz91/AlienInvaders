// -----------------------------------------------------------------------------

//--INCLUDES--//
#include "GameConstants.h"
#include "TextureManager.h"

#include <string>

#include "AlienShootComponent.h"
#include "std_lib_facilities.h"

// -----------------------------------------------------------------------------

namespace
{
	namespace AlienShootPrivate
	{
		constexpr int MAX_SHOTS = 3;
		constexpr int PPS_12 = 4;		// PPS - pixels per step
		constexpr int PPS_15 = 5;

		const sf::IntRect RollingFrame1 = sf::IntRect(0, 48, 8, 20);
		const sf::IntRect PlungerFrame1 = sf::IntRect(0, 24, 8, 20);
		const sf::IntRect ZigZagFrame1 = sf::IntRect(0, 0, 8, 20);

		const std::string spritesheet = "Graphics/AlienShotSpritesheet.png";
	}
}

// -----------------------------------------------------------------------------

AlienShot::AlienShot(ShotType pType)
	: mSprite(Sprite(TextureManager::getTexture(AlienShootPrivate::spritesheet)))
	, mSpeed(AlienShootPrivate::PPS_12)
	, mType(pType)
{
	// set the correct area of the spritesheet
	using namespace AlienShootPrivate;

	switch (pType)
	{
	case ShotType::eROLLING:
		mSprite.setTextureRect(RollingFrame1);
		break;
	case ShotType::ePLUNGER:
		mSprite.setTextureRect(PlungerFrame1);
		break;
	case ShotType::eSQUIGGLY:
		mSprite.setTextureRect(ZigZagFrame1);
		break;
	default:
		break;
	}
}

// -----------------------------------------------------------------------------

AlienShootComponent::AlienShootComponent()
	: mElapsedTime(0.0f)
	, mNumOfShots(0)
{

}

// -----------------------------------------------------------------------------

void AlienShootComponent::update(Invader& pInvader, float pDeltaTime)
{
	using namespace AlienShootPrivate;

	// a random alien will choose to shoot every second
	mElapsedTime += pDeltaTime;
	if (mElapsedTime >= 1 && mShots.size() < MAX_SHOTS)
	{
		int shouldShoot = randint(1);
		if (shouldShoot)
		{
			AlienShot shot = AlienShot(ShotType::eROLLING);
			shot.mSprite.setPosition(pInvader.mSprite.getPosition());
			mShots.push_back(shot);
		}
		mElapsedTime = 0;
	}

	// move the shot down the screen
	for (int i = mShots.size()-1; i >= 0; --i)
	{
		mShots[i].mSprite.move(Vector2f(0, AlienShootPrivate::PPS_12));

		if (mShots[i].mSprite.getPosition().y >= (GameConstants::HEIGHT - GameConstants::BOT_BANNER))
		{
			mShots.erase(mShots.begin() + i);
		}
	}
}

// -----------------------------------------------------------------------------

void AlienShootComponent::render(sf::RenderWindow& pWindow)
{
	for (const AlienShot& shot : mShots)
	{
		pWindow.draw(shot.mSprite);
	}
}

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------



