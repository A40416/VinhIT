#ifndef SHIFT_H
#define SHIFT_H
#include "Employee.h"
#include <string>
using namespace std;
class ShiftSupervisor: public Employee
{
	private:
		float luong1nam=0;
		float thuong=0;
	public:
		ShiftSupervisor()
		{

		};
		ShiftSupervisor(string a, int b, int c, float d): Employee(a,b,c)
		{
			luong1nam=d;
		};
		void setLuong1(float d)
		{
			luong1nam=d;
		
		};
		float getLuong1()
		{
			return luong1nam;
		}
		void setThuong(float e)
		{
			thuong=e;
		};
		float getThuong()
		{
			if (getNgay()==365)
				thuong= luong1nam*3/12.0;
			else 
				thuong=3*(luong1nam/12*(getNgay()/30)/12);
		  return (float)thuong;
		};
		float total()
		{
			return luong1nam+thuong*1.0;
		};
		void Print ()
	 {
		cout<<"Ten: "<<getTen()<<endl;
		cout<<"Ma so: "<<getMaso()<<endl;
		cout<<"So ngay thue: "<<getNgay()<<endl;
		cout<<"Tien luong= $"<<getLuong1()<<endl;
		cout<<"Tien thuong= $"<<getThuong()<<endl;
		cout<<"Tong luong= $"<<(float)total()<<endl;
	 };

};
#endif