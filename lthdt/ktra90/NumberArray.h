#ifndef NUMBERARRAY_H
#define NUMBERARRAY_H
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
    double get(int i)
    {
        if(i<0||i>size)
            return -1;
        return a[i];    
    }
    void set(int i, double x)
    {
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

#endif /* NUMBERARRAY_H */
