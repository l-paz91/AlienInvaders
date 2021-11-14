// -----------------------------------------------------------------------------

//--INCLUDES--//
#include <iostream>
#include <sstream>

#include "DebugHUD.h"
#include "Player.h"

#include "GameManager.h"

// -----------------------------------------------------------------------------

GameManager::GameManager()
	: mPlayer(new Player())
	, mDebugHUD(new DebugHUD())
	, mGamestate(Gamestate::eTITLE)
{

}

// -----------------------------------------------------------------------------

GameManager::~GameManager()
{
	delete mPlayer;
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
		mPlayer->update(pDeltaTime);
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
	switch (mGamestate)
	{
	case Gamestate::eTITLE:
	{
		break;
	}
	case Gamestate::ePLAYING:
	{
		std::stringstream ss;
		ss << "Player X: " << mPlayer->getSprite().getPosition().x;
		mDebugHUD->update(ss);
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



// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


