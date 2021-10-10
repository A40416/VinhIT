#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int a=0, b=0, c=0;
    for(a=1; a<1000; a++)
    {
        for(b=1; b<1000; b++)
        {
            for(c=1; c<1000; c++)
            {
                if((a+b+c==1000)&&(pow(a,2)+pow(b,2)==pow(c,2)))
                    cout<<a<<endl<<b<<endl<<c<<endl;
            }
        }
    }
    return 0;
}
