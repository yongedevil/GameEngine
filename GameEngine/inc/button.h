#ifndef _BUTTON_H
#define _BUTTON_H

#include "component.h"
#include "typedeffex.h"

namespace GameEngine
{
	class Screen;

	class Button : public Component
	{
	public:
		Button();
		~Button();

		void init(Entity * owner, int x, int y, int width, int height, void (Screen:: * onClick)(void));
		void destroy();

		static ComponentType type() { return static_cast<ComponentType>(ComponentTypeEx::COMPONENT_BUTTON); }
		ComponentType getType() const { return static_cast<ComponentType>(ComponentTypeEx::COMPONENT_BUTTON); }

	protected:
		void update(float dt);
		void draw();

	private:
		int m_x;
		int m_y;
		int m_width;
		int m_height;

		void(Screen:: * m_onClick)(void);
	};
}

#endif