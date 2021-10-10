#include <iostream>
using namespace std;
class Point
{
public: 
	double x, y; 
	Point (double x, double y) : x(x), y(y) {}
}; 
class PhepBienDoi : public Point
{
    virtual void bienDoi(Point &a)=0;
    int bienDoimang(Point a, int size)
    {
        for(int i=0; i<size; i++)
        {
            a[i].bienDoi();
        }
    }
    
};
class LatDoc : public Point
{
    private: 
      double axis;
    public:
    LatDoc()
    {

    }  
    LatDoc( double a)
    {
        axis=a;
    }
    void bienDoi(Point &a)
    {
        a.y=2*axis-y;
    }
};
class LatNgang : public Point
{
    private: 
        double axis;
    public:
        LatNgang()
        {

        }  
        LatNgang( double a)
        {
            axis=a;
        }
        void bienDoi(Point &a)
        {
            a.x=2*axis-x;
        }
};
class PhepDich : public Point
{
    private: 
        double shift_x ;
        double shift_y ;
    public:
        PhepDich()
        {

        }  
        PhepDich( double a,double b)
        {
            shift_x=a ;
            shift_y=b;
        }
        void bienDoi(Point &a)
        {
            a.x=x+shift_x;
            a.y=y+shift_y;
        }
};
int main()
{
    Point *a[3]={
        new LatDoc(5);
        new LatNagng(6);
        new PhepDich(5,99)
    };
    for(i=0; i<3; i++)
    {
        a[i]->bienDoi(a);
    }
}