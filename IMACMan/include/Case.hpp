#ifndef IMACGL_CASE_HPP
#define IMACGL_CASE_HPP

#include "Model.hpp"

class Case : public Model{
private:
    int m_x;
    int m_y;


public:
    Case(){};
    Case(int x, int y);
};


#endif //IMACGL_CASE_HPP
