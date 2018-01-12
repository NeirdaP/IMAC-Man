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
}

void Pacman::move(int action, Labyrinth* laby){
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
            //tempEffect.insert("EatTimer",);
            break;
        case 5:
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


