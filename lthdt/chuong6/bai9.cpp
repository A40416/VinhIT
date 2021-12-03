#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main()
{
    char a;
    fstream file,file1;
    file.open("ok.txt", ios::in);
    file1.open("sieunhan.txt", ios::out);
    while(file.get(a))
    {
        file1.put(a+10);
    }
    file.close();
    file1.close();

    return 0;
}