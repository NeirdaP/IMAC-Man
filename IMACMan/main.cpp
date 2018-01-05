#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#define GLEW_STATIC
#include <iostream>
#include <glimac/Program.hpp>
#include <glimac/FilePath.hpp>
#include <glimac/Sphere.hpp>
#include "glimac/Image.hpp"
#include <glimac/glm.hpp>
#include <glimac/common.hpp>
#include <glimac/FreeFlyCamera.hpp>
#include <vector>
#include <string>
#include <ctime>
#include <windows.h>
#include <unistd.h>

#include "include/Board.h"
#include "include/Labyrinth.h"
#include "include/Personnage.h"
#include "include/Pacman.h"
#include "include/Ghost.h"

//using namespace glimac;

int main(int argc, char** argv) {
 /*   // Initialize SDL and open a window
    SDLWindowManager windowManager(800, 600, "GLImac");
    std::cout << "coucou test" << std::endl;
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
*/
    /*********************************
     * HERE SHOULD COME THE INITIALIZATION CODE
     *********************************/
    std::cout << "coucou" << std::endl;
    Board * board = new Board(9);
    board->getLabyrinth()->printLaby();

    //create Pacman
    Personnage * pacman = new Pacman();

    int gameIsOn = 0;
    while(gameIsOn < 10){
        int p = pacman->getDirection();
        Labyrinth * gg = board->getLabyrinth();
        pacman->move(p, gg);

        gg->printLaby();
        //Sleep(1);
        gameIsOn++;
    }


    return EXIT_SUCCESS;
}
