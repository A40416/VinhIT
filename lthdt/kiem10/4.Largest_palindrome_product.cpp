#include <iostream>
#include<stdio.h>
using namespace std;
int ktra(int num)
{
    int temp, r, sum=0;
    for(temp=num;num!=0;num=num/10){
         r=num%10;
         sum=sum*10+r;
    }
    if(temp==sum)
      return 1;
    else
      return 0;
}
int main()
{
    int a,max=0;
    for(int i=999; i>100; i--)
    {
        for(int j=999; i>100; j--)
        {
            a=ktra(i*j);
            if(a==1)
            {
                if((i*j)>max)
                    max=i*j;
                break;
            }

            
        }
    }
    cout<<max;
    
    return 0;
}