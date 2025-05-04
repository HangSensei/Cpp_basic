#define _CRT_SECURE_NO_WARNINGS

//JZ64 求1+2+3+...+n
//描述
//求1 + 2 + 3 + ... + n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A ? B : C）。

//class Solution {
//    class Sum {
//    public:
//        Sum() {
//            _ret += _i;
//            ++_i;
//        }
//    };
//public:
//    int Sum_Solution(int n) {
//        Sum arr[n];
//        return _ret;
//    }
//private:
//    static int _i;
//    static int _ret;
//};
//int Solution::_i = 1;
//int Solution::_ret = 0;

//KY222 打印日期
//描述
//给出年分m和一年中的第n天，算出第n天是几月几号。
//输入描述：
//输入包括两个整数y(1 <= y <= 3000)，n(1 <= n <= 366)。
//输出描述：
//可能有多组测试数据，对于每组数据， 按 yyyy - mm - dd的格式将输入中对应的日期打印出来。

//#include <iostream>
//using namespace std;
//class Date
//{
//public:
//    static int GetMonthDay(int year, int month)
//    {
//        static int arr[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//        if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
//        {
//            return 29;
//        }
//        else
//        {
//            return arr[month];
//        }
//    }
//};
//
//int main()
//{
//    int day = 0;
//    int month = 1;
//    int year = 0;
//    while (cin >> year >> day)
//    {
//        month = 1;
//        while (day - Date::GetMonthDay(year, month) > 0)
//        {
//            day -= Date::GetMonthDay(year, month);
//            ++month;
//            if (month > 12)
//            {
//                ++year;
//                month = 1;
//            }
//        }
//        printf("%04d-%02d-%02d\n", year, month, day);
//    }
//    return 0;
//}

//KY257 日期累加
//描述
//设计一个程序能计算一个日期加上若干天后是什么日期。
//输入描述：
//输入第一行表示样例个数m，接下来m行每行四个整数分别表示年月日和累加的天数。
//输出描述：
//输出m行，每行按yyyy - mm - dd的个数输出。
//示例1
//输入：1
//输出：2008 2 3 100


#include <iostream>
#include <iomanip> 
using namespace std;
class Date
{
    friend ostream& operator<<(ostream& out, const Date& d);
public:
    Date(int year, int month, int day)
        :_year(year)
        , _month(month)
        , _day(day)
    {
    }

    int GetMonthDay(int year, int month)
    {
        static int arr[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        if (month == 2 && (year % 4 == 0 && year % 100 != 0 || (year % 400 == 0)))
        {
            return 29;
        }
        else
        {
            return arr[month];
        }
    }

    Date& operator+=(int adds)
    {
        _day += adds;
        while (_day > GetMonthDay(_year, _month))
        {
            _day -= GetMonthDay(_year, _month);
            ++_month;
            if (_month > 12)
            {
                _month = 1;
                ++_year;
            }
        }
        return *this;
    }
private:
    int _year;
    int _month;
    int _day;
};

ostream& operator<<(ostream& out, const Date& d)
{
    out << setw(4) << setfill('0') << d._year << '-'
        << setw(2) << setfill('0') << d._month << '-'
        << setw(2) << setfill('0') << d._day << endl;
    return out;
}

int main()
{
    int m, year, month, day, adds;
    cin >> m;
    while (m--)
    {
        cin >> year >> month >> day >> adds;
        Date d1(year, month, day);
        Date d2 = d1 += adds;
        cout << d2;

    }

    return 0;
}
