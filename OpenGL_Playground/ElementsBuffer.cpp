#include "ElementsBuffer.hpp"

IndexBuffer::IndexBuffer(std::vector<GLuint>& p_indices)
{
	glGenBuffers(1, &m_ebo_id);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo_id);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, p_indices.size() * sizeof(GLuint), p_indices.data(), GL_STATIC_DRAW);
}

IndexBuffer::~IndexBuffer()
{
}

void IndexBuffer::Bind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo_id);
}

void IndexBuffer::Unbind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void IndexBuffer::Delete()
{
	glDeleteBuffers(1, &m_ebo_id);
}