//
// Created by Thibault on 02/01/2018.
//
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "../include/Ghost.h"

Ghost::Ghost(){
    Personnage();
    setPosXY(7, 5);
}


Ghost::~Ghost(){
 std::cout << "fantôme détruit" << std::endl;
}

//getters
float Ghost::getRegenTimer(){
    return regenerationTimer;
}

//setters
void Ghost::setRegenTimer(float t){
    regenerationTimer = t;
}



void Ghost::moveRandom(Labyrinth* laby){
    //std::srand(std::time(nullptr));

    int randomDir = std::rand() % 4;
    //std::cout << "random dir : " << randomDir << std::endl;
    move(randomDir, laby);
}

void Ghost::move(int action, Labyrinth* laby){
    //std::cout << "move ghost" << std::endl;

    int positionX = (int)getPosX();
    int positionY = (int)getPosY();
    laby->setOneCaseLaby(positionX, positionY, 0);
    bool movementDone = false;
    while(!movementDone) {
        switch (action) {
            case 0:
                //veut aller en haut
                //véririfie s'il y a un mur, si oui rappelle move(action++)
                if (laby->getLaby()[positionX * laby->getWidth() + (positionY - 1)] == 1) {
                    action++;
                } else {
                    positionY--;
                    movementDone = true;
                }
                break;
            case 1:
                //veut aller à droite
                if (laby->getLaby()[(positionX + 1) * laby->getWidth() + positionY] == 1) {
                    action++;
                } else {
                    positionX++;
                    movementDone = true;
                }
                break;
            case 2:
                //veut aller en bas
                if (laby->getLaby()[positionX * laby->getWidth() + (positionY + 1)] == 1) {
                    action++;
                } else {
                    positionY++;
                    movementDone = true;
                }
                break;
            case 3:
                //veut aller à gauche
                if (laby->getLaby()[(positionX - 1) * laby->getWidth() + positionY] == 1) {
                    action = 0;
                } else {
                    positionX--;
                    movementDone = true;
                }
                break;
            default:
                action = 0;
                break;
        }
    }
    setPosX((float)positionX);
    setPosY((float)positionY);
    laby->setOneCaseLaby(positionX, positionY, 5);
    setDirection(action);
}

void Ghost::eat(Pacman* p){
    if(p->getPosX() == getPosX() && p->getPosY() == getPosY()){
            if(!p->getIsPrey()) {
                p->die();
            }
        else if(p->getIsPrey()){
                p->setPoints(p->getPoints()+100);
             //delete(this);
                std::cout << "looser" << std::endl;
        }
    }
}

