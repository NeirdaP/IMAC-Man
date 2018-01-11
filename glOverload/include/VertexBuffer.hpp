#ifndef IMACGL_VERTEXBUFFER_HPP
#define IMACGL_VERTEXBUFFER_HPP
#include "Renderer.hpp"

class VertexBuffer {
private:
    GLuint m_RendererID;

public:
    VertexBuffer(const void* data, GLuint size);
    ~VertexBuffer();

    void bind() const;
    void unbind() const;

    GLuint getM_RendererID() const;
};


#endif //IMACGL_VERTEXBUFFER_HPP
