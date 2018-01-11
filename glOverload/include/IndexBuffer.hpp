#ifndef IMACGL_INDEXBUFFER_HPP
#define IMACGL_INDEXBUFFER_HPP
#include "Renderer.hpp"

class IndexBuffer {
    unsigned int m_RendererID;
    unsigned int m_Count;
public:
    IndexBuffer(const unsigned int* data, unsigned int count);
    ~IndexBuffer();

    void Bind() const;
    void Unbind() const;

    inline unsigned int GetCount() const { return m_Count;}
};


#endif //IMACGL_INDEXBUFFER_HPP
