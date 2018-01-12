#include "../include/VertexArrayBuffer.hpp"
#include "glimac/common.hpp"
VertexArrayBuffer::VertexArrayBuffer()
{
    glGenVertexArrays(1, &m_RendererID);
    glBindVertexArray(m_RendererID);
    glEnableVertexAttribArray(m_vertex_attr_position);
    glEnableVertexAttribArray(m_vertex_attr_normal);
    glEnableVertexAttribArray(m_vertex_attr_texture);
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

GLuint VertexArrayBuffer::getM_vertex_attr_position() const {
    return m_vertex_attr_position;
}

void VertexArrayBuffer::setM_vertex_attr_position(GLuint m_vertex_attr_position) {
    VertexArrayBuffer::m_vertex_attr_position = m_vertex_attr_position;
}

GLuint VertexArrayBuffer::getM_vertex_attr_normal() const {
    return m_vertex_attr_normal;
}

void VertexArrayBuffer::setM_vertex_attr_normal(GLuint m_vertex_attr_normal) {
    VertexArrayBuffer::m_vertex_attr_normal = m_vertex_attr_normal;
}

GLuint VertexArrayBuffer::getM_vertex_attr_texture() const {
    return m_vertex_attr_texture;
}

void VertexArrayBuffer::setM_vertex_attr_texture(GLuint m_vertex_attr_texture) {
    VertexArrayBuffer::m_vertex_attr_texture = m_vertex_attr_texture;
}
