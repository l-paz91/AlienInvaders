// -----------------------------------------------------------------------------

//--INCLUDES--//
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>

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
	}
}


// -----------------------------------------------------------------------------

Player::Player()
	: mSprite(new Sprite(TextureManager::getTexture(PlayerPrivate::playerTextureFilename)))
	, mSpeed(3)
{
	using namespace GameGlobals;

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

void Player::updateInput(Event& pEvent)
{
	// use left and right arrow to move player
	if (pEvent.key.code == Keyboard::Left)
	{
		mSprite->move(-mSpeed, 0);
	}
	if (pEvent.key.code == Keyboard::Right)
	{
		mSprite->move(mSpeed, 0);
	}
}

// -----------------------------------------------------------------------------

void Player::update()
{

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


