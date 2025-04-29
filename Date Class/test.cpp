#include "Date.h"

void test01()
{
	Date d1(2024, 4, 26);
	d1.Print();
	//Date d2(d1 + 100);
	Date d2 = d1 += 100;
	d2.Print();
	Date d3(2025, 4, 28);
	d1 = d2 = d3;
	d2.Print();
	d1.Print();

}
void test02()
{
	Date d1(2025, 4, 26);
	Date d2 = d1 -= 10000;
	d1.Print();
	d2.Print();
	Date d3(2025, 4, 26);
	Date d4 = d3 - 10000;
	d3.Print();
	d4.Print();
}
void test03()
{
	Date d1(2025, 4, 26);
	Date d2 = ++d1;
	d1.Print();//27
	d2.Print();//27

	Date d3(2025, 4, 26);
	Date d4 = d3++;
	d3.Print();//27
	d4.Print();//26

	Date d5(d4);
	//Date d6 = d5.operator--();
	Date d6 = ++d5;
	d5.Print();//25
	d6.Print();//25

	Date d7(d5);
	//Date d8 = d7.operator--(1);
	Date d8 = d7++;
	d7.Print();//24
	d8.Print();//25

}
void test04()
{
	Date d1(2025, 4, 26);
	Date d2(2025, 5, 1);
	cout << (d1 < d2) << endl;
	cout << (d1 >= d2) << endl;

	cout << (d1 - d2) << endl;

}
void test05()
{
	Date d1(2025, 4, 31);
	Date d2(2025, 7, 1);
	cout << d1;
	operator<<(cout, d1);

	cin >> d1 >> d2;
	cout << d1 - d2 << endl;
}
int main()
{
	//test01();
	//test02();
	//test03();
	//test04();
	test05();

	return 0;
}
