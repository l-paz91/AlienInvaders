// -----------------------------------------------------------------------------

//--INCLUDES--//
#include "GameConstants.h"
#include "SoundManager.h"
#include "TextureManager.h"

#include <string>

#include "PlayerShootComponent.h"

// -----------------------------------------------------------------------------

namespace
{
	namespace PlayerShootPrivate
	{
		const std::string shotMissedFilename = "Graphics/ShotSplat.png";

		constexpr float SHOT_MISSED_DELAY = 0.4f;
	}
}

// -----------------------------------------------------------------------------

PlayerShootComponent::PlayerShootComponent()
	: mSprite()
	, mShotMissedSprite(sf::Sprite(TextureManager::getTexture(PlayerShootPrivate::shotMissedFilename)))
{
	mShotMissedSprite.setOrigin(10, 0);

	// set up the shot
	mShotRect.setSize(Vector2f(3.0f, 12.0f));
	mShotRect.setFillColor(Color(82, 252, 82));

	mShotsFired = false;
	mShotDestroyed = true;
	mDisplayShotSplat = false;

	mElapsedTime = 0.0f;
}

// -----------------------------------------------------------------------------

void PlayerShootComponent::update(Player& pPlayer, float pDeltaTime)
{
	using namespace sf;
	using namespace GameConstants;

	// handle shooting
	// only 1 shot from the player is allowed on the screen at any one time
	const bool s = Keyboard::isKeyPressed(Keyboard::S);
	if (s)
	{
		if (!mShotsFired)
		{
			setPosForShot(pPlayer);
			mShotsFired = true;
			mShotDestroyed = false;

			// play firing sound
			SoundManager::playSound(SoundEvent::ePLAYER_FIRE);
		}
	}

	// update shot
	if (!mShotDestroyed)
	{
		mShotRect.move(0, -(720 * pDeltaTime));

		// shot turns white when it reaches middle portion of the screen
		if (mShotRect.getPosition().y <= 576)
		{
			mShotRect.setFillColor(Color::White);
		}

		// shot turns red when it reaches top portion of the screen
		if (mShotRect.getPosition().y <= 200)
		{
			mShotRect.setFillColor(Color::Red);
		}

		// if it hits the top banner - destroy it
		if (mShotRect.getPosition().y <= TOP_BANNER)
		{
			mElapsedTime = 0.0f;
			mShotMissedSprite.setPosition(Vector2f(mShotRect.getPosition().x, GameConstants::TOP_BANNER));
			mDisplayShotSplat = true;
			mShotDestroyed = true;
			mShotsFired = false;
			mShotRect.setFillColor(Color(82, 252, 82));
		}
	}

	if (mDisplayShotSplat && mShotDestroyed)
	{
		mElapsedTime += pDeltaTime;
	}
}

// -----------------------------------------------------------------------------

void PlayerShootComponent::render(sf::RenderWindow& pWindow)
{
	if (!mShotDestroyed)
	{
		pWindow.draw(mShotRect);
	}

	if (mDisplayShotSplat && mElapsedTime <= PlayerShootPrivate::SHOT_MISSED_DELAY)
	{
		pWindow.draw(mShotMissedSprite);
	}
}

// -----------------------------------------------------------------------------

void PlayerShootComponent::setPosForShot(const Player& pPlayer)
{
	// ensure shot always spawns direct top-centre of the player
	const float x = pPlayer.getSprite().getPosition().x - 2.0f;
	const float y = pPlayer.getSprite().getPosition().y - 12.0f;
	mShotRect.setPosition(sf::Vector2f(x, y));
}

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


