#ifndef _TEXTURE_H
#define _TEXTURE_H

#include <fstream>
#include <istream>


namespace GameEngine
{
	class Texture2D
	{
	public:
		Texture2D();
		~Texture2D();

		void loadTexture(char * path);

	private:
		unsigned int m_texture;

		int width;
		int height;
	};
}

#endif