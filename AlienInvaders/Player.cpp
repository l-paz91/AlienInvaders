// -----------------------------------------------------------------------------

//--INCLUDES--//
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Time.hpp>

#include "GameConstants.h"
#include "TextureManager.h"

// -----------------------------------------------------------------------------

#include "std_lib_facilities.h"
#include "Player.h"

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
	: mSprite(new Sprite(TextureManager::getTexture(PlayerPrivate::playerTextureFilename)))
{
	using namespace GameConstants;

	mSprite->setOrigin(20, 0);
	mSprite->setPosition(HALFW, HEIGHT - BOT_BANNER);
}

// -----------------------------------------------------------------------------

Player::~Player()
{
	if (mSprite)
	{
		delete mSprite;
	}
}

// -----------------------------------------------------------------------------

void Player::update(const float& pDt)
{
	using namespace PlayerPrivate;
	using namespace GameConstants;

	const Vector2f& pos = mSprite->getPosition();

	// ---- HANDLE INPUT ---- //
	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		if (!(pos.x <= LEFT_EDGE))
		{
			mSprite->move(-PLAYER_SPEED * pDt, 0);
		}
	}
	if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		if (!(pos.x >= RIGHT_EDGE))
		{
			mSprite->move(PLAYER_SPEED * pDt, 0);
		}
	}
}

// -----------------------------------------------------------------------------

void Player::render(RenderWindow& pWindow)
{
	pWindow.draw(*mSprite);
}

// -----------------------------------------------------------------------------



// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


