#include <iostream>
#include <fstream>
#include "NumberArray.h"
using namespace std;
struct ArrayFeature{
    int size;
    int indexmax;
    double max;
    int indexmin;
    double min;
};
ArrayFeature getFeature(NumberArray& n ){
    int size=n.getSize();
    int indexmax=n.getMax();
    double max=n.get(indexmax);
    int indexmin=n.getMin();
    double min=n.get(indexmin);
    return {size, indexmax, max, indexmin, min};
}
int main()
{
    ArrayFeature a[3];
    for(int i=0; i<3; i++){
        int size;
        cout<<"Nhap size: ";
        cin>>size;
        NumberArray aa(size);
        cout<<"Array: ";
        for(int j=0; j<size; j++)
        {
            double x;
            cin>>x;
            aa.set(j,x);
        }
        a[i]=getFeature(aa);
    }

    for(int i=0; i<3; i++)
    {
        cout<<"---------"<<i<<"-----------\n";
        cout<<"Size: "<<a[i].size<<endl;
        cout<<"Index max: "<<a[i].indexmax<<endl;
        cout<<"max: "<<a[i].max<<endl;
        cout<<"Index min: "<<a[i].min<<endl;
        cout<<"Index min: "<<a[i].indexmin<<endl;
    }


    fstream f;
    f.open("Data.dat", ios::out | ios::binary);
    f.write(reinterpret_cast<char*>(a), sizeof(a));
    f.close();

    ArrayFeature _a[3];
    f.open("Data.dat", ios::in | ios::binary);
    f.read(reinterpret_cast<char*>(_a), sizeof(_a));
    f.close();
    cout<<endl<<endl<<endl<<endl;
    for(int i=0; i<3; i++)
    {
        cout<<"---------"<<i<<"-----------\n";
        cout<<"Size: "<<_a[i].size<<endl;
        cout<<"Index max: "<<_a[i].indexmax<<endl;
        cout<<"max: "<<_a[i].max<<endl;
        cout<<"Index min: "<<_a[i].min<<endl;
        cout<<"Index min: "<<_a[i].indexmin<<endl;
    }
    return 0;
}