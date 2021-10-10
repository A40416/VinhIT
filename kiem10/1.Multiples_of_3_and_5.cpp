#include <iostream>
using namespace std;
int main()
{
    int sum=0;
    for(int i=1; i<1000; i++)
    {
        if(i%3==0)
            sum+=i;
        if(i%5==0)
            sum+=i;
        if((i%3==0)&&(i%5==0))  
            sum-=i;      
    }
    cout<<"Tong cac so chia het 3 va 5 duoi 1000 la: "<< sum<<endl;
    return 0;
}