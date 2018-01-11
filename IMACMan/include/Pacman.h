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
    Pacman();
    static Pacman * pacman; //singleton pacman

public:
    //constructor


    //getters
    int getNbLives();
    int getPoints();
    static Pacman *getInstPac();

    //setters
    void setNbLives(int l);
    void setPoints(int p);

    //methods
    void move(int action, Labyrinth* laby);
    void die();
    void eatGhost(glimac::SDLWindowManager windowManager);
    int keyPressed(glimac::SDLWindowManager windowmanager);

};

Pacman* Pacman::pacman = nullptr;
#endif //IMACGL_PACMAN_H
