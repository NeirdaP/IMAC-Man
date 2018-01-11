#include "../include/VertexArrayBuffer.hpp"
#include "glimac/common.hpp"
VertexArrayBuffer::VertexArrayBuffer(GLuint vertex_attr_position,
                                     GLuint vertex_attr_normal,
                                     GLuint vertex_attr_texture)
    : m_vertex_attr_position(vertex_attr_position),
      m_vertex_attr_normal(vertex_attr_normal),
      m_vertex_attr_texture(vertex_attr_texture)
{
    glGenVertexArrays(1, &m_RendererID);
    glBindVertexArray(m_RendererID);
    glEnableVertexAttribArray(vertex_attr_position);
    glEnableVertexAttribArray(vertex_attr_normal);
    glEnableVertexAttribArray(vertex_attr_texture);

}

VertexArrayBuffer::~VertexArrayBuffer() {
    glDeleteVertexArrays(1, &m_RendererID);
}

void VertexArrayBuffer::bind() {
    glBindVertexArray(m_RendererID);
}

void VertexArrayBuffer::unbind() {
    glBindVertexArray(0);
}

GLuint VertexArrayBuffer::getM_RendererID() const {
    return m_RendererID;
}

void VertexArrayBuffer::attribPointerPosition() {
    glVertexAttribPointer(m_vertex_attr_position, 3, GL_FLOAT, GL_FALSE, sizeof(glimac::ShapeVertex), (const GLvoid*)offsetof(glimac::ShapeVertex, position));
}

void VertexArrayBuffer::attribPointerNormal() {
    glVertexAttribPointer(m_vertex_attr_normal, 3, GL_FLOAT, GL_FALSE, sizeof(glimac::ShapeVertex), (const GLvoid*)offsetof(glimac::ShapeVertex, normal));
}

void VertexArrayBuffer::attribPointerTexture() {
    glVertexAttribPointer(m_vertex_attr_texture, 2, GL_FLOAT, GL_FALSE, sizeof(glimac::ShapeVertex), (const GLvoid*)offsetof(glimac::ShapeVertex, texCoords));
}
