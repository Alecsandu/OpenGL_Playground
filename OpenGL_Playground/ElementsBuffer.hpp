#pragma once
#include <GL/glew.h>

#include <vector>

class IndexBuffer
{
public:
	IndexBuffer(std::vector<GLuint>& p_indices);
	~IndexBuffer();

	void Bind() const;
	void Unbind() const;
	void Delete();

private:
	/* Reference to the Element buffer object  */
	GLuint m_ebo_id;
};