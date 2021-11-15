// -----------------------------------------------------------------------------
#ifndef HUD_H
#define HUD_H
// -----------------------------------------------------------------------------

//--INCLUDES--//
#include <SFML/Graphics.hpp>

// Forward Declares

// -----------------------------------------------------------------------------

class HUD
{
public:
	HUD();

	void update();
	void render(sf::RenderWindow& pWindow);

private:
	void setTextUp(sf::Text& pText, const sf::Vector2f& pPos, const std::string& pMsg = "");

	sf::View mView;
	sf::Font mFont;

	// STATE PLAYING
	sf::Text mScoreP1text;
	sf::Text mScoreP2text;
	sf::Text mHiScoreText;
	sf::Text mLivesText;
	sf::Text mCreditText;

	sf::Text mScore1;
	sf::Text mScore2;
	sf::Text mHiScore;

	sf::RectangleShape mGreenBar;
	sf::Sprite mLifeSprite1;
	sf::Sprite mLifeSprite2;
};

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
#endif // !HUD_H