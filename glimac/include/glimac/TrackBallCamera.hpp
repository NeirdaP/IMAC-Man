#ifndef IMACGL_TRACKBALLCAMERA_HPP
#define IMACGL_TRACKBALLCAMERA_HPP

#include <glimac/glm.hpp>

class TrackBallCamera {
private:
    float m_fDistance;
    float m_fAngleX;
    float m_fAngleY;

public:
    TrackBallCamera(){
        m_fDistance = 5;
        m_fAngleX = 0;
        m_fAngleY = 0;
    }
    void moveFront(float delta){
        m_fDistance -= delta;
    }

    void rotateLeft(float degrees){
        m_fAngleX += degrees;
    }
    void rotateUp(float degrees){
        m_fAngleY += degrees;
    }
    glm::mat4 getViewMatrix() const{
        glm::mat4 viewMatrix;
        viewMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -m_fDistance));
        viewMatrix = glm::rotate(viewMatrix, glm::radians(m_fAngleX), glm::vec3(1.0f, 0.0f, 0.0f));
        viewMatrix = glm::rotate(viewMatrix, glm::radians(m_fAngleY), glm::vec3(0.0f, 1.0f, 0.0f));

        return viewMatrix;
    }
};


#endif //IMACGL_TRACKBALLCAMERA_HPP
