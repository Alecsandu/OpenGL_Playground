/* Third party libraries */
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "glm.hpp"
#include <stb_image.h>

/* My classes */
#include "Controls.hpp"
#include "VertexArray.hpp"
#include "VertexBuffer.hpp"
#include "Shader.hpp"
#include "Texture.hpp"
#include "ElementsBuffer.hpp"
#include "ObjectLoader.hpp"
#include "WindowingSystem.hpp"
#include "Generators.hpp"

/* Standard libs */
#include <errno.h>
#include <vector>
#include<filesystem>
namespace fs = std::filesystem;

void app()
{
    if (!glfwInit())
        throw std::exception("Failed to initialize GLFW!");

    WindowingSystem ws("OpenGL Sandbox", "", 1920, 1080);
    glfwMakeContextCurrent(ws.getWindow());

    glewExperimental = true;  // necesar pentru glfw core profile
    if (glewInit() != GLEW_OK)
    {
        glfwTerminate();
        throw std::exception("Failed to initialize GLEW!");
    }

    std::vector<Vertex> varfuri = {
        Vertex { glm::vec3{-0.5f, -0.5f, 0.0f},   glm::vec3{0.0f, 0.0f, 0.0f},   glm::vec3{1.0f, 0.0f, 0.0f},	glm::vec2{0.0f, 0.0f} }, // Lower left corner
        Vertex { glm::vec3{-0.5f,  0.5f, 0.0f},   glm::vec3{0.0f, 0.0f, 0.0f},   glm::vec3{0.0f, 1.0f, 0.0f},	glm::vec2{0.0f, 1.0f} }, // Upper left corner
        Vertex { glm::vec3{ 0.5f,  0.5f, 0.0f},   glm::vec3{0.0f, 0.0f, 0.0f},   glm::vec3{0.0f, 0.0f, 1.0f},	glm::vec2{1.0f, 1.0f} }, // Upper right corner
        Vertex { glm::vec3{ 0.5f, -0.5f, 0.0f},   glm::vec3{0.0f, 0.0f, 0.0f},   glm::vec3{1.0f, 1.0f, 1.0f},	glm::vec2{1.0f, 0.0f} }  // Lower right corner
    };

    Shader sh("Shaders/vertex_shader.vert", "Shaders/fragment_shader.frag");
    Texture texture("Resources/pop_cat.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
    texture.texUnit(sh, "tex0", 0);

    VertexArray va;
    va.Bind();
    VertexBuffer vb(varfuri);
    vb.Bind();

    va.linkAttrib(vb, 0, 3, GL_FLOAT, sizeof(Vertex), (void*)(0));
    va.linkAttrib(vb, 1, 3, GL_FLOAT, sizeof(Vertex), (void*)(3 * sizeof(float)));
    va.linkAttrib(vb, 2, 3, GL_FLOAT, sizeof(Vertex), (void*)(6 * sizeof(float)));
    va.linkAttrib(vb, 3, 2, GL_FLOAT, sizeof(Vertex), (void*)(9 * sizeof(float)));

    vb.Unbind();
    va.Unbind();

    sh.Bind();
    while (!glfwWindowShouldClose(ws.getWindow()))
    {
        glClearColor(0.0f, 0.13f, 0.17f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        vb.Bind();
        va.Bind();
        texture.Bind();
        
        glDrawArrays(GL_TRIANGLE_FAN, 0, 4);

        texture.Unbind();
        va.Unbind();
        vb.Unbind();
        
        glfwSwapBuffers(ws.getWindow());
        glfwPollEvents();
    }

    ws.Delete();
    glfwTerminate();

    va.Unbind();
    va.Delete();
    vb.Unbind();
    vb.Delete();
    sh.Unbind();
    sh.Delete();
}

int main()
{
    try
    {
        app();
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what();
    }
    return EXIT_SUCCESS;
}