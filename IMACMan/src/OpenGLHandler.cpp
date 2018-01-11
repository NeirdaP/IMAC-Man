#include <gl/glew.h>
#include <GL/glut.h>
#include <glimac/FilePath.hpp>
#include <glimac/SDLWindowManager.hpp>
#include <glimac/Program.hpp>
#include <fstream>
#include <iostream>
#include "../include/OpenGLHandler.hpp"

int OpenGLHandler::start(const std::string &dirPath){
    // Initialize glew for OpenGL3+ support
    GLenum glewInitError = glewInit();

    if(GLEW_OK != glewInitError) {
        std::cerr << glewGetErrorString(glewInitError) << std::endl;
        return EXIT_FAILURE;
    }

    glimac::FilePath applicationPath(dirPath);

    std::string VS = "shaders/3D.vs.glsl";
    std::string FS = "shaders/multiTex3D.fs.glsl";

#if __APPLE__
    glimac::Program program = glimac::loadProgram(VS, FS);
#else
    glimac::Program program = glimac::loadProgram(applicationPath.dirPath() + VS,
                                      applicationPath.dirPath() + FS);
#endif
    program.use();

    std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;


}

OpenGLHandler::OpenGLHandler() {

}

OpenGLHandler::~OpenGLHandler() {

}
