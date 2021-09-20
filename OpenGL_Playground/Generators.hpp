#pragma once

#include "glm.hpp"
#include <vector>
#include <random>
#include <cmath>

class Generators
{
public:
	Generators();
	~Generators();

	std::vector<glm::vec3> generatePoint();

private:
	std::default_random_engine generator;
};

