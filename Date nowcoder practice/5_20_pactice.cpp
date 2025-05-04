#define _CRT_SECURE_NO_WARNINGS

//JZ64 ��1+2+3+...+n
//����
//��1 + 2 + 3 + ... + n��Ҫ����ʹ�ó˳�����for��while��if��else��switch��case�ȹؼ��ּ������ж���䣨A ? B : C����

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

//KY222 ��ӡ����
//����
//�������m��һ���еĵ�n�죬�����n���Ǽ��¼��š�
//����������
//���������������y(1 <= y <= 3000)��n(1 <= n <= 366)��
//���������
//�����ж���������ݣ�����ÿ�����ݣ� �� yyyy - mm - dd�ĸ�ʽ�������ж�Ӧ�����ڴ�ӡ������

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

//KY257 �����ۼ�
//����
//���һ�������ܼ���һ�����ڼ������������ʲô���ڡ�
//����������
//�����һ�б�ʾ��������m��������m��ÿ���ĸ������ֱ��ʾ�����պ��ۼӵ�������
//���������
//���m�У�ÿ�а�yyyy - mm - dd�ĸ��������
//ʾ��1
//���룺1
//�����2008 2 3 100


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
