#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <assert.h>
#include <iostream>
using namespace std;

class Date
{
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);

public:
	int GetMonthDay(int year, int month)//this is a inline fuction (frequent using)
	{
		assert(month >= 1 && month <= 12);
		static int monthDayArr[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (month == 2 
			&& (( year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		{
			return 29;
		}
		else
		{
			return monthDayArr[month];
		}
	}
	Date(int year = 1, int month = 1, int day = 1);//default constructor
	//Date(const Date& d);// copy construction
	/*Date operator=(const Date& d);*/
	void Print();
	Date& operator+=(int day);//operator overloading
	Date operator+(int day);

	Date& operator-=(int day);
	Date operator-(int day);

	Date& operator++();//++d;
	Date operator++(int);//d++;

	Date& operator--();//--d;
	Date operator--(int);//d--;

	bool operator==(const Date& d) const;
	bool operator!=(const Date& d) const;

	bool operator<(const Date& d) const;
	bool operator<=(const Date& d) const;

	bool operator>(const Date& d) const;
	bool operator>=(const Date& d) const;

	int operator-(const Date& d) const;

	bool CheckDate();

	/*Date* operator&()
	{
		return this;
		return nullptr;//could not access the address
		return (Date*)0x00FF1200; // return fake address
	}

	const Date* operator&()const
	{
		return this;
		return nullptr;
		return (Date*)0x00FF1223; // return fake address
	}*/

	
private:
	int _year;
	int _month;
	int _day;
};
// Global function 
ostream& operator<<(ostream& out, const Date& d);
istream& operator>>(istream& in, Date& d);
