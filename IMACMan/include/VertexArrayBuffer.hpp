#ifndef IMACGL_VERTEXARRAYBUFFER_HPP
#define IMACGL_VERTEXARRAYBUFFER_HPP
#include "Renderer.hpp"
#include "glimac/common.hpp"

class VertexArrayBuffer {
private:
    GLuint m_RendererID;
    GLuint m_vertex_attr_position = 1;
    GLuint m_vertex_attr_normal = 2;
    GLuint m_vertex_attr_texture = 3;

public:
    VertexArrayBuffer();
    ~VertexArrayBuffer();

    void bind();
    void unbind();

    void attribPointerPosition();
    void attribPointerNormal();
    void attribPointerTexture();


    //Getters
    GLuint getM_RendererID() const;
    GLuint getM_vertex_attr_position() const;
    GLuint getM_vertex_attr_normal() const;
    GLuint getM_vertex_attr_texture() const;

    //Setters
    void setM_vertex_attr_position(GLuint m_vertex_attr_position);
    void setM_vertex_attr_normal(GLuint m_vertex_attr_normal);
    void setM_vertex_attr_texture(GLuint m_vertex_attr_texture);


};


#endif //IMACGL_VERTEXARRAYBUFFER_HPP
