#include "button.h"

using namespace GameEngine;

Button::Button()
{

}

Button::~Button()
{
}

void Button::init(Entity * owner, int x, int y, int width, int height, void (Screen:: * onClick)(void))
{
	Component::init(owner);
}

void Button::destroy()
{
	Component::destroy();
}

void Button::update(float dt)
{
}

void Button::draw()
{

}