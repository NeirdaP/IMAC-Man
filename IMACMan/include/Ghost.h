//
// Created by Idefix on 02/01/2018.
//

#ifndef IMACGL_GHOST_H
#define IMACGL_GHOST_H

#include <iostream>
#include <string>
#include <vector>
#include "Personnage.h"

class Ghost : public Personnage {
private:
    float regenerationTimer;

public:
    Ghost();

    void move();
    void eat();

    //getters
    float getRegenTimer();

    //setters
    void setRegenTimer(float t);

};


#endif //IMACGL_GHOST_H
