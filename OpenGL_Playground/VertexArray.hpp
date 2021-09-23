#pragma once
#include <GL/glew.h>

class VertexBuffer;

class VertexArray
{
public:
	VertexArray();
	~VertexArray();

	void linkAttrib(VertexBuffer& vbo, GLuint layout, GLuint numComponents, GLenum type, GLsizei stride, void* offset);

	void Bind() const;
	void Unbind() const;
	void Delete();

	unsigned int getVertexArrayId() const;

private:
	unsigned int m_vertex_array_id;
};