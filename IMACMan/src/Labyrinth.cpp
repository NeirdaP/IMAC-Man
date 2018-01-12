//
// Created by Idefix on 04/01/2018.
//

#include <iostream>
#include <string>
#include <vector>
#include "../include/Labyrinth.h"

Labyrinth::Labyrinth(){
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < width; ++j) {
            vecCases.push_back(Case(i,j));
        }
    }
}

//getters

int Labyrinth::getWidth(){
    return width;
}

std::vector<int> Labyrinth::getLaby(){
    return tabCases;
}

int Labyrinth::getLabyCaseValue(int x, int y){
    return tabCases[x * width + y];
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
            switch(tabCases[j + width * i]){

                case 0: std::cout << ". ";
                    break;

                case 1: std::cout << "= ";
                    break;

                case 2: std::cout << "  ";
                    break;

                case 4: std::cout << "O ";
                    break;

                case 5: std::cout << "X ";
                    break;

                default: std::cout << tabCases[j + width * i] << " ";
            }

        }
        std::cout << std::endl;
    }
    std::cout << std::endl << std::endl << std::endl;
}

