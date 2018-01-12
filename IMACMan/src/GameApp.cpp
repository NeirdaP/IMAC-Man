//
// Created by Thibault on 11/01/2018.
//

#include "../include/GameApp.h"
#include "../include/Board.h"
#include "../include/Labyrinth.h"
#include "../include/Personnage.h"
#include "../include/Pacman.h"
#include "../include/Ghost.h"
#include <Windows.h>

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
        SDL_Event e;
        while(windowManager.pollEvent(e)){
            checkKeyPressed(e);
        }
        Labyrinth * labyr = board->getLabyrinth();
        pacman->move(pDir, labyr,windowManager);

        //int gDir;
        for(int i = 0 ; i < nbGhosts ; i++){
            //gDir = tabGhosts[i]->getDirection();
            tabGhosts[i]->moveRandom(labyr);
            tabGhosts[i]->eat(pacman);
        }
        Sleep(1000);

        labyr->printLaby();

        std::cout << "temps ecoule: " << windowManager.getTime() << " secondes" << std::endl;
        if(!pacman->getIsAlive() || (int)windowManager.getTime()== board->getTime()){
            gameIsOn = false;
        }
    }
}

void GameApp::checkKeyPressed(SDL_Event e){
    if (e.type == SDL_KEYDOWN){
        if (e.key.keysym.sym == SDLK_z){
            pDir = 1;
            return;
        }
        else if (e.key.keysym.sym == SDLK_d){
            pDir = 2;
            return;
        }
        else if (e.key.keysym.sym == SDLK_s){
            pDir = 3;
            return;
        }
        else if (e.key.keysym.sym == SDLK_q){
            pDir = 4;
            return;
        }/*
        else if (e.key.keysym.sym == SDLK_UP){
            pacman->zoom();
        } else if (e.key.keysym.sym == SDLK_DOWN){
            pacman->dezoom();
        }*/
    } else if (e.type == SDL_QUIT) {
        //done = true; // Leave the loop after this iteration
    }
    //}
}