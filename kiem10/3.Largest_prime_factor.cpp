
#include <iostream>
#include <math.h>
using namespace std;
 
 
int main(){
    // long n;
    // cout << "\nNhap n = ";
    // cin >> n;
    long long n=147147147147;
    int max=0; 
    for(int i = 3; i < 1000000; i+=2)
    {
        if(n%i==0)
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
                max=i;
            }
        }
    }
    cout<<"Thua so nguyen to lon nhat = "<<max<<endl; 
}