//
// Created by Thibault on 02/01/2018.
//

#ifndef IMACGL_BOARD_H
#define IMACGL_BOARD_H

#include <iostream>
#include <string>
#include <vector>
#include "../include/Labyrinth.h"

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
};


#endif //IMACGL_BOARD_H
