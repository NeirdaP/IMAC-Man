//
// Created by Thibault on 02/01/2018.
//

#ifndef IMACGL_PACMAN_H
#define IMACGL_PACMAN_H

#include <iostream>
#include <string>
#include <vector>
#include "Personnage.h"

class Pacman : public Personnage{
private:
    int nbLives;
    int points;

public:
    Pacman();

    void move(int action, Labyrinth* laby);
    void eat();
    void die();

    //getters
    int getNbLives();
    int getPoints();

    //setters
    void setNbLives(int l);
    void setPoints(int p);

};


#endif //IMACGL_PACMAN_H
