#include <string>
class Date
{
private:
	int ngay, thang, nam;
	char a;
public:
	Date()
	{
		ngay = 0;
		thang = 0;
		nam = 0;
		a = 'r';
	}

	Date(int angay, int athang, int anam, char aa)
	{
		if (athang == 2)
		{
			if (angay > 29)
			{
				angay = 29;
			}
		}
		else
		{
			if (athang < 8)
			{
				if (athang <= 0)
					athang = 1;
				if (athang % 2 == 1)
				{
					if (angay > 31)
					{
						angay = 31;
					}
				}
				else if (athang % 2 == 0)
				{
					if (angay > 30)
					{
						angay = 30;
					}
				}
			}
			else
			{
				if (athang > 12)
				{
					athang = 12;
				}
				if (athang % 2 == 0)
				{
					if (angay > 31)
					{
						angay = 31;
					}
				}
				else if (athang % 2 == 1)
				{
					if (angay > 30)
					{
						angay = 30;
					}
				}
			}
		}
		if (angay <= 0)
			angay = 1;
		ngay = angay;
		thang = athang;
		nam = anam;
		a = aa;
    }

	Date(int angay, int athang, int anam)
	{
		if (athang == 2)
		{
			if (angay > 29)
			{
				angay = 29;
			}
		}
		else
		{
			if (athang < 8)
			{
				if (athang <= 0)
					athang = 1;
				if (athang % 2 == 1)
				{
					if (angay > 31)
					{
						angay = 31;
					}
				}
				else if (athang % 2 == 0)
				{
					if (angay > 30)
					{
						angay = 30;
					}
				}
			}
			else
			{
				if (athang > 12)
				{
					athang = 12;
				}
				if (athang % 2 == 0)
				{
					if (angay > 31)
					{
						angay = 31;
					}
				}
				else if (athang % 2 == 1)
				{
					if (angay > 30)
					{
						angay = 30;
					}
				}
			}
		}
		if (angay <= 0)
			angay = 1;
		ngay = angay;
		thang = athang;
		nam = anam;
		a = 'r';
	}
	friend ostream& operator<<(ostream& out, Date p)
	{
		if (p.a == 'd')
		{
			out << "Ngày " << p.ngay << " tháng " << p.thang << " nãm " << p.nam;
			return out;
		}
		else if (p.a == 'r')
		{
			string day = to_string(p.ngay);
			string month = to_string(p.thang);
			string year = to_string(p.nam);
			if (day.length() == 1)
			{
				day = "0" + day;
			}
			if (month.length() == 1)
			{
				month = "0" + month;
			}
			out << day + "/" + month + "/" + year;
			return out;
		}
	}

};
