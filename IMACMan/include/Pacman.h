//
// Created by Thibault on 02/01/2018.
//

#ifndef IMACGL_PACMAN_H
#define IMACGL_PACMAN_H

#include <iostream>
#include <string>
#include <map>
#include <glimac/SDLWindowManager.hpp>
#include "Personnage.h"


class Pacman : public Personnage{

private:
    int nbLives;
    int points;
    //Pacman();
    //static Pacman * pacman; //singleton pacman
    double eatBegin;
    double eatDuration;
    bool isPrey;//définit si le personnage chasse ou est chassé par les autres personnages;

public:
    Pacman();
    //getters
    int getNbLives();
    int getPoints();
    double getEatBegin() const;
    double getEatDuration() const;
    bool getIsPrey() const;

    //setters
    void setNbLives(int l);
    void setPoints(int p);
    void setEatBegin(double eatBegin);
    void setEatDuration(double eatDuration);
    void setIsPrey(bool isPrey);


    //methods
    void move(int action, Labyrinth* laby, glimac::SDLWindowManager &windowManager);
    void die();
    void canEatGhost(glimac::SDLWindowManager &windowManager);
    ~Pacman();


};

#endif //IMACGL_PACMAN_H
