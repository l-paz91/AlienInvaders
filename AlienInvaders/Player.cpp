// -----------------------------------------------------------------------------

//--INCLUDES--//
#include "GameConstants.h"
#include "SoundManager.h"
#include "TextureManager.h"

// -----------------------------------------------------------------------------

#include "Player.h"

#include "std_lib_facilities.h"

// -----------------------------------------------------------------------------

using namespace GameConstants;
using namespace sf;

// -----------------------------------------------------------------------------

namespace
{
	namespace PlayerPrivate
	{
		const string playerTextureFilename = "Graphics/PlayerSprite.png";
		const string shotMissedFilename = "Graphics/ShotSplat.png";
		
		// In SI, the player moves a pixel every screen refresh, so 60 times a second
		// therefore our player needs to move 3 pixels every second (as the width is 3x larger)
		// the players speed never changes
		constexpr float PLAYER_SPEED = 180;
		constexpr float SHOT_SPLAT_DELAY = 0.4f;
	}
}

using namespace PlayerPrivate;

// -----------------------------------------------------------------------------

Player::Player()
	: mSprite(Sprite(TextureManager::getTexture(PlayerPrivate::playerTextureFilename)))
	, mShotMissedSprite(Sprite(TextureManager::getTexture(PlayerPrivate::shotMissedFilename)))
{
	using namespace GameConstants;

	mSprite.setOrigin(20, 0);
	mSprite.setPosition(HALFW, 651.0f);

	mShotMissedSprite.setOrigin(10, 0);

	// set up the shot
	mShot.setSize(Vector2f(3.0f, 12.0f));
	mShot.setFillColor(Color(82, 252, 82));
	setPosForShot();

	mShotsFired = false;
	mShotDestroyed = true;
	mDisplayShotSplat = false;
	
	mElapsedTime = 0.0f;
}

// -----------------------------------------------------------------------------

void Player::update(const float& pDt)
{
	// ---- HANDLE INPUT ---- //
	move(pDt);
	shoot(pDt);
}

// -----------------------------------------------------------------------------

void Player::render(RenderWindow& pWindow)
{
	pWindow.draw(mSprite);

	if (!mShotDestroyed)
	{
		pWindow.draw(mShot);
	}

	if (mDisplayShotSplat && mElapsedTime <= PlayerPrivate::SHOT_SPLAT_DELAY)
	{
		pWindow.draw(mShotMissedSprite);
	}

}

// -----------------------------------------------------------------------------


void Player::move(const float& pDeltaTime)
{
	// player can only move on X axis
	const Vector2f& pos = mSprite.getPosition();

	const bool left = Keyboard::isKeyPressed(Keyboard::Left);
	const bool a = Keyboard::isKeyPressed(Keyboard::A);
	if (left || a)
	{
		if (!(pos.x <= LEFT_EDGE))
		{
			mSprite.move(-PLAYER_SPEED * pDeltaTime, 0);
		}
	}

	const bool right = Keyboard::isKeyPressed(Keyboard::Right);
	const bool d = Keyboard::isKeyPressed(Keyboard::D);
	if (right || d)
	{
		if (!(pos.x >= RIGHT_EDGE))
		{
			mSprite.move(PLAYER_SPEED * pDeltaTime, 0);
		}
	}
}

// -----------------------------------------------------------------------------

void Player::shoot(const float& pDeltaTime)
{
	// handle shooting
	// only 1 shot from the player is allowed on the screen at any one time
	const bool mouseLeft = Mouse::isButtonPressed(Mouse::Left);
	const bool s = Keyboard::isKeyPressed(Keyboard::S);
	if (mouseLeft || s)
	{
		if (!mShotsFired)
		{
			setPosForShot();
			mShotsFired = true;
			mShotDestroyed = false;

			// play the sound
			SoundManager::playSound(SoundEvent::ePLAYER_FIRE);
		}
	}

	// update shot
	if (!mShotDestroyed)
	{
		mShot.move(0, -(720 * pDeltaTime));
		if (mShot.getPosition().y <= 576)
		{
			mShot.setFillColor(Color::White);
		}

		// if it hits the top banner - destroy it
		if (mShot.getPosition().y <= TOP_BANNER)
		{
			mElapsedTime = 0.0f;
			mShotMissedSprite.setPosition(Vector2f(mShot.getPosition().x, GameConstants::TOP_BANNER));
			mDisplayShotSplat = true;
			mShotDestroyed = true;
			mShotsFired = false;
			mShot.setFillColor(Color(82, 252, 82));
		}
	}

	if (mDisplayShotSplat && mShotDestroyed)
	{
		mElapsedTime += pDeltaTime;
	}
}

// -----------------------------------------------------------------------------

void Player::loseLife()
{
	// player has 3 lives

}

// -----------------------------------------------------------------------------

void Player::setPosForShot()
{
	// ensure shot always spawns direct top-centre of the player
	const float x = mSprite.getPosition().x - 2.0f;
	const float y = mSprite.getPosition().y - 12.0f;
	mShot.setPosition(Vector2f(x, y));
}

// -----------------------------------------------------------------------------



// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


