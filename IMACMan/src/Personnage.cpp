//
// Created by Thibault on 02/01/2018.
//

#include <iostream>
#include <string>
#include <vector>
#include "../include/Personnage.h"

Personnage::Personnage(){
    isAlive = true;
}

void Personnage::move(int action, Labyrinth* laby){
    std::cout << "fail wrong move function personnage" << std::endl;
    /*laby->setOneCaseLaby((int)positionX, (int)positionY, 0);
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
    laby->setOneCaseLaby((int)positionX, (int)positionY, 9);
    direction = action;*/
}

void Personnage::eat(){

}

void Personnage::die(){

}



//getters
bool Personnage::getIsAlive(){
    return isAlive;
}

float Personnage::getSpeed(){
    return speed;
}

float Personnage::getPosX(){
    return positionX;
}

float Personnage::getPosY(){
    return positionY;
}

int Personnage::getDirection(){
    return direction;
}



//setters
void Personnage::setIsAlive(bool a){
    isAlive = a;
}

void Personnage::setSpeed(float s){
    speed = s;
}


void Personnage::setPosX(float px){
    positionX = px;
}

void Personnage::setPosY(float py){
    positionY = py;
}

void Personnage::setPosXY(float px, float py){
    positionX = px;
    positionY = py;
}

void Personnage::setDirection(int d){
    direction = d;
}



