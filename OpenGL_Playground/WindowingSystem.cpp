#include "WindowingSystem.hpp"

WindowingSystem::WindowingSystem(const std::string& title, const std::string& icon_path, unsigned int width, unsigned int height) : m_window_title(title)
{
	m_client_width = width;
	m_client_height = height;

	//glfwWindowHint(GLFW_DECORATED, 0);
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	m_window = glfwCreateWindow(m_client_width, m_client_height, title.c_str(), NULL, NULL);

	if (!m_window)
	{
		glfwTerminate();
		throw std::exception("The window failed to be created!\n");
	}

	/*if (icon_path != "")
	{
		GLFWimage icons[1] = {};
		icons[0].pixels = SOIL_load_image(icon_path.c_str(), &icons[0].width, &icons[0].height, 0, SOIL_LOAD_RGBA);
		glfwSetWindowIcon(m_window, 1, icons);
		SOIL_free_image_data(icons[0].pixels);
	}*/
}

WindowingSystem::~WindowingSystem()
{}

int WindowingSystem::getScreenWidth() const
{
	return this->m_client_width;
}

void WindowingSystem::setScreenWidth(int in_width)
{
	this->m_client_width = in_width;
}

int WindowingSystem::getScreenHeight() const
{
	return this->m_client_height;
}

void WindowingSystem::setScreenHeight(int in_height)
{
	this->m_client_height = in_height;
}

GLFWwindow* WindowingSystem::getWindow() const
{
	return this->m_window;
}

void WindowingSystem::setWindow(GLFWwindow& new_window)
{
	this->m_window = &new_window;
}

void WindowingSystem::Delete()
{
	glfwDestroyWindow(m_window);
}
