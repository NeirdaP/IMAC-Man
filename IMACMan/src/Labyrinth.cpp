//
// Created by Idefix on 04/01/2018.
//

#include <iostream>
#include <string>
#include <vector>
#include "../include/Labyrinth.h"

Labyrinth::Labyrinth(){

}

//getters
int Labyrinth::getWidth(){
    return width;
}

std::vector<int> Labyrinth::getLaby(){
    return tabCases;
}

//setters
void Labyrinth::setWidth(int w){
    width = w;
}

void Labyrinth::setLaby(std::vector<int> t){
    tabCases = t;
    for(int i = 0 ; i < width ; i++){
        for(int j = 0 ; j < width ; j++){
            std::cout << tabCases[i] << " ";
        }
        std::cout << std::endl;
    }
}

