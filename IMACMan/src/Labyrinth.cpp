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
}

void Labyrinth::setOneCaseLaby(int x, int y, int value){
    tabCases[x * width + y] = value;
}


void Labyrinth::printLaby(){
    for(int i = 0 ; i < width ; i++){
        for(int j = 0 ; j < width ; j++){
            if(tabCases[j + width * i] == 1){
                std::cout << "_ ";
            }
            else if(tabCases[j + width * i] == 0){
                std::cout << "  ";
            }
            else{
                std::cout << tabCases[j + width * i] << " ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl << std::endl << std::endl;
}