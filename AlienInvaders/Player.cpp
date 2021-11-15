// -----------------------------------------------------------------------------

//--INCLUDES--//
#include "GameConstants.h"
#include "TextureManager.h"

// -----------------------------------------------------------------------------

#include "Player.h"

#include "std_lib_facilities.h"
using namespace sf;

// -----------------------------------------------------------------------------

namespace
{
	namespace PlayerPrivate
	{
		const string playerTextureFilename = "Graphics/PlayerSprite.png";
		
		// In SI, the player moves a pixel every screen refresh, so 60 times a second
		// therefore our player needs to move 3 pixels every second (as the width is 3x larger)
		// the players speed never changes
		constexpr float PLAYER_SPEED = 180;
	}
}


// -----------------------------------------------------------------------------

Player::Player()
	: mSprite(Sprite(TextureManager::getTexture(PlayerPrivate::playerTextureFilename)))
{
	using namespace GameConstants;

	mSprite.setOrigin(20, 0);
	mSprite.setPosition(HALFW, 651.0f);
}

// -----------------------------------------------------------------------------

void Player::update(const float& pDt)
{
	using namespace PlayerPrivate;
	using namespace GameConstants;

	const Vector2f& pos = mSprite.getPosition();

	// ---- HANDLE INPUT ---- //
	const bool left = Keyboard::isKeyPressed(Keyboard::Left);
	const bool a    = Keyboard::isKeyPressed(Keyboard::A);
	if (left || a)
	{
		if (!(pos.x <= LEFT_EDGE))
		{
			mSprite.move(-PLAYER_SPEED * pDt, 0);
		}
	}

	const bool right = Keyboard::isKeyPressed(Keyboard::Right);
	const bool d = Keyboard::isKeyPressed(Keyboard::D);
	if (right || d)
	{
		if (!(pos.x >= RIGHT_EDGE))
		{
			mSprite.move(PLAYER_SPEED * pDt, 0);
		}
	}
}

// -----------------------------------------------------------------------------

void Player::render(RenderWindow& pWindow)
{
	pWindow.draw(mSprite);
}

// -----------------------------------------------------------------------------



// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


