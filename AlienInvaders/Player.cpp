// -----------------------------------------------------------------------------

//--INCLUDES--//
#include "GameConstants.h"
#include "PlayerShootComponent.h"
#include "TextureManager.h"

#include <string>

// -----------------------------------------------------------------------------

#include "Player.h"

// -----------------------------------------------------------------------------

using namespace GameConstants;
using namespace sf;

// -----------------------------------------------------------------------------

namespace
{
	namespace PlayerPrivate
	{
		const std::string playerTextureFilename = "Graphics/PlayerSprite.png";
		
		// In SI, the player moves a pixel every screen refresh, so 60 times a second
		// therefore our player needs to move 3 pixels every second (as the width is 3x larger)
		// the players speed never changes
		constexpr float PLAYER_SPEED = 180;
	}
}

using namespace PlayerPrivate;

// -----------------------------------------------------------------------------

Player::Player()
	: mSprite(Sprite(TextureManager::getTexture(PlayerPrivate::playerTextureFilename)))
	, mShootComponent(new PlayerShootComponent())

{
	using namespace GameConstants;

	mSprite.setOrigin(20, 0);
	mSprite.setPosition(HALFW, 651.0f);
	
	mElapsedTime = 0.0f;
}

// -----------------------------------------------------------------------------

Player::~Player()
{
	delete mShootComponent;
}

// -----------------------------------------------------------------------------

void Player::update(const float& pDt)
{
	// ---- HANDLE INPUT ---- //
	move(pDt);

	// ---- UPDATE COMPONENTS ---- //
	mShootComponent->update(*this, pDt);
}

// -----------------------------------------------------------------------------

void Player::render(RenderWindow& pWindow)
{
	pWindow.draw(mSprite);

	// ---- RENDER COMPONENTS ---- //
	mShootComponent->render(pWindow);
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

void Player::loseLife()
{
	// player has 3 lives

}

// -----------------------------------------------------------------------------



// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


