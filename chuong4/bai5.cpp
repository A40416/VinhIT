#include <iostream>
using namespace std;

template <class T>
T Total(int size) {
	T a[size];
	T sum=0;
	cout << "Enter: \n";
	for (int i = 0; i < size; i ++) {
		cin >> a[i];
		sum += a[i];
	}	
    return sum;
}

int main() {
    cout <<"Tinh tong cac so nguyen: \n"<< Total<int>(3)<<endl;
	cout <<"Tinh tong cac so thuc: \n"<< Total<double>(3)<<endl;
	cout <<"Tinh tong cac ki tu: \n"<< Total<char>(3)<<endl;
	return 0;
}

