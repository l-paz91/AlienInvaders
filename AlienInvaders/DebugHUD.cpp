// -----------------------------------------------------------------------------

//--INCLUDES--//
#include <iostream>
#include <sstream>

#include "GameConstants.h"

#include "DebugHUD.h"

// -----------------------------------------------------------------------------

using namespace GameConstants;
using namespace sf;

// -----------------------------------------------------------------------------

DebugHUD::DebugHUD()
	: mView(View(FloatRect(0.0f, 0.0f, WIDTH, HEIGHT)))
	, mFont(Font())
	, mText(Text())
{
	if (!mFont.loadFromFile("Fonts/javatext.ttf"))
	{
		std::cout << "Error loading debug font." << std::endl;
	}

	// set the text up
	mText.setPosition(Vector2f(500, 200));
	mText.setFont(mFont);
	mText.setCharacterSize(12);
	mText.setFillColor(Color::Red);
}

// -----------------------------------------------------------------------------

void DebugHUD::update(std::stringstream& pSS)
{
	// update any text here
	std::string s = pSS.str();

	mText.setString(s);
}

// -----------------------------------------------------------------------------

void DebugHUD::render(RenderWindow& pWindow)
{
	// get the current view so we can set it back after
	View currentView = pWindow.getView();
	
	// set the view to the debug HUD
	pWindow.setView(mView);

	// now draw to the window
	pWindow.draw(mText);

	// set it back to the previous view
	pWindow.setView(currentView);
}

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


