//
// Created by Thibault on 11/01/2018.
//

#include <iostream>
#include <vector>

#include "../include/GameApp.h"
#include "../include/Board.h"
#include "../include/Labyrinth.h"
#include "../include/Personnage.h"
#include "../include/Pacman.h"
#include "../include/Ghost.h"
#include <Windows.h>

GameApp::GameApp(){
    nbGhosts = 4;
    startAgain = true;
}

void GameApp::appInit(){
    board = Board::getInstBoard(); //singleton board
    board->getLabyrinth()->printLaby();

    int pDir = 0;

    //create Pacman
    //pacman = Pacman::getInstPac(); //singleton pacman
    pacman = new Pacman();

    //std::vector<Ghost*> tabGhosts;
    for(int i = 0 ; i < nbGhosts ; i++){
        Ghost * ghost = new Ghost();
        tabGhosts.push_back(ghost);
    }
}

bool GameApp::appLoop(glimac::SDLWindowManager windowManager){
    gameIsOn = true;
    Labyrinth * labyr;
    while(gameIsOn){

        board->displayScore(pacman);
        board->displayLives(pacman);
        std::cout << "Time :" << (int)(board->getTime() - windowManager.getTime()) << std::endl;
        labyr = board->getLabyrinth();
        labyr->printLaby();

        //std::cout << "ok"  << std::endl;
        SDL_Event e;
        while(windowManager.pollEvent(e)){
            checkKeyPressed(e);
        }
        GameApp::appRegenerateghost(windowManager);
        pacman->canEatGhost(windowManager);
        pacman->move(pDir, labyr);

        //int gDir;
        for(int i = 0 ; i < nbGhosts ; i++){
            //gDir = tabGhosts[i]->getDirection();
            tabGhosts[i]->moveRandom(labyr);
            tabGhosts[i]->eat(pacman,windowManager);
            std::cout <<"pac fant " << i << "pac pos x"<<tabGhosts[i]->getPosX() <<"pac posy" <<tabGhosts[i]->getPosY() << std::endl << std::endl;
        }
        std::cout <<"pac posx" <<pacman->getPosX() <<"pac posy" <<pacman->getPosY() << std::endl << std::endl;
        Sleep(1000);

        if(!(pacman->getIsAlive()) || (int)windowManager.getTime()== board->getTime()){
            std::cout << "Game over" << std::endl;
            gameIsOn = false;
        }
    }
    return startAgain;
}

void GameApp::checkKeyPressed(SDL_Event e){
    if (e.type == SDL_KEYDOWN){
        if (e.key.keysym.sym == SDLK_q){
            pDir = 1;
            return;
        }
        else if (e.key.keysym.sym == SDLK_s){
            pDir = 2;
            return;
        }
        else if (e.key.keysym.sym == SDLK_d){
            pDir = 3;
            return;
        }
        else if (e.key.keysym.sym == SDLK_z){
            pDir = 4;
            return;
        }
        else if (e.key.keysym.sym == SDLK_ESCAPE){
            gameIsOn = false;
            startAgain = false;
            atexit(SDL_Quit);
            return;
        }/*
        else if (e.key.keysym.sym == SDLK_UP){
            pacman->zoom();
        } else if (e.key.keysym.sym == SDLK_DOWN){
            pacman->dezoom();
        }*/
    } /*else if (e.type == SDL_QUIT) {
        //done = true; // Leave the loop after this iteration
    }*/
    //}
}

void GameApp::appDisallow(){
    pacman = nullptr;
    for(int i = 0 ; i < nbGhosts ; ++i){
        tabGhosts.pop_back();
    }
    tabGhosts.clear();
}

void GameApp::appRegenerateghost(glimac::SDLWindowManager windowManager) {
    for(int i = 0 ; i < nbGhosts ; ++i){
        if(!tabGhosts[i]->isActive()){
            if(windowManager.getTime()>= tabGhosts[i]->getPosX()+ tabGhosts[i]->getDeactivatedTime()){
                tabGhosts[i]->setActive(true);
            }
        }
    }
}
