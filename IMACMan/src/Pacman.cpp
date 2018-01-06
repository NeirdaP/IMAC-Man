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
    setIsPrey(false);
    points = 0;
    setDirection(0);
}

void Pacman::move(int action, Labyrinth* laby){
    int positionX = (int)getPosX();
    int positionY = (int)getPosY();
    laby->setOneCaseLaby(positionX, positionY, 2);
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
    if(laby->getLabyCaseValue(positionX, positionY) == 0){
        points += 1000;
    }
    laby->setOneCaseLaby(positionX, positionY, 9);
    setDirection(action);
}

void Pacman::eat(){

}

void Pacman::die(){
    if(nbLives > 0){
        nbLives--;
        std::cout << "Lives : " << nbLives << std::endl;
        setPosXY(1, 1);
    }
    else{
        setIsAlive(false);
        std::cout << "----------- GAME OVER -----------" << std::endl;
    }
}

//getters
int Pacman::getNbLives(){
    return nbLives;
}

int Pacman::getPoints(){
    return points;
}

//setters
void Pacman::setNbLives(int l){
    nbLives = l;
}

void Pacman::setPoints(int p){
    points += p;
}