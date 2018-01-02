//
// Created by Idefix on 02/01/2018.
//

#ifndef IMACGL_BOARD_H
#define IMACGL_BOARD_H

#include <iostream>
#include <string>
#include <vector>

class Board {
private:
    int width;
    int** labyrinth;

public:
    Board();

    //getters
    int getWidth();
    int** getLabyrinth();

    //setters
    void setWidth(int w);
    void setLabyrinth(int** l);
};


#endif //IMACGL_BOARD_H
