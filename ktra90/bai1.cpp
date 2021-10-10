#include <iostream>
//#include "NumberArray.h"
using namespace std;
class NumberArray
{
private:
    double *a;
    int size;
public:
    NumberArray()
    {

    }   
    NumberArray(int n)
    {
        size=n;
        a= new double[n];
        for(int i=0; i<n; i++)
        {
            a[i]=0;
        }
    } 
    NumberArray(int n, double value)
    {
        size=n;
        a= new double[n];
        for(int i=0; i<n; i++)
        {
            a[i]=value;
        }
    }
    ~NumberArray()
    {
        delete[] a;
    }
    int getSize()
    {
        return size;
    }
    int get(int i)
    {
        if(i<0||i>size)
            return -1;
        return a[i];    
    }
    void set(int i, double x)
    {
        
        if(i<0||i>size)
            cout<<"Khong hop le!!";
        a[i]=x;    
    }
    int getMax()
    {
        double max=a[0];
        int pos=0;
        for(int i=0 ; i<size;++i)
        {
            if (a[i]>max)
            { 
                max=a[i];
                pos=i;
            }
        }
        return pos;
    }
    int getMin()
    {
        double min=a[0];
        int pos=0;
        for(int i=0 ; i<size;++i)
        {
            if (a[i]<min)
            { 
                min=a[i];
                pos=i;
            }
        }
        return pos;
    }
    void print()
    {
        cout<<"Size: "<< getSize()<<endl;
        cout<<"a[]={";
        for(int i=0; i<size; i++)
        {
            cout<<a[i]<<",";
        }
        cout<<"}";
        cout<<endl;
    }
};
int main()
{
    NumberArray a1(5);
    a1.print();
    cout<<"-----------\n";
    NumberArray a(10,10); //10pt=10
    a.print();
    cout<<"------------\n";
    cout<<"Size: "<<a.getSize()<<endl;
    a.set(2,5); //a[2]=5
    a.set(5,20); // a[5]=20
    a.set(6,100); //a[6]=100
    cout<<"Gtri thu5: "<<a.get(5)<<endl; // in 20
    cout<<"Position max: "<< a.getMax()<<endl;
    cout<<"MMMax: "<<a.get(a.getMax())<<endl;
    cout<<"Position min: "<< a.getMin()<<endl;
    cout<<"MMMin: "<<a.get(a.getMin())<<endl;
    a.print();
    
}