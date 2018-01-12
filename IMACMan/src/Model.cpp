
#include <glimac/Sphere.hpp>
#include "../include/Model.hpp"

void Model::render(glm::mat4 viewMatrix) {
    glm::mat4 projMatrix = glm::perspective(glm::radians(70.f), 800.0f/600.0f, 0.1f, 300.f);
    glm::mat4 modelViewMatrix = viewMatrix * modelMatrix;
    glm::mat4 modelViewProjMatrix = projMatrix * modelViewMatrix;
    glm::mat4 normalMatrix = glm::transpose(glm::inverse(modelViewMatrix));

    vao.bind();
    drawVertices();
    vao.unbind();


}

void Model::drawVertices() {
    glDrawElements(GL_TRIANGLES, basicMesh.getVertexCount(), GL_UNSIGNED_INT, 0);
}

Model::Model()
{
    basicMesh.build(1,32,16);
    vbo.setBuffer(basicMesh.getDataPointer(), (GLuint) basicMesh.getVertexCount());
    vao = VertexArrayBuffer();
}
