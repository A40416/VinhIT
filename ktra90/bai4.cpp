#include <iostream>
#include <string>
using namespace std;
template <class T>
class NumberArray
{
private:
    T *a;
    int size;
public:
    NumberArray()
    {

    }   
    NumberArray(int n)
    {
        size=n;
        a= new T[n];
    } 
    NumberArray(int n, T value)
    {
        size=n;
        a= new T[n];
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
    T get(int i)
    {
        if(i<0||i>size)
            return -1;
        return a[i];    
    }
    void set(int i, T x)
    {
        
        if(i<0||i>size)
            cout<<"Khong hop le!!";
        a[i]=x;    
    }
    int getMax()
    {
        T max=a[0];
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
        T min=a[0];
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
    }
};
int main()
{
    NumberArray <string> vinh(10,"vinh");
    vinh.print();
    for(int i=1; i<vinh.getSize(); i+=2)
    {
        vinh.set(i,"pro");
    }
    vinh.print();
    
    
}