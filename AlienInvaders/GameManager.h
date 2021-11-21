// -----------------------------------------------------------------------------
#ifndef GameManager_H
#define GameManager_H
// -----------------------------------------------------------------------------

//--INCLUDES--//
#include <SFML/Graphics.hpp>

// Forward Declares
class Alien;
class Player;
class DebugHUD;
class HUD;

// -----------------------------------------------------------------------------

enum class Gamestate
{
	eTITLE, ePLAYING, eGAMEOVER
};

// -----------------------------------------------------------------------------

class GameManager
{
public:
	GameManager();
	~GameManager();

	void updateObjects(const float& pDeltaTime);
	void updateHUDs();

	void renderObjects(sf::RenderWindow& pWindow);
	void renderHUDs(sf::RenderWindow& pWindow);

private:
	Alien* mAliens;
	Player* mPlayer;

	HUD* mHUD;
	DebugHUD* mDebugHUD;

	Gamestate mGamestate;
};

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
#endif // !GameManager_H