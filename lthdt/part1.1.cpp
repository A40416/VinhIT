#include <iostream>
#include "Stopwatch.h"
using namespace std;
int main()
{
	// int h, m, s;
	// do
	// {
	// cout<<"Nhap gio phut giay: ";
	// cin>>h>>m>>s;
	// } while (!(h>=0 && h<=100 && m>=0 && m<=59 && s >=0 && s <= 59));
	// Stopwatch a(h, m, s);
	// a.print();
	// cout<<a.getHour()<<endl;
	// cout<<a.getSecond()<<endl;

    int h, m, s;
	cout<<"Nhap gio phut giay: ";
	cin>>h>>m>>s;
    Stopwatch time(h,m,s);
    time.print();
	for(int i=0; i<20; i++)
	{
		time.run(5);
		time.print();
	}

}