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
//test de la testance
//test
void Personnage::move(int action){
switch(action){
    case 0:
        //veut avancer tout droit
        //véririfie s'il y a un mur, si oui rappelle move(action++)
        break;
    case 1:
        //veut tourner à droite
        break;
    case 2:
        //veut touner à gauche
        break;
    case 3:
        //veut faire demi tour
        break;
    }
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

bool Personnage::getIsPrey(){
    return isPrey;
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

void Personnage::setIsPrey(bool p){
    isPrey = p;
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




