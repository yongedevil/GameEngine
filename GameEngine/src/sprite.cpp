#include "sprite.h"

using namespace GameEngine;

Sprite::Sprite() : m_texture(NULL)
{
}

Sprite::~Sprite()
{
	delete m_texture;
}

void Sprite::init(Entity * owner, SpriteInfo const& info)
{
	Component::init(owner);

	m_offset = info.positionOffset;
	m_texture = new Texture2D(info.texture);
	m_frameWidth = info.frameWidth;
	m_frameHeight = info.frameHeight;
	m_frameCount = info.frameCount;
	m_frameTime = info.frameTime;

	m_animations = std::vector<AnimationInfo>();
	for (int i = 0; i < info.animationsCount; ++i)
	{
		m_animations.push_back(info.animations[i]);
	}
}

void Sprite::destory()
{
	Component::destroy();
}

void Sprite::update(float dt)
{
	m_timeElapsed += dt;

	if (m_timeElapsed > m_frameTime)
	{
		getNextFrame();
		m_timeElapsed = 0;
	}

}

void Sprite::draw()
{

}


void Sprite::getNextFrame()
{
	m_curFrame += m_dir;

	if (m_curFrame > m_animations[m_curAnimation].lastIndex)
	{
		m_curFrame = m_animations[m_curAnimation].firstIndex;
	}
	else if (m_curFrame < m_animations[m_curAnimation].firstIndex)
	{
		m_curFrame = m_animations[m_curAnimation].lastIndex;
	}
}

void Sprite::setAnimation(std::string const& animationName)
{
	bool found = false;
	for (int i = 0; !found && i < m_animations.size(); ++i)
	{
		if (animationName == m_animations[i].name)
		{
			found = true;
			setAnimation(i);
		}
	}
}
void Sprite::setAnimation(int index)
{
	if (index >= 0 && index < m_animations.size())
	{
		m_curAnimation = index;
		m_curFrame = m_dir >= 0 ? m_animations[m_curAnimation].firstIndex : m_animations[m_curAnimation].lastIndex;
	}
}