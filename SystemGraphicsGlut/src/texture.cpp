#include "texture.h"

#include <GL\freeglut.h>
#include <SOIL\SOIL.h>

using namespace GameEngine;

Texture2D::Texture2D()
{

}

Texture2D::~Texture2D()
{

}


void Texture2D::loadTexture(char * path)
{
	m_texture = SOIL_load_OGL_texture
		(
		path,
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
		);

	if (0 == m_texture)
	{
		printf("SOIL loading error: %s", SOIL_last_result());
	}
}
