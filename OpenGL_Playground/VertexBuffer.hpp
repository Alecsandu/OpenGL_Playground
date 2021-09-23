#pragma once
#include <GL/glew.h>
#include "glm.hpp"
#include <vector>

struct Vertex
{
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec3 color;
	glm::vec2 texUV;
};

class VertexBuffer
{
public:
	VertexBuffer(std::vector<Vertex>& vertices);//GLfloat* vertices, GLsizeiptr size);
	~VertexBuffer();

	unsigned int getBufferID() const;

	void Bind() const;
	void Unbind() const;
	void Delete();

private:
	unsigned int m_vbo_id;
};

