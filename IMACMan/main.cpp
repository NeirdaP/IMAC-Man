#include "glimac/SDLWindowManager.hpp"
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
#include <chrono>

#if __WINDOWS__
#include <windows.h>
#endif

#include <unistd.h>

#include "include/Board.h"
#include "include/Labyrinth.h"
#include "include/Personnage.h"
#include "include/Pacman.h"
#include "include/Ghost.h"
#include "include/GameApp.h"

#include "include/OpenGLHandler.hpp"
#include "include/VertexBuffer.hpp"

using namespace glimac;

int main(int argc, char** argv) {

    // Initialize SDL and open a window */
    SDLWindowManager windowManager(800, 600, "TITRE");
    SDLWindowManager &refWinMa = windowManager;

    OpenGLHandler glHandler = OpenGLHandler::getInstance();
    glHandler.start((std::string) argv[0]);

    Model model;

    /*********************************
     * HERE SHOULD COME THE INITIALIZATION CODE
     *********************************/
    std::cout << "coucou" << std::endl;

    GameApp * app = new GameApp();
    app->appInit();
    app->appLoop(refWinMa);

    return EXIT_SUCCESS;
}
