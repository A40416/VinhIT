#include <iostream>
using namespace std;
bool Prime(int n)
{
    bool check=false;
    int count =0;
    for(int i=2; i<n; i++)
    {
        if(n%i==0)
            count++;
    }
    if(count ==0)
    {
        check=true;
        return check;
    }
    return check;
}
int main()
{
    for(int i=2; i<100; i++)
    {
        if(Prime(i)==1)
        {
            cout<<i<<endl;
        }
    }
    return 0;
}