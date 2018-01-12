
#include <glimac/Sphere.hpp>
#include <iostream>
#include "../include/Model.hpp"

void Model::render(glm::mat4 viewMatrix) {
    vao.bind();
        glm::mat4 projMatrix = glm::perspective(glm::radians(70.f), 800.0f/600.0f, 0.1f, 300.f);
        glm::mat4 modelViewMatrix = viewMatrix * modelMatrix;
        glm::mat4 modelViewProjMatrix = projMatrix * modelViewMatrix;
        glm::mat4 normalMatrix = glm::transpose(glm::inverse(modelViewMatrix));

        glHandler->sendShaderUniformMatrix4f(glHandler->getUMVPMatrix(),modelViewProjMatrix);
        glHandler->sendShaderUniformMatrix4f(glHandler->getUMVMatrix(),modelViewMatrix);
        glHandler->sendShaderUniformMatrix4f(glHandler->getUNormalMatrix(),normalMatrix);
        drawVertices();
    vao.unbind();

}

void Model::drawVertices() {
//    glDrawElements(GL_TRIANGLES, basicMesh.getVertexCount(), GL_UNSIGNED_INT, 0);
    glDrawArrays(GL_TRIANGLES, 0, basicMesh.getVertexCount());
}

Model::Model()
{
    basicMesh.build(1,32,16);
    vbo.setBuffer(basicMesh.getDataPointer(), (GLuint) basicMesh.getVertexCount());
    vao = VertexArrayBuffer();
    setModelMatrix();
    glHandler = &OpenGLHandler::getInstance();
}

const glm::mat4 &Model::getModelMatrix() const {
    return modelMatrix;
}

void Model::setModelMatrix(const glm::mat4 &modelMatrix) {
    Model::modelMatrix = modelMatrix;
}
