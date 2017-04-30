#include "Cube.h"
#include "Scene.h"

Cube::Cube(float x, float y, float z)
{
	size(100);
	position(x, y, z);
	SetColour(1.f, 0.f, 0.f, 1.f);
	_usingTexture = false;
}


void Cube::Display()
{
	glPushMatrix();
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	glTranslatef(pos[0], pos[1], pos[2]);

	auto halfWidth = scale[0] / 2;
	auto halfHeight = scale[1] / 2;
	auto halfDepth = scale[2] / 2;

	if (_usingTexture) {
		glEnable(GL_TEXTURE_2D);
		glEnable(GL_COLOR_MATERIAL);
		glBindTexture(GL_TEXTURE_2D, _textureId);
		glColor4f(1.f, 1.f, 1.f, 1.f);
	}
	else
	{
		glDisable(GL_TEXTURE_2D);
		glColor4fv(_colour);
	}

	glBegin(GL_TRIANGLES);
	{
		// Front
		glNormal3f(0.f, 0.f, 1.f);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-halfWidth, -halfHeight, halfDepth);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(halfWidth, -halfHeight, halfDepth);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-halfWidth, halfHeight, halfDepth);

		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(halfWidth, -halfHeight, halfDepth);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(halfWidth, halfHeight, halfDepth);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-halfWidth, halfHeight, halfDepth);

		// Right
		glNormal3f(1.f, 0.f, 0.f);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(halfWidth, -halfHeight, halfDepth);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(halfWidth, -halfHeight, -halfDepth);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(halfWidth, halfHeight, halfDepth);

		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(halfWidth, -halfHeight, -halfDepth);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(halfWidth, halfHeight, -halfDepth);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(halfWidth, halfHeight, halfDepth);

		// Back
		glNormal3f(0.f, 0.f, -1.f);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(halfWidth, -halfHeight, -halfDepth);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(-halfWidth, -halfHeight, -halfDepth);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(halfWidth, halfHeight, -halfDepth);

		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(-halfWidth, -halfHeight, -halfDepth);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(-halfWidth, halfHeight, -halfDepth);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(halfWidth, halfHeight, -halfDepth);

		// Left
		glNormal3f(-1.f, 0.f, 0.f);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-halfWidth, -halfHeight, -halfDepth);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(-halfWidth, -halfHeight, halfDepth);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-halfWidth, halfHeight, -halfDepth);

		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(-halfWidth, -halfHeight, halfDepth);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(-halfWidth, halfHeight, halfDepth);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-halfWidth, halfHeight, -halfDepth);

		// Top
		glNormal3f(0.f, 1.f, 0.f);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-halfWidth, halfHeight, halfDepth);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(halfWidth, halfHeight, halfDepth);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-halfWidth, halfHeight, -halfDepth);

		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(halfWidth, halfHeight, halfDepth);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(halfWidth, halfHeight, -halfDepth);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-halfWidth, halfHeight, -halfDepth);

		// Bottom
		glNormal3f(0.f, -1.f, 0.f);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-halfWidth, -halfHeight, -halfDepth);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(halfWidth, -halfHeight, -halfDepth);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(halfWidth, -halfHeight, halfDepth);

		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(halfWidth, -halfHeight, halfDepth);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(-halfWidth, -halfHeight, halfDepth);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-halfWidth, -halfHeight, -halfDepth);

	}
	glEnd();
	glPopAttrib();
	glPopMatrix();
}

void Cube::SetTexture(std::string texturePath)
{
	_textureId = Scene::GetTexture(texturePath);
	auto textureNotLoaded = _textureId < 0;
	
	if (textureNotLoaded)
	{
		_textureId = -1;
		_usingTexture = false;
		return;
	}

	_usingTexture = true;
}

void Cube::SetColour(float r, float g, float b, float a)
{
	_colour[0] = r;
	_colour[1] = g;
	_colour[2] = b;
	_colour[3] = a;
}
