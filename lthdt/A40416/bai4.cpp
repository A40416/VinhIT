#include <iostream>
using namespace std;
class Date {
	private:
		int day, month, year;
	public:
		Date() { };
		Date(int _day, int _month, int _year) {
			day = _day;
			month = _month;
			year = _year;
		}
		
		void print() {
			cout << day << "/" << month << "/" << year << endl;
		}
        Date operator +(unsigned int x)
        {
            Date a;
            a.day= day+x;
            if(a.day>30)
                a.month+=1;
            if(a.month>12)
                a.year+=1;
            return a;		
        }
};
class Sinhvien : public Date
{
    private:
        string Msv;
        string hoten;
        Date ngay;
        static int count;
    public:
        Sinhvien()
        {
            count++;
        }
        Sinhvien(string m, string h, Date n)
        {
            Msv=m;
            hoten=h;
            ngay=n;
            count++;
        }
        static int getCount() 
        {
            return count;
        }
};
int Sinhvien::count = 0;
