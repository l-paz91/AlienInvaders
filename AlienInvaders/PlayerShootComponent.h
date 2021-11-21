// -----------------------------------------------------------------------------
#ifndef PlayerShootComponent_H
#define PlayerShootComponent_H
// -----------------------------------------------------------------------------

//--INCLUDES--//
#include "Player.h"
#include "ShootComponent.h"

// -----------------------------------------------------------------------------

class PlayerShootComponent : public ShootComponent<Player>
{
public:
	PlayerShootComponent();

	virtual void update(Player& pPlayer, float pDeltaTime);
	virtual void render(sf::RenderWindow& pWindow);

private:
	void setPosForShot(const Player& pPlayer);

	sf::Sprite mSprite;
	sf::Sprite mShotMissedSprite;
	sf::RectangleShape mShotRect;

	float mElapsedTime;

	bool mShotsFired;
	bool mShotDestroyed;
	bool mDisplayShotSplat;
};

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
#endif // !PlayerShootComponent_H