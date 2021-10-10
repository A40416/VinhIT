#include <cstdlib>
#include "FeetInches.h"

void FeetInches::simplify() 
{
	if (inches >= 12) 
	{
		feet += (inches/12);
		inches = inches%12;
	} 
	else if (inches < 0) 
	{
		feet -= ((abs(inches) / 12) + 1);
		inches = 12 - (abs(inches) % 12);
	}
}

FeetInches FeetInches::operator + (const FeetInches &right) {
	FeetInches temp;
	temp.inches = inches + right.inches;
	temp.feet = feet + right.feet;
	temp.simplify();
	return temp;
}

FeetInches FeetInches::operator - (const FeetInches &right) {
	FeetInches temp;

	temp.inches = inches - right.inches;
	temp.feet = feet - right.feet;
	temp.simplify();

	return temp;
}

bool FeetInches::operator>= (const FeetInches &right) 
{
	bool status;
	if (feet > right.feet)
	{
		return true;
	} 
	else if (feet == right.feet && inches >= right.inches) 
	{
		status = true;
	} else 
	{
		status = false;
	}
	return status;
}

bool FeetInches::operator <= (const FeetInches &right) {
	bool status;

	if (feet < right.feet) 
	{
		return true;
	} 
	else if (feet == right.feet && inches <= right.inches) 
	{
		status = true;
	} else 
	{
		status = false;
	}

	return status;
}

bool FeetInches::operator != (const FeetInches &right) 
{
	bool status;

	if (feet != right.feet) 
	{
		status = true;
	} else if (feet == right.feet && inches != right.inches) 
	{
		status = true;
	} 
	else 
	{
		status = false;
	}
	return status;

}
ostream &operator << (ostream &strm, const FeetInches &obj) 
{
	strm << obj.feet << " feet," << obj.inches << " inches";
	return strm;
}
istream &operator >> (istream &strm, FeetInches &obj)
{
	cout << "Feet: ";
	strm >> obj.feet;
	cout << "Inches: ";
	strm >> obj.inches;
	obj.simplify();
	return strm;
}
FeetInches FeetInches::multiply(const FeetInches &right)
{
	FeetInches temp;
	temp.feet = feet * right.feet;
	temp.inches = inches * right.inches;

	return temp;
}
FeetInches::operator double()
{
	double temp = feet;
	temp += (inches / 12.0);
	return temp;
}
FeetInches:: operator int()
{
  return feet;
}
