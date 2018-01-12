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
    BonusDuration = 15;
    currentBonus = new int[4];
    for(int k = 0; k < 3; k++){
        currentBonus[k] = 0;
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

double Labyrinth::getBonusDuration() const {
    return BonusDuration;
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

void Labyrinth::setBonusDuration(double BonusDuration) {
    Labyrinth::BonusDuration = BonusDuration;
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

                case 17: std::cout << "| ";
                    break;

                case 18: std::cout << "| ";
                    break;

                default: std::cout << tabCases[j + width * i] << " ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl << std::endl << std::endl;
}

void Labyrinth::applyBonus(glimac::SDLWindowManager windowmanage, Pacman* p) {
    switch((int)currentBonus[0]){

        case 1: p->setNbLives(p->getNbLives() + 1);
            currentBonus[0] = 0;
            currentBonus[1] = 0;
            break;

        case 2: p->setEatDuration(p->getEatDuration()*2);
            currentBonus[0] = 0;
            currentBonus[1] = 0;
            break;

        case 3: p->setSpeed( p->getSpeed() *2);
            currentBonus[2] = (int) windowmanage.getTime();
            break;

        default: break;
    }
}

void Labyrinth::updateBonus(glimac::SDLWindowManager windowmanage, Pacman *p) {
    if(windowmanage.getTime()> 1 && (int)windowmanage.getTime() % 50 != 0){
        int randomBonus = std::rand() % 3;
        int randX, randY;
        currentBonus[0] = randomBonus;
        currentBonus[1] = (int)windowmanage.getTime();
        do{
            randX = std::rand() % 10;
            randY = std::rand() % 10;
        }while(getLabyCaseValue(randX,randY)!= 0);
        setOneCaseLaby(randX,randY,8);

    }

    if(currentBonus[2]!= 0 && currentBonus[2] >= (int)BonusDuration){
        if (currentBonus[0]== 3){
            p->setSpeed(p->getSpeed() / 2);
        }
        for(int i = 0; i < 3; i++){
            currentBonus[i] = 0;
        }
    }

}




