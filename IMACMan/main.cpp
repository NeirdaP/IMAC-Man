#include "glimac/SDLWindowManager.hpp"
#if __APPLE__
//#include <GL/glew.h>
#endif
#define GLEW_STATIC
#include <iostream>
/*#include <glimac/Program.hpp>
#include <glimac/FilePath.hpp>
#include <glimac/Sphere.hpp>
#include "glimac/Image.hpp"
#include <glimac/glm.hpp>
#include <glimac/common.hpp>
#include <glimac/FreeFlyCamera.hpp>*/
#include <vector>
#include <string>
#include <chrono>
#include <unistd.h>

#if __WINDOWS__
#include <windows.h>
#endif

//#include <SDL_mixer.h>

#include <unistd.h>

#include "include/Board.h"
#include "include/Labyrinth.h"
#include "include/Personnage.h"
#include "include/Pacman.h"
#include "include/Ghost.h"
#include "include/GameApp.h"

//#include "include/OpenGLHandler.hpp"
//#include "include/VertexBuffer.hpp"
//#include "include/Renderer.hpp"

using namespace glimac;

int main(int argc, char** argv) {
    // Initialize SDL and open a window */
    SDLWindowManager windowManager(800, 600, "TITRE");
    SDLWindowManager &refWinMa = windowManager;

    //OpenGLHandler glHandler = OpenGLHandler::getInstance();
    //glHandler.start((std::string) argv[0]);

    /*********************************
     * HERE SHOULD COME THE INITIALIZATION CODE
     *********************************/


    bool startAgain = true;                         //defines if the player wants to start again at the end of the game or not
    while(startAgain){
        GameApp * app = new GameApp();              //create new app
        app->appInit();
        startAgain = app->appLoop(refWinMa);

        app->appDisallow();
        delete app;
    }




    return EXIT_SUCCESS;
}
