//
// Created by Thibault on 02/01/2018.
//

#ifndef IMACGL_BOARD_H
#define IMACGL_BOARD_H

#include <iostream>
#include <string>
#include <vector>
#include "../include/Labyrinth.h"
#include "../include/Personnage.h"
#include "../include/Pacman.h"

class Board {
private:
    int width;
    Labyrinth labyrinth;
    int level;



public:
    Board();
    Board(int w);
    void loadElements();

    //getters
    int getWidth();
    Labyrinth* getLabyrinth();

    //setters
    void setWidth(int w);
    void setLabyrinth(Labyrinth* l);

    //methods
    void displayScore(Pacman * p);
};


#endif //IMACGL_BOARD_H
