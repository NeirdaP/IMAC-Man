//
// Created by Thibault on 11/01/2018.
//

#include "../include/GameApp.h"
#include "../include/Board.h"
#include "../include/Labyrinth.h"
#include "../include/Personnage.h"
#include "../include/Pacman.h"
#include "../include/Ghost.h"

GameApp::GameApp(){
    nbGhosts = 4;
}

void GameApp::appInit(){
    board = Board::getInstBoard(); //singleton board
    board->getLabyrinth()->printLaby();

    int pDir = 0;

    //create Pacman
    pacman = Pacman::getInstPac(); //singleton pacman

    //std::vector<Ghost*> tabGhosts;
    for(int i = 0 ; i < nbGhosts ; i++){
        Ghost * ghost = new Ghost();
        tabGhosts.push_back(ghost);
    }
}

void GameApp::appLoop(glimac::SDLWindowManager windowManager){
    gameIsOn = true;
    while(gameIsOn){

        board->displayScore(pacman);
        board->displayLives(pacman);
        std::cout << "Time :" << (int)(board->getTime() - windowManager.getTime()) << std::endl;

        //std::cout << "ok"  << std::endl;
        pDir = pacman->keyPressed(windowManager);
        Labyrinth * labyr = board->getLabyrinth();
        pacman->move(pDir, labyr);

        //int gDir;
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
}