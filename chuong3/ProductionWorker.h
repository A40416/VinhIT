#ifndef PRODUCTIONWORKER_H
#define PRODUCTIONWORKER_H
#include "Employee.h"
#include <string> 
using namespace std;
class ProductionWorker : public Employee
{
	private:
		int ca;
		int luong1h;
	public:
	ProductionWorker() : Employee()
	{

	}
	ProductionWorker(string a, int b, int c, int d, int e) : Employee(a, b, c)
	{
		ca=d;
		luong1h=e;
	}
	void setCa(int d)
	{
		ca=d;
	}
	void setLuong(int e)
	{
		luong1h=e;
	}
	
	string const getCa()
	{
		if (ca==1)
			return "Ngay";
		return "Dem";	
	}
	int getLuong()
	{
		return luong1h;
	}
	double TongLuong()
	{
		int total=0;
		if (ca==1)
		{
			total=getNgay()*luong1h*24;
		}
		else if (ca==2)
		{
			total=getNgay()*luong1h*24*1.5;
		}
		return total;
	}
	void Print ()
	{
		cout<<"Ten: "<<getTen()<<endl;
		cout<<"Ma so: "<<getMaso()<<endl;
		cout<<"So ngay thue: "<<getNgay()<<endl;
		cout<<"Ca: "<<getCa()<<endl;
		cout<<"Luong/1h= "<<getLuong()<<endl;
	}

};
#endif