#include <iostream>
#include <cmath>
using namespace std;
template <class T>
T absolute(T a)
{
	return abs(a);
}

int main()
{
	int a;
	double b;
	cout <<" nhap a: ";
	cin>>a;
	cout<<" gia tri tuyet doi cua a: " <<absolute<int>(a)<<endl;
		cout <<" nhap b: ";
	cin>>b;
	cout<<" gia tri tuyet doi cua b: " <<absolute<float>(b)<<endl;
	return 0;
}
