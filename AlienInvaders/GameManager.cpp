// -----------------------------------------------------------------------------

//--INCLUDES--//
#include <iostream>
#include <sstream>

#include "Alien.h"
#include "DebugHUD.h"
#include "HUD.h"
#include "Player.h"
#include "PlayerShootComponent.h"

#include "GameManager.h"

// -----------------------------------------------------------------------------

GameManager::GameManager()
	: mAliens(new Alien())
	, mPlayer(new Player())
	, mHUD(new HUD())
	, mDebugHUD(new DebugHUD())
	, mGamestate(Gamestate::eTITLE)
{

}

// -----------------------------------------------------------------------------

GameManager::~GameManager()
{
	delete mAliens;
	delete mPlayer;
	delete mHUD;
	delete mDebugHUD;
}

// -----------------------------------------------------------------------------

void GameManager::updateObjects(const float& pDeltaTime)
{
	switch (mGamestate)
	{
	case Gamestate::eTITLE:
	{
		mGamestate = Gamestate::ePLAYING;		// for now just go directly to gameplay
		break;
	}
	case Gamestate::ePLAYING:
	{
		mAliens->update(pDeltaTime);
		mPlayer->update(pDeltaTime);

		// check for collisions and send events out
		alienHit();
		break;
	}
	case Gamestate::eGAMEOVER:
	{
		break;
	}
	default:
		std::cout << "How did we get here? (GameManager::updateObjects switch default)" << std::endl;
		break;
	}
}

// -----------------------------------------------------------------------------

void GameManager::updateHUDs()
{
	mHUD->update();

	switch (mGamestate)
	{
	case Gamestate::eTITLE:
	{
		break;
	}
	case Gamestate::ePLAYING:
	{
		//std::stringstream ss;
		//ss << "Player X: " << mPlayer->getSprite().getPosition().x;
		//mDebugHUD->update(ss);
		break;
	}
	case Gamestate::eGAMEOVER:
	{	
		break;
	}
	default:
		std::cout << "How did we get here? (GameManager::updateHUDs switch default)" << std::endl;
		break;
	}

}

// -----------------------------------------------------------------------------

void GameManager::renderObjects(sf::RenderWindow& pWindow)
{
	switch (mGamestate)
	{
	case Gamestate::eTITLE:
	{
		break;
	}
	case Gamestate::ePLAYING:
	{
		mAliens->render(pWindow);
		mPlayer->render(pWindow);
		break;
	}
	case Gamestate::eGAMEOVER:
	{
		break;
	}
	default:
		std::cout << "How did we get here? (GameManager::renderObjects switch default)" << std::endl;
		break;
	}
}

// -----------------------------------------------------------------------------

void GameManager::renderHUDs(sf::RenderWindow& pWindow)
{
	mHUD->render(pWindow);

	switch (mGamestate)
	{
	case Gamestate::eTITLE:
	{
		break;
	}
	case Gamestate::ePLAYING:
	{
		mDebugHUD->render(pWindow);
		break;
	}
	case Gamestate::eGAMEOVER:
	{
		break;
	}
	default:
		std::cout << "How did we get here? (GameManager::renderHUDs switch default)" << std::endl;
		break;
	}
}

// -----------------------------------------------------------------------------

void GameManager::alienHit()
{
	for (Invader& i : mAliens->mAliens)
	{
		// ignore the collision if the alien has already been destroyed
		// we don't remove sprites from the vector - just hide them
		if (i.mDisplay && mPlayer->mShootComponent->mShotRect.getGlobalBounds().intersects(i.mSprite.getGlobalBounds()))
		{
			// alien hit, hide it and display destroyed sprite
			i.mDisplay = false;
			++mAliens->mAliensHit;
			mAliens->alienDestroyedEvent(i);

			// move the shot out of the way so it doesn't collide with other invaders
			mPlayer->mShootComponent->setPosForShot(*mPlayer);

			// remove the shot from the screen
			mPlayer->mShootComponent->mShotDestroyed = true;
			mPlayer->mShootComponent->mShotsFired = false;
			mPlayer->mShootComponent->mShotRect.setFillColor(sf::Color(82, 252, 82));
			return;
		}
	}

	return;
}

// -----------------------------------------------------------------------------



// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


