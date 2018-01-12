#include <gl/glew.h>
#include <GL/glut.h>
#include <glimac/FilePath.hpp>
#include <glimac/SDLWindowManager.hpp>
#include <glimac/Program.hpp>
#include <fstream>
#include <iostream>
#include "../include/OpenGLHandler.hpp"

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
    std::string FS = "shaders/3D.fs.glsl";

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

    setUMVMatrix(getShaderUniformLocation("uMVMatrix"));
    setUMVPMatrix(getShaderUniformLocation("uMVPMatrix"));
    setUNormalMatrix(getShaderUniformLocation("uNormalMatrix"));

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

void OpenGLHandler::sendShaderUniform3f(GLint targetedVectorID, glm::vec3 vec) {
    glUniform3f(targetedVectorID, vec.x, vec.y, vec.z);
}

void OpenGLHandler::sendShaderUniform1f(GLint targetedFloatID, float value) {
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

GLint OpenGLHandler::getUMVPMatrix() const {
    return uMVPMatrix;
}

void OpenGLHandler::setUMVPMatrix(GLint uMVPMatrix) {
    OpenGLHandler::uMVPMatrix = uMVPMatrix;
}

GLint OpenGLHandler::getUMVMatrix() const {
    return uMVMatrix;
}

void OpenGLHandler::setUMVMatrix(GLint uMVMatrix) {
    OpenGLHandler::uMVMatrix = uMVMatrix;
}

GLint OpenGLHandler::getUNormalMatrix() const {
    return uNormalMatrix;
}

void OpenGLHandler::setUNormalMatrix(GLint uNormalMatrix) {
    OpenGLHandler::uNormalMatrix = uNormalMatrix;
}

GLint OpenGLHandler::getUKd() const {
    return uKd;
}

void OpenGLHandler::setUKd(GLint uKd) {
    OpenGLHandler::uKd = uKd;
}

GLint OpenGLHandler::getUKs() const {
    return uKs;
}

void OpenGLHandler::setUKs(GLint uKs) {
    OpenGLHandler::uKs = uKs;
}

GLint OpenGLHandler::getUShininess() const {
    return uShininess;
}

void OpenGLHandler::setUShininess(GLint uShininess) {
    OpenGLHandler::uShininess = uShininess;
}

GLint OpenGLHandler::getULightPos_vs() const {
    return uLightPos_vs;
}

void OpenGLHandler::setULightPos_vs(GLint uLightPos_vs) {
    OpenGLHandler::uLightPos_vs = uLightPos_vs;
}

GLint OpenGLHandler::getULightIntensity() const {
    return uLightIntensity;
}

void OpenGLHandler::setULightIntensity(GLint uLightIntensity) {
    OpenGLHandler::uLightIntensity = uLightIntensity;
}
