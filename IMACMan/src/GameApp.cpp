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
//#include <SDL_mixer.h>

#if __WINDOWS__
#include <windows.h>
#endif

GameApp::GameApp(){
    nbGhosts = 4;
    startAgain = true;
}
/*
void GameApp::musiqueApp(){
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
}*/

void GameApp::appInit(){
//    musiqueApp();

    board = Board::getInstBoard();              //singleton board
    board->getLabyrinth()->printLaby();

    pacman = new Pacman();

    for(int i = 0 ; i < nbGhosts ; i++){
        Ghost * ghost = new Ghost();            //rempli le tableau de Ghost
        tabGhosts.push_back(ghost);
    }

    appCamera = new Camera();

//    appRenderer = new Renderer(appCamera);

/*    Model* model = new Model();

    appRenderer->addModel(model);
    appRenderer->renderModels();*/
}

bool GameApp::appLoop(glimac::SDLWindowManager windowManager) {
    gameIsOn = true;
    Labyrinth *labyr;
    while (gameIsOn) {

        board->displayScore(pacman);
        board->displayLives(pacman);
        std::cout << "Time :" << (int) (board->getTime() - windowManager.getTime()) << std::endl;
        labyr = board->getLabyrinth();
        labyr->printLaby();

        SDL_Event e;
        while (windowManager.pollEvent(e)) {
            checkKeyPressed(e);                             //fonction qui vérifie si une touche du clavier est appuyée
        }
        appRegenerateghost(windowManager);                  //fonction qui régénère les fantômes lorsqu'ils sont mangés par pacman
        pacman->canEatGhost(windowManager);                 //fonction qui permet a pacman de manger les fantomes s'il a un bonus
        pacman->updateBonus(windowManager, labyr);
        pacman->move(pDir, labyr, windowManager);           //fonction qui fait bouger pacman

        for (int i = 0; i < nbGhosts; i++) {
            //gDir = tabGhosts[i]->getDirection();
            tabGhosts[i]->moveRandom(labyr);                //fonction qui fait bouger les fantomes
            tabGhosts[i]->eat(pacman, windowManager);

            //Pause 1 seconde windows et mac
            double timePause = windowManager.getTime();
            do {                                            //fait une pause (compatible windows et mac
            }while(windowManager.getTime() <= timePause + 1);


            if (!(pacman->getIsAlive()) || (int) windowManager.getTime() == board->getTime()) {
                gameIsOn = false;
            }
        }
        return startAgain;
    }
}

//fonction qui vérirife les différentes touches du clavier qui sont associées a des actions
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
        else if (e.key.keysym.sym == SDLK_p){
            std::cout << "Pause" << std::endl;
            getchar();
            return;
        }
        else if (e.key.keysym.sym == SDLK_ESCAPE){
            gameIsOn = false;
            startAgain = false;
            atexit(SDL_Quit);
            return;
        }
    } else if (e.type == SDL_QUIT) {
        gameIsOn = false;                           // Leave the loop after this iteration
    }
}

void GameApp::appDisallow(){
    pacman = nullptr;
    for(int i = 0 ; i < nbGhosts ; ++i){
        tabGhosts.pop_back();
    }
    tabGhosts.clear();
}

//regenre les fantomes lorsqu'ils se font manger par pacman
void GameApp::appRegenerateghost(glimac::SDLWindowManager windowManager) {
    for(int i = 0 ; i < nbGhosts ; ++i){
        if(!tabGhosts[i]->isActive()){
            if(windowManager.getTime()>= tabGhosts[i]->getPosX()+ tabGhosts[i]->getDeactivatedTime()){
                tabGhosts[i]->setActive(true);
            }
        }
    }
}
