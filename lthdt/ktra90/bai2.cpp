#include <iostream>
#include <iomanip>
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
    NumberArray(NumberArray &ok)
    {
        size=ok.size;
        a=new double[size];
        for(int i=0; i<size; i++)
        {
            a[i]=ok.a[i];
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
    NumberArray operator +=(double x)
    {
        NumberArray arr;
        for(int i=0; i<size; i++)
        {
            a[i]+=x;
        }
        return arr;
    }
    // void print()
    // {
    //     cout<<"Size: "<< getSize()<<endl;
    //     cout<<"a[]={";
    //     for(int i=0; i<size; i++)
    //     {
    //         cout<<a[i]<<",";
    //     }
    //     cout<<"}";
    // }
    friend ostream &operator <<(ostream &out, NumberArray hi)
    {
        out<<"Size: "<<hi.size<<endl;
        out<<"Cac phan tu: ";
        for(int i=0; i<hi.size; i++)
        {
            out<<hi.a[i]<<"\t";
        }
        out<<endl;
        return out;
    }

};
double max(NumberArray &ok)
    {
        return ok.get(ok.getMax());
    }
int main()
{
    NumberArray a(5,10.6); //tao 5pt=10
    cout<<a;
    cout<<"------------------\n";
    NumberArray b(a); //sao chep cau tu
    b+=5; //+moi ptu voi 5
    cout<<b;

    //cout<<setprecision(1);
    NumberArray n(3, 4.5);
    n.set(0, 5.1);
    n.set(2, -3.2);
    cout<<max(n)<<endl;

}