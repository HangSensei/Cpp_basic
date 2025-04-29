#include "Date.h"

Date::Date(int year, int month, int day)//default constructor
{
	_year = year;
	_month = month;
	_day = day;

	if (!CheckDate())
	{
		cout << "invalid date-> " << *this << endl;
	}
}

bool Date::CheckDate()
{
	if (_month < 1 || _month > 12 || _day < 1 || _day > GetMonthDay(_year, _month))
	{
		return false;
	}
	else
	{
		return true;
	}
}

//Date::Date(const Date& d)//copy construction
//{
//	_year = d._year;
//	_month = d._month;
//	_day = d._day;
//}
//
//Date& Date::operator=(const Date& d)// overloading the assignment operator
//{
//	if (this != &d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//
//	return *this;
//}
void Date::Print()
{
	cout << _year << "/" << _month << "/" << _day << endl;
}
Date& Date::operator+=(int day)
{
	if (day < 0)// if day is a negative num 
	{
		return *this -= -day;
	}
	_day += day;
	// carry
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		_month++;
		if (_month >= 13)
		{
			_month = 1;
			_year++;
		}
	}
	return *this;
}

Date Date::operator+(int day)
{
	Date tmp = *this;
	tmp += day;

	return tmp;
}

Date& Date::operator-=(int day)
{
	if (day < 0)// if day is a negative num 
	{
		return *this += -day;
	}
	_day -= day;
	while (_day < 1)
	{
		--_month;
		if (_month < 1)
		{
			_month = 12;
			--_year;
		}

		_day += GetMonthDay(_year, _month);
	}

	return *this;
}

Date Date::operator-(int day)
{
	Date tmp(*this);
	tmp -= day;

	return tmp;
}

Date& Date::operator++()
{
	*this += 1;
	return *this;
}

Date Date::operator++(int)
{
	Date tmp(*this);
	*this += 1;
	return tmp;
}

Date& Date::operator--()
{
	*this -= 1;
	return *this;
}

Date Date::operator--(int)
{
	Date tmp(*this);
	*this -= 1;
	return tmp;
}

bool Date::operator == (const Date& d) const
{
	return _year == d._year
		&& _month == d._month
		&& _day == d._day;
}
bool Date::operator != (const Date& d) const
{
	return !(*this == d);
}

bool Date::operator < (const Date& d) const
{
	if (_year < d._year)
	{
		return true;
	}
	else if (_year == d._year && _month < d._month)
	{
		return true;
	}
	else if (_year == d._year && _month == d._month && _day < d._day)
	{
		return true;
	}
	return false;
}
bool Date::operator <= (const Date& d) const
{
	return *this < d || *this == d;
}

bool Date::operator > (const Date& d) const
{
	return !(*this <= d);
}
bool Date::operator >= (const Date& d) const
{
	return !(*this < d);
}

int Date::operator-(const Date& d) const// Date d1 - Date d2
{
	Date max = *this;
	Date min = d;
	int flag = 1;
	if (*this < d)
	{
		max = d;
		min = *this;
		flag = -1;
	}

	int n = 0;
	while (min != max)
	{
		++min;
		++n;
	}
	return n * flag;
}

ostream& operator<<(ostream& out, const Date& d)
{
	out << "Year:" << d._year << " Month:" << d._month << " Day:" << d._day << endl;
	return out;
}

istream& operator>>(istream& in, Date& d)
{
	while (1)
	{
		cout << "Please Enter the Year / Month / Date" << endl;
		in >> d._year >> d._month >> d._day;
		if (d.CheckDate())
		{
			break;
		}
		else
		{
			cout << "invalid date, please re-enter" << endl;
		}
	}
	return in;
}