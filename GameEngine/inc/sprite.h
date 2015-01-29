#ifndef _SPRITE_H
#define _SPRITE_H

#include <string>
#include <vector>

#include "component.h"
#include "texture.h"
#include "vector.h"

namespace GameEngine
{
	class Sprite : Component
	{
	public:
		struct AnimationInfo
		{
			std::string name;
			int firstIndex;
			int lastIndex;
		};
		
		struct SpriteInfo
		{
			Vector2f positionOffset;
			Texture2D texture;
			int frameWidth;
			int frameHeight;
			int frameCount;
			float frameTime;

			AnimationInfo * animations;
			int animationsCount;
		};

	public:
		Sprite();
		~Sprite();

		void init(Entity * owner, SpriteInfo const& info);
		void destory();

		static ComponentType type() { return ComponentType::COMPONENT_SPRITE; }
		ComponentType getType() const { return ComponentType::COMPONENT_SPRITE; }

		void setAnimation(std::string const& animationName);
		void setAnimation(int index);

	protected:
		void update(float dt);
		void draw();

		void getNextFrame();

	private:
		bool m_followOwner;
		Vector2f m_position;
		Vector2f m_offset;
		Vector2f m_rotationOrigin;

		Texture2D * m_texture;
		std::vector<AnimationInfo> m_animations;
		int m_curAnimation;

		int m_dir;
		Vector2f m_scale;
		float m_rotation;
		bool m_flipHorizontal;

		float m_frameTime;
		float m_timeElapsed;
		int m_frameCount;
		int m_curFrame;
		int m_frameWidth;
		int m_frameHeight;
		int m_numCol;
	};
}

#endif