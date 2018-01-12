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
    std::vector<int> tabCases;
    std::vector<Case> vecCases;
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
