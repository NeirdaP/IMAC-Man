//
// Created by Thibault on 02/01/2018.
//

#include <iostream>
#include <string>
#include <vector>
#include "../include/Board.h"
#include "../include/Pacman.h"
#include "../include/Ghost.h"

Board::Board(){};

Board::Board(int w){
    this->width = w;
    loadElements();
};


void Board::loadElements(){

    //create labyrinth
    Labyrinth* laby = new Labyrinth();
    //0 : chemin avec pacgomme / 1 : mur / 2 : chemin sans pacgomme 4 : super pac gomme  5 : fantôme 9 : pacman
    std::vector<int> l = {1, 1, 1, 1, 1, 1, 1, 1, 1,  1, 0, 0, 0, 0, 4, 0, 0, 1,  1, 0, 1, 0, 1, 1, 1, 0, 1,  1, 0, 0, 0, 0, 4, 0, 0, 1,  1, 1, 0, 1, 0, 1, 1, 0, 1,  1, 1, 0, 1, 0, 0, 1, 0, 1,  1, 1, 0, 1, 1, 0, 0, 0, 1,  1, 1, 0, 0, 4, 0, 1, 0, 1,  1, 1, 1, 1, 1, 1, 1, 1, 1};
    laby->setWidth(width);
    laby->setLaby(l);
    laby->setWidth(width);
    setLabyrinth(laby);


}

//getters
int Board::getWidth(){
    return width;
}

Labyrinth* Board::getLabyrinth(){
    return &labyrinth;
}

//setters
void Board::setWidth(int w){
    width = w;
}

void Board::setLabyrinth(Labyrinth* l){
    labyrinth = *l;
}

