#include "VertexArray.hpp"

#include "VertexBuffer.hpp"

#include <iostream>

VertexArray::VertexArray()
{
	glGenVertexArrays(1, &m_vertex_array_id);
}

VertexArray::~VertexArray()
{
}

void VertexArray::linkAttrib(VertexBuffer& vbo, GLuint layout, GLuint numComponents, GLenum type, GLsizei stride, void* offset)
{
	vbo.Bind();
	glVertexAttribPointer(layout, numComponents, type, GL_FALSE, stride, offset);
	glEnableVertexAttribArray(layout);
	vbo.Unbind();
}

unsigned int VertexArray::getVertexArrayId() const
{
	return this->m_vertex_array_id;
}

void VertexArray::Bind() const
{
	glBindVertexArray(m_vertex_array_id);
}

void VertexArray::Unbind() const
{
	glBindVertexArray(0);
}

void VertexArray::Delete()
{
	glDeleteVertexArrays(1, &m_vertex_array_id);
}
