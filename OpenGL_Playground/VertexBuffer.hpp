#pragma once
#include <GL/glew.h>
#include "glm.hpp"
#include <vector>

class VertexBuffer
{
public:
	VertexBuffer(std::vector<glm::vec3>& vertices);//GLfloat* vertices, GLsizeiptr size);
	~VertexBuffer();

	unsigned int getBufferID() const;

	void Bind() const;
	void Unbind() const;
	void Delete();

private:
	unsigned int m_vbo_id;
};

