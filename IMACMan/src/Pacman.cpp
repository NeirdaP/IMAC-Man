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

void Pacman::move(){

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