#include <gl/glew.h>
#include <GL/glut.h>
#include <glimac/FilePath.hpp>
#include <glimac/SDLWindowManager.hpp>
#include <glimac/Program.hpp>
#include <fstream>
#include <iostream>
#include "../include/OpenGLHandler.hpp"
#if __WINDOWS__
#include <windows.h>
#endif

int OpenGLHandler::start(const std::string &dirPath){
#if __APPLE__
    // Initialize glew for OpenGL3+ support
    GLenum glewInitError = glewInit();

    if(GLEW_OK != glewInitError) {
        std::cerr << glewGetErrorString(glewInitError) << std::endl;
        return EXIT_FAILURE;
    }

    glimac::FilePath applicationPath(dirPath);

    std::string VS = "shaders/3D.vs.glsl";
    std::string FS = "shaders/multiTex3D.fs.glsl";

    glimac::Program program = glimac::loadProgram(VS, FS);

#if __APPLE__
    setProgram(&program);
#else
    glimac::Program program = glimac::loadProgram(applicationPath.dirPath() + VS,
                                      applicationPath.dirPath() + FS);
#endif
    getProgram()->use();

    std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;
    glEnable(GL_DEPTH_TEST);
#endif
    return EXIT_SUCCESS;
}

OpenGLHandler::OpenGLHandler() {

}

OpenGLHandler::~OpenGLHandler() {

}

void OpenGLHandler::sendShaderUniformMatrix4f(GLint targetedMatrixID, glm::mat4 matrix) {
    glUniformMatrix4fv(targetedMatrixID, 1, GL_FALSE, glm::value_ptr(matrix));
}

void sendShaderUniform3f(GLint targetedVectorID, glm::vec3 vec) {
    glUniform3f(targetedVectorID, vec.x, vec.y, vec.z);
}

void sendShaderUniform1f(GLint targetedFloatID, float value) {
    glUniform1f(targetedFloatID, value);
}

GLint OpenGLHandler::getShaderUniformLocation(std::string name) {
    return glGetUniformLocation(getProgram()->getGLId(), name.c_str());
}

glimac::Program *OpenGLHandler::getProgram() const {
    return program;
}

void OpenGLHandler::setProgram(glimac::Program *program) {
    OpenGLHandler::program = program;
}
