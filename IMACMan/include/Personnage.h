//
// Created by Idefix on 02/01/2018.
//

#ifndef IMACGL_PERSONNAGE_H
#define IMACGL_PERSONNAGE_H


class Personnage {
private:
    float speed;
    bool isPrey;

public:
    Personnage();
    void move();
    void eat();
    void die();

    //getters
    int getSpeed();
    bool getIsPrey();

    //setters
    void setSpeed(int s);
    void setIsPrey(bool p);
};


#endif //IMACGL_PERSONNAGE_H
