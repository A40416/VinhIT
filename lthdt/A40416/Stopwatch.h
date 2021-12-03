#ifndef ABC_H
#define ABC_H
using namespace std;
class Stopwatch
{
private:
	int hour;
	int minute;
	int second;
    void normalize();
public:
	Stopwatch()
	{
		hour=0;
		minute=0;
		second=0;
	};
	Stopwatch(int h = 0, int m = 0, int s = 0)
	{
		hour = h;
		minute = m;
		second = s;
        normalize();
	};
	void setHour(int h)
	{
		hour=h;
		normalize();
	};
	void setSecond(int s)
	{
		second=s;
		normalize();
	};
	int setSecond()
	{
		return hour*3600+minute*60+second;
	}
	void setMinute(int m)
	{
		minute=m;
		normalize();
	};
	int getSecond() const
	{
		return hour * 3600 + minute * 60 + second;
	};
	void print() const
	{
		cout<<hour<<":";
		cout<<minute<<":";
		cout<<second<<endl;
	};
	
};

#endif

void Stopwatch::normalize()
{
	if(hour>100)
	{
		hour=hour%100;
	}
	if(minute>59)
	{
		int a= minute/60;
		minute=minute%60;
		hour= hour+a;
	}
	if(second>60)
	{
		int b= second/60;
		second=second%60;
		minute= minute+b;
	}
}

