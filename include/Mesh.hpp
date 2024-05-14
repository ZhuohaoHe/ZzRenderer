#pragma once

#include <vector>
#include <glm/glm.hpp>
#include <memory>

#include "IndexBuffer.hpp"
#include "VertexArray.hpp"

#include "Material.hpp"

struct Vertex{
    glm::vec3 Position;
    glm::vec2 TexCoords;
    glm::vec3 Normal;
    // glm::vec3 Tangent;
    // glm::vec3 Bitangent;
};

class Mesh {
public:
    Mesh() = default;
    Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::shared_ptr<Material> material);
    virtual ~Mesh();

    virtual void render();

protected:
    VertexArray *m_VAO;
    VertexBuffer *m_VBO;
    IndexBuffer *m_IBO;
    std::shared_ptr<Material> m_material;
};
