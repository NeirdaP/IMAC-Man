//
// Created by Idefix on 04/01/2018.
//

#ifndef IMACGL_LABYRINTH_H
#define IMACGL_LABYRINTH_H

#include <iostream>
#include <string>
#include <vector>


class Labyrinth {
private:
    int width;
    std::vector<int> tabCases;

public:
    Labyrinth();

    //getters
    int getWidth();
    std::vector<int> getLaby();

    //setters
    void setWidth(int w);
    void setLaby(std::vector<int> t);
    void setOneCaseLaby(int x, int y, int value);

    void printLaby();
};


#endif //IMACGL_LABYRINTH_H
