// 
// Created by Thibault on 02/01/2018.
//

#ifndef IMACGL_PERSONNAGE_H
#define IMACGL_PERSONNAGE_H

#include <iostream>
#include <string>
#include <vector>
#include "../include/Labyrinth.h"


class Personnage {
private:
    bool isAlive;
    float speed;
    float positionX;
    float positionY;
    int direction;      //définit dans quel sens est en train de se déplacer le personnage car s'il va vers la gauche par ex, alors c'est la flèche du bas qui signifie "aller à droite", etc

public:
    Personnage();
    //fonctions virtuelles redéfinies dans les enfants
    virtual void move(int action, Labyrinth* laby){}
    virtual void eat(){}
    virtual void die(){}

    //getters
    bool getIsAlive();
    float getSpeed();
    float getPosX();
    float getPosY();
    int getDirection();

    //setters
    void setIsAlive(bool a);
    void setSpeed(float s);
    void setPosX(float px);
    void setPosY(float py);
    void setPosXY(float px, float py);
    void setDirection(int d);
};




#endif //IMACGL_PERSONNAGE_H
