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

public:
    Pacman();

    void move();
    void eat();

    //getters
    int getNbLives();

    //setters
    void setNbLives(int l);

};


#endif //IMACGL_PACMAN_H
