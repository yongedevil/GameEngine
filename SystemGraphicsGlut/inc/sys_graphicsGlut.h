#ifndef _SYS_GRAPHICS_H
#define _SYS_GRAPHICS_H

#include <string>

#include "system.h"

namespace GameEngine
{
	class EntityManager;

	class Sys_Graphics : public System
	{
	public:
		Sys_Graphics();
		~Sys_Graphics();

		void startup();
		void shutdown();
		
		void reshape(int width, int height);
		void displayStart();
		void display(EntityManager * m_entManager);
		void displayEnd();

		int screenWidth() const { return m_screenWidth; }
		int screenHeight() const { return m_screenHeight; }

		float const* getCameraPos() const { return m_cameraPos; }
		void setCameraPos(float x, float y, float z) { m_cameraPos[0] = x; m_cameraPos[1] = y; m_cameraPos[2] = z; }


		void screenToWorld(int screenX, int screenY, float depthZ, float & worldX, float & worldY) const;

	protected:
		void update(float dt);
		

	private:
		int m_screenWidth;
		int m_screenHeight;
		float m_cameraWidth;
		float m_cameraHeight;

		float * m_cameraPos;
		float * m_cameraTarget;

		static const int DEFAULT_SCREENWIDTH;
		static const int DEFAULT_SCREENHEIGHT;

		static const float DEFAULT_CAMERAWIDTH;
		static const float DEFAULT_CAMERAHEIGHT;
	};
}

#endif