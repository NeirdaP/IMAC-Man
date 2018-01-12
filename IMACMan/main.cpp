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

#include <SDL_mixer.h>

#include <unistd.h>

#include "include/Board.h"
#include "include/Labyrinth.h"
#include "include/Personnage.h"
#include "include/Pacman.h"
#include "include/Ghost.h"
#include "include/GameApp.h"

#include "include/OpenGLHandler.hpp"
#include "include/VertexBuffer.hpp"
#include "include/Renderer.hpp"

using namespace glimac;

int main(int argc, char** argv) {
    // Initialize SDL and open a window */
    SDLWindowManager windowManager(800, 600, "TITRE");
    SDLWindowManager &refWinMa = windowManager;

    OpenGLHandler glHandler = OpenGLHandler::getInstance();
    glHandler.start((std::string) argv[0]);

    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) //Initialisation de l'API Mixer
    {
        std::cout << Mix_GetError() << std::endl;
    }

    Mix_AllocateChannels(16);
    std::string path ="C:\\Users\\Admin\\CLionProjects\\IMAC-Man\\IMACMan\\playMUSIC\\music.wav";
    Mix_Chunk* chunk = Mix_LoadWAV(path.c_str()); //transform std::string into char* so SDL_Mixer "understand" the path
    if(chunk == NULL){
        std::cout << "Error on loading : " << Mix_GetError() << std::endl;
        std::cout << "Note's path is : " << path << std::endl;
    }

    Mix_FreeChunk(chunk);

    Mix_CloseAudio();


    /*********************************
     * HERE SHOULD COME THE INITIALIZATION CODE
     *********************************/

    GameApp * app = new GameApp();
    app->appInit();
    app->appLoop(refWinMa);
    //std::cout << "coucou" << std::endl;
    bool startAgain = true;
    while(startAgain){
        GameApp * app = new GameApp();
        app->appInit();
        startAgain = app->appLoop(refWinMa);

        app->appDisallow();
        delete app;
    }




    return EXIT_SUCCESS;
}
