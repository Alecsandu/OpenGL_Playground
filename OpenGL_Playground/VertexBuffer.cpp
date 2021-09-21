#include "VertexBuffer.hpp"

VertexBuffer::VertexBuffer(std::vector<glm::vec3>& vertices)
{
	glGenBuffers(1, &m_vbo_id);
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo_id);  // Bind the buffer in order to save the data in it
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), vertices.data(), GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0); 
}

VertexBuffer::~VertexBuffer()
{
}

unsigned int VertexBuffer::getBufferID() const
{
	return this->m_vbo_id;
}

void VertexBuffer::Bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo_id);
}

void VertexBuffer::Unbind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VertexBuffer::Delete()
{
	glDeleteBuffers(1, &m_vbo_id);
}
