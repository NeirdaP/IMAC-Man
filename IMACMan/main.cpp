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

#include "include/OpenGLHandler.hpp"

using namespace glimac;

int main(int argc, char** argv) {
   // Initialize SDL and open a window */
   SDLWindowManager windowManager(800, 600, "IITRE");
    SDLWindowManager &refWinMa = windowManager;

    OpenGLHandler glHandler = OpenGLHandler::getInstance();
    glHandler.start((std::string) argv[0]);


    /*********************************
     * HERE SHOULD COME THE INITIALIZATION CODE
     *********************************/
    std::cout << "coucou" << std::endl;
    Board *board = Board::getInstBoard(); //singleton board
    board->getLabyrinth()->printLaby();

    int nbGhosts = 4;
    int pDir = 0;

    //create Pacman
    Pacman * pacman = Pacman::getInstPac(); //singleton pacman

    std::vector<Ghost*> tabGhosts;
    for(int i = 0 ; i < nbGhosts ; i++){
        Ghost * ghost = new Ghost();
        tabGhosts.push_back(ghost);
    }

    bool gameIsOn = true;
    while(gameIsOn){

        board->displayScore(pacman);
        board->displayLives(pacman);
        std::cout << "Time :" << (int)(board->getTime() -windowManager.getTime()) << std::endl;

        //std::cout << "ok"  << std::endl;
        pDir = pacman->keyPressed(windowManager);
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
        if(!pacman->getIsAlive() || (int)windowManager.getTime()== board->getTime()){
            gameIsOn = false;
        }
    }


    return EXIT_SUCCESS;
}
