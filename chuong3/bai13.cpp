#include <iostream>
#include <math.h>
using namespace std;

class Shape
{
private:
    float Chuvi;
public:
    Shape()
    {
        Chuvi=0;
    };
    Shape(float c)
    {
        Chuvi=c;
    };
    virtual float calcChuvi()=0;
    void setInfor(float cv)
    {
        Chuvi= cv;
    };
    float getChuvi() const
    {
        return Chuvi;
    }
    void print()
    {
        cout<<getChuvi()<<endl;
    };

};
class Rectangle : public Shape
{
private:
    float x1;
    float x2;
    float y1;
    float y2;
public:
    Rectangle(float x1,float x2,float y1,float y2)
    {
        this->x1=x1;
        this->x2=x2;
        this->y1=y1;
        this->y2=y2;
    };
    virtual float calcChuvi()
    {
        return 2*abs(x2-x1)*abs(y2-y1);
    };    
    void setXx1(float _x1)
    {
        x1=_x1;
    };
    void setXx2(float _x2)
    {
        x2=_x2;
    };
    void setYy1(float _y1)
    {
        y1=_y1;
    };
    void setYy2(float _y2)
    {
        y2=_y2;
    };
};
class Circle : public Shape
{
private:
    float X1;
    float X2;
    float r;
public:
    Circle(float X1,float X2,float r)
    {
        this->X1=X1;
        this->X2=X2;
        this->r=r;
    };
    virtual float calcChuvi()
    {
        return 2*3.14*r;
    };
    void setXxX1(float _X1)
    {
        X1=_X1;
    };
    void setXxX2(float _X2)
    {
        X2=_X2;
    };
    void setR(float _r)
    {
        r=_r;
    };
};
int main()
{
    Shape *a[3]={
        new Shape(5);
        new Rectangle(1,2,4,1),
        new Circle(2,3,5)
    };
    for(int i=0; i<2; i++)
    {
      cout<<a[i] -> calcChuvi()<<endl;
    }
    return 0;
}
