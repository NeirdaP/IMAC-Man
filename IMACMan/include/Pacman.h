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
    int nbLives; // nombres de vies
    int points; // nombre de points
    //Pacman();
    //static Pacman * pacman; //singleton pacman
    double eatBegin; //temps à partir duquel pacman a mangé un super pacgom
    double eatDuration; //temps que pacman peut manger fantôme
    bool isPrey;//définit si le personnage chasse ou est chassé par les autres personnages;
    int* currentBonus; //tableau contenant les infos sur le bonus actif (voir cpp)
    int randX,randY;
    double BonusDuration;

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
    void move(int action, Labyrinth* laby, glimac::SDLWindowManager &windowManager); // gère le déplacement du pacman
    void die(); // gestion du nombre de vie
    void canEatGhost(glimac::SDLWindowManager &windowManager); // met à jour si le pacman peut toujours manger des fantômes
    ~Pacman();
    void updateBonus(glimac::SDLWindowManager windowmanage, Labyrinth* laby); //gestion de la création suppression bonus
    void applyBonus(glimac::SDLWindowManager windowmanage, Labyrinth* laby);

};

#endif //IMACGL_PACMAN_H
