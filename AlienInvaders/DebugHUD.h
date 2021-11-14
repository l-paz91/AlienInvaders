// -----------------------------------------------------------------------------
#ifndef DebugHUD_H
#define DebugHUD_H
// -----------------------------------------------------------------------------

//--INCLUDES--//

// Forward Declares
class sf::Font;
class sf::RenderWindow;
class sf::Text;
class sf::View;

// -----------------------------------------------------------------------------

class DebugHUD
{
public:
	DebugHUD();
	~DebugHUD();

	void update(std::stringstream& pSS);
	void render(sf::RenderWindow& pWindow);

private:
	sf::View* mView;

	sf::Font* mFont;
	sf::Text* mText;
};

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
#endif // !DebugHUD_H