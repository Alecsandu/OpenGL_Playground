#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stb_image.h>

class Shader;

class Texture
{
public:
	Texture(const char* image, GLenum texType, GLenum slot, GLenum format, GLenum pixelType);
	~Texture();

	// Assigns a texture unit to a texture
	void texUnit(Shader& shader, const char* uniform, GLuint unit);

	void Bind() const;
	void Unbind() const;
	void Delete();

private:
	GLuint ID;
	GLenum type;
};