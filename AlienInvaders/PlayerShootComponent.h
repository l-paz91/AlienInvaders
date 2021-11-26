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

	void setPosForShot(const Player& pPlayer);

private:
	sf::Sprite mSprite;
	sf::Sprite mShotMissedSprite;

public:
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