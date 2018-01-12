//
// Created by Thibault on 11/01/2018.
//

#ifndef IMACGL_GAMEAPP_H
#define IMACGL_GAMEAPP_H

#include <iostream>
#include "../../glimac/include/glimac/SDLWindowManager.hpp"

#include "../include/Board.h"
#include "../include/Labyrinth.h"
#include "../include/Personnage.h"
#include "../include/Pacman.h"
#include "../include/Ghost.h"


class GameApp {
private:
    Board * board;
    Pacman * pacman;
    int nbGhosts;
    std::vector<Ghost*> tabGhosts;
    int pDir;
    bool gameIsOn;
    bool startAgain;

public:
    GameApp();
    void appInit();
    bool appLoop(glimac::SDLWindowManager windowManager);
    void checkKeyPressed(SDL_Event e);
    void appDisallow();
    void appRegenerateghost(glimac::SDLWindowManager windowManager);
};


#endif //IMACGL_GAMEAPP_H
