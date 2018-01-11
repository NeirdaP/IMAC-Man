//
// Created by Thibault on 11/01/2018.
//

#ifndef IMACGL_GAMEAPP_H
#define IMACGL_GAMEAPP_H

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

public:
    GameApp();
    void appInit();
    void appLoop(glimac::SDLWindowManager windowManager);
    int checkKeyPressed(SDL_Event e);
};


#endif //IMACGL_GAMEAPP_H
