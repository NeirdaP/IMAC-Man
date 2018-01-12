#ifndef IMACGL_VERTEXBUFFER_HPP
#define IMACGL_VERTEXBUFFER_HPP


#include <GL/glew.h>

class VertexBuffer {
private:
    GLuint m_RendererID;

public:
    VertexBuffer(){};
    VertexBuffer(const void* data, GLuint size);
    ~VertexBuffer();

    void bind() const;
    void unbind() const;

    GLuint getM_RendererID() const;

    void setBuffer(const void* data, GLuint size);
};


#endif //IMACGL_VERTEXBUFFER_HPP
