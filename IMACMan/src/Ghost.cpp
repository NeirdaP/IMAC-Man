//
// Created by Thibault on 02/01/2018.
//
#include <iostream>
#include <string>
#include <vector>
#include "../include/Ghost.h"

Ghost::Ghost(){}

void Ghost::move(){

}

void Ghost::eat(){

}

//getters
float Ghost::getRegenTimer(){
    return regenerationTimer;
}

//setters
void Ghost::setRegenTimer(float t){
    regenerationTimer = t;
}

