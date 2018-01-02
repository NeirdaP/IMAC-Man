//
// Created by Thibault on 02/01/2018.
//

#ifndef IMACGL_PERSONNAGE_H
#define IMACGL_PERSONNAGE_H

#include <iostream>
#include <string>
#include <vector>


class Personnage {
private:
    float speed;
    bool isPrey;

public:
    Personnage();
    virtual void move();
    virtual void eat();
    void die();

    //getters
    float getSpeed();
    bool getIsPrey();

    //setters
    void setSpeed(float s);
    void setIsPrey(bool p);
};


#endif //IMACGL_PERSONNAGE_H
