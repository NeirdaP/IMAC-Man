//
// Created by Thibault on 02/01/2018.
//

#include <iostream>
#include <string>
#include <vector>
#include "../include/Board.h"

Board::Board(){}

//getters
int Board::getWidth(){
    return width;
}

int** Board::getLabyrinth(){
    return labyrinth;
}

//setters
void Board::setWidth(int w){
    width = w;
}

void Board::setLabyrinth(int** l){
    labyrinth = l;
}