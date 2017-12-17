#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <iostream>
#include <glimac/Program.hpp>
#include <glimac/FilePath.hpp>
#include <glimac/Sphere.hpp>
#include "glimac/Image.hpp"
#include <glimac/glm.hpp>
#include <glimac/common.hpp>
#include <glimac/FreeFlyCamera.hpp>
#include <vector>

using namespace glimac;

int main(int argc, char** argv) {
    // Initialize SDL and open a window
    SDLWindowManager windowManager(1600, 900, "GLImac");

    // Initialize glew for OpenGL3+ support
    GLenum glewInitError = glewInit();
    if(GLEW_OK != glewInitError) {
        std::cerr << glewGetErrorString(glewInitError) << std::endl;
        return EXIT_FAILURE;
    }

    FilePath applicationPath(argv[0]);

    std::string VS = "shaders/3D.vs.glsl";
    std::string FS = "shaders/multiTex3D.fs.glsl";

#if __APPLE__
    Program program = loadProgram(VS, FS);
#else
    Program program = loadProgram(applicationPath.dirPath() + VS,
                                      applicationPath.dirPath() + FS);
#endif
    program.use();

    std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;

    /*********************************
     * HERE SHOULD COME THE INITIALIZATION CODE
     *********************************/

    return EXIT_SUCCESS;
}
