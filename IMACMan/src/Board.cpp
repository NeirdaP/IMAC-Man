//
// Created by Thibault on 02/01/2018.
//

#include <iostream>
#include <string>
#include <vector>
#include "../include/Board.h"

Board::Board(){};

Board::Board(int w){
    this->width = w;
};


void Board::loadElements(){
    Labyrinth* laby = new Labyrinth();
    std::vector<int> l = {1, 1, 1, 1, 1,  1, 0, 1, 0, 1,  1, 0, 0, 0, 1,  1, 1, 0, 1, 1,  1, 1, 1, 1, 1};
    laby->setLaby(l);
    laby->setWidth(width);
    setLabyrinth(laby);
}

//getters
int Board::getWidth(){
    return width;
}

Labyrinth Board::getLabyrinth(){
    return labyrinth;
}

//setters
void Board::setWidth(int w){
    width = w;
}

void Board::setLabyrinth(Labyrinth* l){
    labyrinth = *l;
}