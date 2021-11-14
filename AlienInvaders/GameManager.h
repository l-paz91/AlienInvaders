// -----------------------------------------------------------------------------
#ifndef GameManager_H
#define GameManager_H
// -----------------------------------------------------------------------------

//--INCLUDES--//
#include <SFML/Graphics.hpp>

// Forward Declares
class Player;
class DebugHUD;

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
	Player* mPlayer;

	DebugHUD* mDebugHUD;

	Gamestate mGamestate;
};

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
#endif // !GameManager_H