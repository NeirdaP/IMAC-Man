#ifndef IMACGL_FREEFLYCAMERA_HPP
#define IMACGL_FREEFLYCAMERA_HPP

#include "glimac/glm.hpp"

class FreeFlyCamera {
private:
    //Position de la Caméra
    glm::vec3 m_Position;

    //Angle Horizontal
    float m_fPhi;

    //Angle Vertical
    float m_fTheta;

    //Vecteur "vers l'avant"
    glm::vec3 m_FrontVector;

    //Vecteur "vers la gauche"
    glm::vec3 m_LeftVector;

    //Vecteur "vers le haut"
    glm::vec3 m_UpVector;

    //Point vers lequel regarde la caméra
    glm::vec3 m_V = m_Position + m_FrontVector;


    //Calcule les vecteurs de direction à partir des angles Horizontaux et Verticaux
    void computeDirectionVectors(){
        m_FrontVector = glm::vec3 (cos(m_fTheta)*sin(m_fPhi), sin(m_fTheta), cos(m_fTheta)*cos(m_fPhi));
        m_LeftVector = glm::vec3 (sin(m_fPhi + (float) M_PI_2), 0, cos(m_fPhi + (float) M_PI_2));
        m_UpVector = glm::cross(m_FrontVector, m_LeftVector);
    }

public:
    //Constructeur
    FreeFlyCamera(){
        m_Position = glm::vec3 (0.0f, 0.0f, -2.0f);
        m_fPhi = (float) M_PI;
        m_fTheta = 0.0f;
        computeDirectionVectors();
    }

    void moveLeft(float t){
        m_Position += t*m_LeftVector;
        computeDirectionVectors();
    }

    void moveFront(float t){
        m_Position += t*m_FrontVector;
        computeDirectionVectors();
    }

    void rotateLeft(float degrees){
        m_fPhi += glm::radians(degrees);
        computeDirectionVectors();
    }

    void rotateUp(float degrees){
        m_fTheta += glm::radians(degrees);
        computeDirectionVectors();
    }

    glm::mat4 getViewMatrix() const {
        return glm::lookAt(m_Position, m_Position + m_FrontVector, m_UpVector);
    }

};


#endif //IMACGL_FREEFLYCAMERA_HPP
