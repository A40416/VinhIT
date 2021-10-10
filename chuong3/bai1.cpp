#include <iostream>
#include "ProductionWorker.h"
#include <string> 
using namespace std;
int main()
{
  ProductionWorker vinh("vinh",2310,26,1,5);
	vinh.Print();
	cout<<"Tong luong: "<<vinh.TongLuong()<<endl;
	ProductionWorker vinh1("vinh",2310,26,2,5);
	vinh1.Print();
	cout<<"Tong luong: "<<vinh1.TongLuong()<<endl;
    system("pause");
    return 0;
}