#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include "BasicShape.h"

using namespace std;

class Rectangle : public BasicShape{
private:
    long width;
    long length;
public:
    Rectangle(long w, long l) {
        width = w;
        length = l;

        //calcArea();
    }

    long getWidth() const{
        return width;
    }

    long getLength() const{
        return length;
    }

    virtual void calcArea() {
        area = length * width;
        cout<<"Area Rectangle is:  "<<area<<endl;
    }
};

#endif
