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
    int nbGhosts = 4;

    //create Pacman
    Pacman * pacman = new Pacman();

    std::vector<Ghost*> tabGhosts;
    for(int i = 0 ; i < nbGhosts ; i++){
        Ghost * ghost = new Ghost();
        tabGhosts.push_back(ghost);
    }

    bool gameIsOn = true;
    while(gameIsOn){
        int pDir = pacman->getDirection();
        Labyrinth * labyr = board->getLabyrinth();
        pacman->move(pDir, labyr);

        int gDir;
        for(int i = 0 ; i < nbGhosts ; i++){
            //gDir = tabGhosts[i]->getDirection();
            tabGhosts[i]->moveRandom(labyr);
            tabGhosts[i]->eat(pacman);
        }

        labyr->printLaby();
        //Sleep(1);
        if(!pacman->getIsAlive()){
            gameIsOn = false;
        }
    }


    return EXIT_SUCCESS;
}
