#ifndef _TILE_H
#define _TILE_H

#include "component.h"
#include "typedeff_miningGame.h"

namespace GAME3011_Assignment1
{
	class Tile : public GameEngine::Component
	{
	private:
		int m_value;

	public:
		Tile();

		void init(GameEngine::Entity * owner);
		void destroy();

		int getValue() const;
		int setValue(int value);
		
		static GameEngine::ComponentType type() { return static_cast<GameEngine::ComponentType>(ComponentType::COMPONENT_TILE); }
		GameEngine::ComponentType getType() const { return static_cast<GameEngine::ComponentType>(ComponentType::COMPONENT_TILE); }

	protected:
		void update(float dt);
		void draw(class Sys_Graphics * graphics);
	};
}

#endif