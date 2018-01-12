
#ifndef IMACGL_OPENGLHANDLER_HPP
#define IMACGL_OPENGLHANDLER_HPP


class OpenGLHandler {
public:
    int start(const std::string &dirPath);
    static OpenGLHandler& getInstance()
    {
        static OpenGLHandler instance;
        return instance;
    }

    ~OpenGLHandler();

    glimac::Program *getProgram() const;

    void setProgram(glimac::Program *program);
private:
    OpenGLHandler();
    void sendShaderUniformMatrix4f(GLint targetedMatrixID, glm::mat4 matrix);
    void sendShaderUniform3f(GLint targetedVectorID, glm::vec3 vec);
    void sendShaderUniform1f(GLint targetedFloatID, float value);

    GLint getShaderUniformLocation(std::string);

    glimac::Program* program;
};


#endif //IMACGL_OPENGLHANDLER_HPP
