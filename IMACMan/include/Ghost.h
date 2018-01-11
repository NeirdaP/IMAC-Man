//
// Created by Thibault on 02/01/2018.
//

#ifndef IMACGL_GHOST_H
#define IMACGL_GHOST_H

#include <iostream>
#include <string>
#include <vector>
#include "Personnage.h"
#include "Pacman.h"

class Ghost : public Personnage {
private:
    float regenerationTimer;

public:
    Ghost();
    ~Ghost();
    void move(int action, Labyrinth* laby);
    void moveRandom(Labyrinth* laby);
    void eat(Pacman* p);

    //getters
    float getRegenTimer();

    //setters
    void setRegenTimer(float t);

};


#endif //IMACGL_GHOST_H
