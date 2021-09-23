#pragma once
#include <Windows.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <string>

class WindowingSystem
{
public:
	WindowingSystem(const std::string& title, const std::string& icon_path, unsigned int width, unsigned int height);
	~WindowingSystem();

	int getScreenWidth() const;
	void setScreenWidth(int);

	int getScreenHeight() const;
	void setScreenHeight(int);

	GLFWwindow* getWindow() const;
	void setWindow(GLFWwindow&);

	void Delete();

private:
	int m_client_width;
	int m_client_height;
	std::string m_window_title;
	GLFWwindow* m_window;
};

