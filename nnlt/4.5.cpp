#include <iostream>
using namespace std;
int *newarray(int a[], int size, int k)
{
    int *newarray;
    newarray= new int[size*k];
    for(int i=0; i<k; i++)
    {
        for(int j=0; j< size; j++)
        {
            newarray[j+i*size]=a[j];
        }
    }
    return newarray;
}
int main()
{
    int const size=10;
    int a[size]={1,2,3,4,5,6,7,8,9,10};
    int *b; 
    b=newarray(a,10,10);
    for(int i=0; i<100; i++)
    {

        cout<<*(b+i)<<" ";
    }
}