#include "screen.h"

using namespace GameEngine;

Screen::Screen()
{

}

Screen::~Screen()
{
}

Button * Screen::addButton(int x, int y, int width, int height, void (Screen:: * onClick)(void))
{
	Button * button = Entity::addComponent<Button>();

	if(button)
	{
		button->init(this, x, y, width, height, onClick);
	}

	return button;
}