//
// Created by Thibault on 02/01/2018.
//

#ifndef IMACGL_PACMAN_H
#define IMACGL_PACMAN_H

#include <iostream>
#include <string>
#include <vector>
#include <glimac/SDLWindowManager.hpp>
#include "Personnage.h"


class Pacman : public Personnage{
private:
    int nbLives;
    int points;
    bool canEat;


public:
    //constructor
    Pacman();

    //getters
    int getNbLives();
    int getPoints();

    //setters
    void setNbLives(int l);
    void setPoints(int p);

    //methods
    void move(int action, Labyrinth* laby);
    void die();
    void eatGhost();
    int keyPressed(glimac::SDLWindowManager windowmanager);

};


#endif //IMACGL_PACMAN_H
