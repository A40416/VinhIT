#include <iostream>
#include <math.h>
using namespace std;
 
 
int main()
{
    int num= 10001;
    int xxxxx=0;
    while (xxxxx<=num)
    {
        for(int i = 2; i < 9999999; i++)
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
                xxxxx++;
                if(xxxxx==num)
                { 
                    cout<< i<< endl;
                    break;
                }
            }
        }
    }
    return 0;
}