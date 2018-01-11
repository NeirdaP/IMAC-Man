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
    int time;
    Board();
    Board(int w, int ntime);
    static Board * board; // singleton

public:

    void loadElements();

    //getters
    int getWidth();
    Labyrinth* getLabyrinth();
    int getTime() const;
    static Board *getInstBoard();

    //setters
    void setWidth(int w);
    void setLabyrinth(Labyrinth* l);
    void setTime(int time);

    //methods
    void displayScore(Pacman * p);
    void displayLives(Pacman *p);
};

Board* Board::board = nullptr;
#endif //IMACGL_BOARD_H
