#include <iostream>
#include "Stopwatch.h"
using namespace std;
int main()
{
    Stopwatch a(3,4,5), b(6,7,8),c=a+b;
    c.print();

    return 0;
}
