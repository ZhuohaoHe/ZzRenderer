#pragma once

#include "Light.hpp"

struct SharedUniform {
    glm::mat4 model;
    glm::mat4 lightSpaceMatrix;
    std::vector<std::shared_ptr<Light>> lights;
};

struct ShadowUniform {
    glm::mat4 model;
    glm::mat4 lightSpaceMatrix;
};

struct UboCamera {
    glm::mat4 view; // 64
    glm::mat4 projection; // 64
    glm::vec3 viewPos; // 16 (padding 4 to memory alignment)
};