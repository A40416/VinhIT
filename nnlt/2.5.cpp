#include <iostream>
using namespace std;
int *newarray(int a[], int size)
{
    int *newarray;
    newarray= new int[size];
    int temp;
    for(int i=0; i<size; i++)
    {
        newarray[i]=a[size-1-i];
    }
    return newarray;
}
int main()
{
    int const size=10;
    int a[size]={1,2,3,4,5,6,7,8,9,10};
    int *b; 
    b=newarray(a,10);
    for(int i=0; i<size; i++)
    {

        cout<<*(b+i)<<" ";
    }
}