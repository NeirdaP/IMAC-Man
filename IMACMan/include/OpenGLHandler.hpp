#ifndef IMACGL_OPENGLHANDLER_HPP
#define IMACGL_OPENGLHANDLER_HPP
#include <glimac/Program.hpp>

class OpenGLHandler {
private:
    OpenGLHandler();

    glimac::Program* program;

    GLint uMVPMatrix;
    GLint uMVMatrix;
    GLint uNormalMatrix;
    GLint uKd;
    GLint uKs;
    GLint uShininess;
    GLint uLightPos_vs;
    GLint uLightIntensity;

public:
    static OpenGLHandler& getInstance()
    {
        static OpenGLHandler instance;
        return instance;
    }
    ~OpenGLHandler();

    int start(const std::string &dirPath);

    glimac::Program *getProgram() const;
    void setProgram(glimac::Program *program);

    void sendShaderUniformMatrix4f(GLint targetedMatrixID, glm::mat4 matrix);
    void sendShaderUniform3f(GLint targetedVectorID, glm::vec3 vec);
    void sendShaderUniform1f(GLint targetedFloatID, float value);

    GLint getShaderUniformLocation(std::string);


    //Getters & Setters
    GLint getUMVPMatrix() const;

    void setUMVPMatrix(GLint uMVPMatrix);

    GLint getUMVMatrix() const;

    void setUMVMatrix(GLint uMVMatrix);

    GLint getUNormalMatrix() const;

    void setUNormalMatrix(GLint uNormalMatrix);

    GLint getUKd() const;

    void setUKd(GLint uKd);

    GLint getUKs() const;

    void setUKs(GLint uKs);

    GLint getUShininess() const;

    void setUShininess(GLint uShininess);

    GLint getULightPos_vs() const;

    void setULightPos_vs(GLint uLightPos_vs);

    GLint getULightIntensity() const;

    void setULightIntensity(GLint uLightIntensity);
};


#endif //IMACGL_OPENGLHANDLER_HPP
