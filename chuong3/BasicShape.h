#ifndef BASICSHAPE_H
#define BASICSHAPE_H

#include <iostream>

using namespace std;

class BasicShape {
protected:
    double area;
public:
    BasicShape()
    {
        area=0;
    }
    double getArea() const{
        return area;
    }

    virtual void calcArea() = 0;
};

#endif

