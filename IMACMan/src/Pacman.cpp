//
// Created by Thibault on 02/01/2018.
//

#include <iostream>
#include <string>
#include <vector>
#include "../include/Pacman.h"


Pacman::Pacman(){
    Personnage();
    this->nbLives = 3;
    setPosXY(1, 1);
}

void Pacman::move(int action, Labyrinth* laby){
    int positionX = (int)getPosX();
    int positionY = (int)getPosY();
    laby->setOneCaseLaby(positionX, positionY, 0);
    switch(action){
        case 0:
            //veut aller en haut
            //véririfie s'il y a un mur, si oui rappelle move(action++)
            if(laby->getLaby()[positionX * laby->getWidth() + (positionY - 1)] == 1){
                action++;
                move(action, laby);
            }
            else{
                positionY--;
            }
            break;
        case 1:
            //veut aller à droite
            if(laby->getLaby()[(positionX + 1) * laby->getWidth() + positionY] == 1){
                action++;
                move(action, laby);
            }
            else{
                positionX++;
            }
            break;
        case 2:
            //veut aller en bas
            if(laby->getLaby()[positionX * laby->getWidth() + (positionY + 1)] == 1){
                action++;
                move(action, laby);
            }
            else{
                positionY++;
            }
            break;
        case 3:
            //veut aller à gauche
            if(laby->getLaby()[(positionX - 1) * laby->getWidth() + positionY] == 1){
                action++;
                move(action, laby);
            }
            else{
                positionX--;
            }
            break;
    }
    setPosX((float)positionX);
    setPosY((float)positionY);
    laby->setOneCaseLaby(positionX, positionY, 9);
    setDirection(action);
}

void Pacman::eat(){

}

//getters
int Pacman::getNbLives(){
    return nbLives;
}

//setters
void Pacman::setNbLives(int l){
    nbLives = l;
}