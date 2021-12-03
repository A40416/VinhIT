#include <iostream>
#include "FilterArray.h"
#include "NumberArray.h"
using namespace std;

int main()
{
    NumberArray a(4, 5.6);
    a.set(0, 2.4);
    a.set(1, 5.4);
    a.set(2, 9.4);
    a.print();

    FilterArray* fa[6]={
        new FACopy(),
        new FAInteger(),
        new FAAdd(1.4),
        new FAAdd(22),
        new FAAdd(1.9),
        new FAAdd(3.5)
    };
    for(int i=0; i<6; i++)
    {
        cout<<"------"<<i<<"-------\n";
        fa[i] -> doFilter(a).print();
    }
    return 0;
}