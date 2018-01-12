#ifndef IMACGL_MODEL_HPP
#define IMACGL_MODEL_HPP

#include "VertexBuffer.hpp"
#include "VertexArrayBuffer.hpp"
#include "glimac/glm.hpp"
#include "glimac/common.hpp"
#include "Sphere.hpp"
#include "OpenGLHandler.hpp"

class Model{
private:
    VertexBuffer vbo;
    VertexArrayBuffer vao;
    glm::mat4 modelMatrix;
    Sphere basicMesh;
    //TODO :: texture ?
    const glm::mat4 &getModelMatrix() const;
    void setModelMatrix(const glm::mat4 &modelMatrix = glm::mat4(1.0f));
    OpenGLHandler* glHandler;

public:
    Model();

    void render(glm::mat4 viewMatrix);
    void drawVertices();
    //getters
    //setters

};


#endif //IMACGL_MODEL_HPP