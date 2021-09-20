/* Third party libraries */
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "glm.hpp"

/* My classes */
#include "Controls.hpp"
#include "VertexArray.hpp"
#include "VertexBuffer.hpp"
#include "ShaderLoader.hpp"
#include "VertexBufferLayout.hpp"
#include "Texture.hpp"
#include "IndexBuffer.hpp"
#include "ObjectLoader.hpp"
#include "WindowingSystem.hpp"
#include "Generators.hpp"

/* Standard libs */
#include <errno.h>
#include <vector>

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

    glViewport(0, 0, 1920, 1080);

    Generators gen;

    std::vector<glm::vec3> varfuri = {
        glm::vec3(-0.5f, -0.5f * float(sqrt(3)) / 3,     0.0f),
        glm::vec3( 0.5f, -0.5f * float(sqrt(3)) / 3,     0.0f),
        glm::vec3( 0.0f,  0.5f * float(sqrt(3)) * 2 / 3, 0.0f)
    };

    std::cout << sizeof(varfuri) << " " << sizeof(GLfloat) << " " << sizeof(glm::vec3) << " " << varfuri.size();
    ShaderLoader sh("vertex_shader.vert", "fragment_shader.frag");

    VertexArray va(1);
    va.Bind();
    VertexBuffer vb(varfuri.data(), sizeof(glm::vec3) * varfuri.size());
    vb.Bind();

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (void*)0);
    glEnableVertexAttribArray(0);

    vb.Unbind();
    va.Unbind();
    int nr = 0;
    sh.Bind();
    while (!glfwWindowShouldClose(ws.getWindow()))
    {
        nr++;
        glClearColor(0.0f, 0.13f, 0.17f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        vb.Bind();
        va.Bind();
        
        glDrawArrays(GL_TRIANGLES, 0, 3);

        if (nr == 250) {
            varfuri.clear();
            varfuri = gen.generatePoint();
            nr = 0;
        }

        glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * varfuri.size(), varfuri.data(), GL_STATIC_DRAW);

        va.Unbind();
        vb.Unbind();
        
        glfwSwapBuffers(ws.getWindow());
        glfwPollEvents();
    }

    glfwTerminate();
    va.Unbind();
    va.cleanup();
    vb.Unbind();
    vb.cleanup();
    sh.Unbind();
    sh.cleanup();
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