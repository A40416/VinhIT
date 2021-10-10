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
        cout<<Chuvi<<endl;
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
    virtual float caclChuvi()
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
class Cricle : public Shape
{
private:
    float x1;
    float x2;
    float r;
public:
    Circle(float x1,float x2,float r)
    {
        this->x1=x1;
        this->x2=x2;
        this->r=r;
    };
    virtual float caclChuvi()
    {
        return 2*3.14*r;
    };
    void setXxx1(float _x1)
    {
        x1=_x1;
    };
    void setXxx2(float _x2)
    {
        x2=_x2;
    };
    void setR(float _r)
    {
        r=_r;
    };
};
int main()
{
    Shape *a[3]={
        new Rectangle(1,2,4,1),
        new Circle(2,3,5)
    };
    for(int i=0; i<2; i++)
    {
        a[i] -> caclChuvi();
        a[i].print();
    }
    for(int i=0; i<2; i++)
    {
        delete a[i];
    }
    
    return 0;
}
