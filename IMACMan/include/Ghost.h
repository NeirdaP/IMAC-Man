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
    float regenerationTimer; //temps au bout duquel le fantôme se régénère
    float deactivatedTime;  // moment ou le fnatôme a été désactivé
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
    void move(int action, Labyrinth* laby); //déplacement fantôme
    void moveRandom(Labyrinth* laby); //déplacement aléatoire des fantômes
    void eat(Pacman* p,glimac::SDLWindowManager& windowManager); // gstion de qui mange qui

    //getters
    float getRegenTimer();

    //setters
    void setRegenTimer(float t);

};


#endif //IMACGL_GHOST_H
