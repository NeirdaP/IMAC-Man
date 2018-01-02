//
// Created by Idefix on 02/01/2018.
//

#include "../include/Personnage.h"

Personnage::Personnage(){}

void Personnage::move(){

}

void Personnage::eat(){

}

void Personnage::die(){

}



int Personnage::getSpeed(){
    return speed;
}

bool Personnage::getIsPrey(){
    return isPrey;
}



void Personnage::setSpeed(int s){
    speed = s;
}

void Personnage::setIsPrey(bool p){
    isPrey = p;
}