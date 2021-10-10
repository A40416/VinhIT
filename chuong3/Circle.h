#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include "BasicShape.h"

using namespace std;

class Circle : public BasicShape{ 
private:
    long centerX;
    long centerY;
    double radius;
public:
    Circle(long cX, long cY, double r) {
        centerX = cX;
        centerY = cY;
        radius = r;

        //calcArea();    
    }

    long getCenterX() const{
        return centerX;
    }

    long getCenterY() const{
        return centerY;
    }

    virtual void calcArea() {
        area = 3.14159 * radius * radius;
        cout<<"Area Circle is:  "<<area<<endl;
    }

};

#endif
