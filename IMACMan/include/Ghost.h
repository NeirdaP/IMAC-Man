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
    float deactivatedTime;
public:
    float getDeactivatedTime() const;

    void setDeactivatedTime(float deactivatedTime);

private:
    bool active;
public:
    bool isActive() const;

    void setActive(bool active);

public:
    Ghost();
    ~Ghost();
    void move(int action, Labyrinth* laby);
    void moveRandom(Labyrinth* laby);
    void eat(Pacman* p,glimac::SDLWindowManager& windowManager);

    //getters
    float getRegenTimer();

    //setters
    void setRegenTimer(float t);

};


#endif //IMACGL_GHOST_H
