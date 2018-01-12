//
// Created by Thibault on 02/01/2018.
//

#include <iostream>
#include <string>
#include <vector>
#include "../include/Personnage.h"

Personnage::Personnage(){
    isAlive = true;
    speed = 1;
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



