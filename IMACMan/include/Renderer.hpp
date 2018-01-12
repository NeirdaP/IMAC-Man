#ifndef IMACGL_RENDERER_HPP
#define IMACGL_RENDERER_HPP

#include <GL/glew.h>
#include <vector>
#include "Model.hpp"
#include "Camera.hpp"

class Renderer {
private:
    std::vector<Model*> models;
    Camera* m_camera;
public:
    Renderer(Camera *m_camera);

    ~Renderer() = default;
    void addModel(Model* model);
    void renderModels();

};


#endif //IMACGL_RENDERER_HPP
