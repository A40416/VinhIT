#include <iostream>
using namespace std;
int Fibonacci(int n)
{
    int sum=0;
    int a1=1;
    int a2=2;
    int a3=0;
    while (a3 <= n)
    {
        a3 = a1 + a2;
        cout<<a2<<" "<<a3<<endl;
        if (a2%2==0)
            sum+=a2;
        a1 = a2;
        a2 = a3;
    }
    return sum;
}
int main()
{
    cout<<Fibonacci(4000000);
    
    return 0;
}
