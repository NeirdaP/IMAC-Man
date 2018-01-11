#ifndef IMACGL_VERTEXARRAYBUFFER_HPP
#define IMACGL_VERTEXARRAYBUFFER_HPP
#include "Renderer.hpp"
#include "glimac/common.hpp"

class VertexArrayBuffer {
private:
    GLuint m_RendererID;
    GLuint m_vertex_attr_position;
    GLuint m_vertex_attr_normal;
    GLuint m_vertex_attr_texture;

public:
    VertexArrayBuffer(GLuint vertex_attr_position = 1,
                      GLuint vertex_attr_normal = 2,
                      GLuint vertex_attr_texture = 3);
    ~VertexArrayBuffer();

    void bind();
    void unbind();

    void attribPointerPosition();
    void attribPointerNormal();
    void attribPointerTexture();

    GLuint getM_RendererID() const;
};


#endif //IMACGL_VERTEXARRAYBUFFER_HPP
