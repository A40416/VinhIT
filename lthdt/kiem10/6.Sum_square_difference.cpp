#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int sum1=0, sum2=0, key=0;
    for(int i=1; i<=100; i++)
    {
        sum1+=pow(i,2);
        sum2+=i;
    }
    sum2=pow(sum2,2);
    key=sum2-sum1;
    cout<<"hiiiiii: "<< key<<endl;
    return 0;
}