#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int num=2000000;
    unsigned long long sum = 2;
    for(int i = 3; i < num; i+=2)
    { 
        int count = 0;
        for(int j = 2; j <= sqrt(i); j++)
        {
            if(i % j == 0)
            {
                count++;
            }
        }
        if(count ==0)
        {
            sum+=i;
        }
    }
    cout<<"hiiii: "<<sum<<endl;
    return 0;
}