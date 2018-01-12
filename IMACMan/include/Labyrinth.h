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



class Labyrinth {
private:
    int width;
    std::vector<int> tabCases;                      //tableau d'entiers représentant cahcune des cases du tableau
   // std::vector<Case> vecCases;                     //tableau de Case (non utilisé) destiné à remplacer le vecteur tabCases pour une meilleur gestion des cases du tableau
                   //durée d'un bonus temporaire



public:
    //getters
    Labyrinth();
    int getWidth();
    std::vector<int> getLaby();
    int getLabyCaseValue(int x, int y);
    int *randX, *randY;

    //setters
    void setWidth(int w);
    void setLaby(std::vector<int> t);
    void setOneCaseLaby(int x, int y, int value);

    //methods
    void printLaby();
    //applique les bonus au pacman
};


#endif //IMACGL_LABYRINTH_H
