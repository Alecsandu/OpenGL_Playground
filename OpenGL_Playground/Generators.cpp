#include "Generators.hpp"

#include <iostream>
#include <random>
#include <cmath>

constexpr double pi = 3.14159265358979323846;

Generators::Generators()
{

}

Generators::~Generators()
{
}

std::vector<glm::vec3> Generators::generatePoint()
{
    std::vector<glm::vec3> varfuri;

    /* Initialize distributions */
    std::uniform_real_distribution<double> distribution1(-0.7, 0.7);
    std::uniform_real_distribution<double> distribution2(0.4, 0.7);
    std::uniform_real_distribution<double> distribution3(0.1, 0.5 * pi);

    /* Generate random circle center positions */
    double pos_x = distribution1(generator);
    double pos_y = distribution1(generator);
    double pos_z = distribution1(generator);
    glm::vec3 centre_point = { pos_x, pos_y, pos_z};   

    double radius = distribution2(generator);

    double angle = 0.0;
    for (int i = 0; i < 3; ++i)
    {
        angle += distribution3(generator);
        glm::vec3 circle_vector = {
            radius * std::cos(angle), 
            radius * sin(angle),
            0.0
        };

        glm::vec3 final_vector = { 
            centre_point.x + circle_vector.x,
            centre_point.y + circle_vector.y,
            0.0
        };

        varfuri.push_back(final_vector);
    }

    return varfuri;
}
