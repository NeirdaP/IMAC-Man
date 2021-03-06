//
// Created by Thibault on 02/01/2018.
//

#include <iostream>
#include <string>
#include <vector>
#include "../include/Pacman.h"


//Pacman * Pacman::pacman = nullptr ;

Pacman::Pacman(){
    Personnage();
    this->nbLives = 3;
    setPosXY(1, 1);
    isPrey = false;
    points = 0;
    setDirection(0);
    eatBegin = 0;
    eatDuration = 10;
    BonusDuration = 15;
    currentBonus = new int[4];
    for(int k = 0; k < 3; k++){
        currentBonus[k] = 0;
    }
}

void Pacman::move(int action, Labyrinth* laby,glimac::SDLWindowManager &windowManager){
    int positionX = (int)getPosX();
    int positionY = (int)getPosY();
    laby->setOneCaseLaby(positionX, positionY, 2);
    switch(action){
        case 1:
            //veut aller a gauche
            if(laby->getLabyCaseValue(positionX, positionY - 1) != 1){
                positionY--;
            }
            break;
        case 2:
            //veut aller en bas
            if(laby->getLabyCaseValue(positionX + 1, positionY) != 1){
                positionX++;
            }
            break;
        case 3:
            //veut aller a droite
            if(laby->getLabyCaseValue(positionX, positionY + 1) != 1){
                positionY++;
            }
            break;
        case 4:
            //veut aller en haut
            if(laby->getLabyCaseValue(positionX - 1, positionY) != 1){
                positionX--;
                //action++;
                //move(action, laby);
            }
            break;

        default: action = 1;
    }

    setPosX((float)positionX);
    setPosY((float)positionY);
    int currentPos = laby->getLabyCaseValue(positionX, positionY);
    switch(currentPos){
        case 0:
            points += 10;
            break;
        case 4:
            points += 50;
            isPrey = true;
            break;

        case 8: applyBonus(windowManager,laby);
            break;

        case 17:
            //va du portail droit au portail haut
            setPosX(1);
            setPosY(5);
            setDirection(2);
            laby->setOneCaseLaby(positionX, positionY, 17);
            break;
        case 18:
            //va du portail haut au portail droit
            setPosX(5);
            setPosY(1);
            setDirection(3);
            laby->setOneCaseLaby(positionX, positionY, 18);
            break;

        default:
            break;
    }

    if(isPrey){
        laby->setOneCaseLaby(positionX, positionY, 6);
    }
    else{
        laby->setOneCaseLaby(positionX, positionY, 9);
    }

    setDirection(action);
}
void Pacman::die(){
    std::cout <<"die"<< std::endl;
    if(nbLives == 1){
        setIsAlive(false);
        std::cout << "----------- GAME OVER -----------" << std::endl;
    }

    if(nbLives > 1){
        nbLives--;
        std::cout << "You've lost 1 life !"<< std::endl;
        setPosXY(1, 1);
    }

}

//getters
int Pacman::getNbLives(){
    return nbLives;
}

int Pacman::getPoints(){
    return points;
}

/*Pacman *Pacman::getInstPac() {
    if(!pacman){
        pacman = new Pacman();
    }
    return pacman;
}*/

double Pacman::getEatBegin() const {
    return eatBegin;
}

double Pacman::getEatDuration() const {
    return eatDuration;
}

bool Pacman::getIsPrey() const{
    return isPrey;
}

//setters
void Pacman::setNbLives(int l){
    nbLives = l;
}

void Pacman::setPoints(int p){
    points += p;
}

void Pacman::setEatDuration(double eatDuration) {
    Pacman::eatDuration = eatDuration;
}

void Pacman::setIsPrey(bool isPrey) {
    Pacman::isPrey = isPrey;
}

void Pacman::setEatBegin(double eatBegin) {
    Pacman::eatBegin = eatBegin;
}



//methods


void Pacman::canEatGhost(glimac::SDLWindowManager& windowManager) {

    if(isPrey && !eatBegin){
        eatBegin = windowManager.getTime();
    }
    if(windowManager.getTime() >= eatBegin +eatDuration){
        eatBegin = 0;
        isPrey = false;
    }

}

void Pacman::applyBonus(glimac::SDLWindowManager windowmanage, Labyrinth *laby) {

    switch((int)currentBonus[0]){

        case 1: setNbLives(getNbLives() + 1);
            currentBonus[0] = 0;
            currentBonus[1] = 0;
            break;

        case 2: setEatDuration(getEatDuration()*2);
            currentBonus[0] = 0;
            currentBonus[1] = 0;
            break;

        case 3: setSpeed(getSpeed() *2);
            currentBonus[2] = (int) windowmanage.getTime();
            break;

        default: break;
    }
}

void Pacman::updateBonus(glimac::SDLWindowManager windowmanage, Labyrinth *laby) {
    //création d'un bonus
    if(windowmanage.getTime()> 1 && (int)windowmanage.getTime() % 50 != 0){
        int randomBonus = std::rand() % 3;
        currentBonus[0] = randomBonus;
        currentBonus[1] = (int)windowmanage.getTime();
        do{
            randX = std::rand() % 15;
            randY = std::rand() % 15;
        }while(laby->getLabyCaseValue(randX,randY)!= 0);
        laby->setOneCaseLaby(randX,randY,8);
    }

    //si le bonus n'as pas été mangé pendant le temps imparti
    if(windowmanage.getTime() >= currentBonus[1]+(int)BonusDuration && currentBonus[2] == 0){
        laby->setOneCaseLaby(randX,randY,0);
    }
    //désactive un bonus temporaire
    if(currentBonus[2]!= 0 && currentBonus[2] >= (int)BonusDuration){
        if (currentBonus[0]== 3){
            setSpeed(getSpeed() / 2);
        }
        for(int i = 0; i < 3; i++){
            currentBonus[i] = 0;
        }
    }

}


