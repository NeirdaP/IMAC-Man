//
// Created by Idefix on 04/01/2018.
//

#ifndef IMACGL_LABYRINTH_H
#define IMACGL_LABYRINTH_H

#include <iostream>
#include <string>
#include <vector>
#include "Case.hpp"
#include <glimac/Sphere.hpp>
#include <glimac/SDLWindowManager.hpp>
#include <ctime>
#include "Pacman.h"


class Labyrinth {
private:
    int width;
    std::vector<int> tabCases;                      //tableau d'entiers représentant cahcune des cases du tableau
    std::vector<Case> vecCases;                     //tableau de Case (non utilisé) destiné à remplacer le vecteur tabCases pour une meilleur gestion des cases du tableau
    double BonusDuration;
    int* currentBonus;

public:
    //getters
    Labyrinth();
    int getWidth();
    std::vector<int> getLaby();
    int getLabyCaseValue(int x, int y);
    double getBonusDuration() const;

    //setters
    void setWidth(int w);
    void setLaby(std::vector<int> t);
    void setOneCaseLaby(int x, int y, int value);
    void setBonusDuration(double BonusDuration);

    //methods
    void printLaby();
    void updateBonus(glimac::SDLWindowManager windowmanage, Pacman *p);
    void applyBonus(glimac::SDLWindowManager windowmanage, Pacman *p);
};


#endif //IMACGL_LABYRINTH_H
