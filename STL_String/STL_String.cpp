#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<algorithm>

#include<vector>
#include<list>

using namespace std;
void test01()
{
	string s1;//construct empty string
	string s2("hello world");// using constant string to construct
	string s3(s2);//copy construction
	string s4(s2, 0, 7);// copy string constructor (partial copy) 
	//substring (4)	string(const string & str, size_t pos, size_t len = npos);
	string s5(s2, 0, 100); // size_t len = npos
	string s6(s2, 0); // size_t len = npos = -1 = size_t MAX
	const char* str = "hello world";
	string s7(str, 7); // Copies the first n characters from the array of characters pointed by s.
	string s8(100, '*');// fill

	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
	cout << s5 << endl;
	cout << s6 << endl;
	cout << s7 << endl;
	cout << s8 << endl;

	string s9;
	string s10;
	string s11;
	s9 = s2;
	s10 = "xxx";
	s11 = 'y';
	cout << s9 << endl;
	cout << s10 << endl;
	cout << s11 << endl;
}

void test02()
{
	string s0 = "hello world";
	const string s1 = "hello world";
	s0[1]++; // s0.operator[](0)++
	//s1[1]++;
	cout << s0 << endl;

	for (size_t i = 0; i < s0.size(); i++ )
	{
		s0[i]++;
	}
	cout << s0 << endl;

	//迭代器 iterator
	//[begin(), end())
	string::iterator iter = s0.begin();
	while (iter != s0.end())
	{
		(*iter)--;
		iter++;
	}
	cout << s0 << endl;

}

void test03()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	vector<int>::iterator it1 = v.begin();
	while (it1 != v.end())
	{
		cout << *it1 << " ";
		it1++;
	}
	cout << endl;


	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);

	list<int>::iterator it2 = lt.begin();
	while (it2 != lt.end())
	{
		cout << *it2 << " ";
		it2++;
	}
	cout << endl;

	reverse(v.begin(), v.end());
	reverse(lt.begin(), lt.end());

}

void test04()
{
	//range for: C++11
	auto x = 10; // auto type
	auto y = 10.1;
	cout << x << endl;
	cout << y << endl;
	int& z = x;
	auto m = z;// copy
	//auto& m = z; // reference
	// Both of them are int*
	auto p1 = &x; // can be all type value
	auto* p2 = &x; // only pointers

	string s1 = "hello bit";
	// auto iteration
	for (auto& ch : s1)
	{
		ch--;
	}
	cout << endl;

	for (auto ch : s1)
	{
		cout << ch << " ";
	}
	cout << endl;

	int arr[] = { 1, 2, 3, 4, 5, 6, 7 ,8, 9, 10 };
	for (auto a : arr)
	{
		cout << a << " ";
	}
	cout << endl;

}

int main()
{
	//test01();
	//test02();
	//test03();
	test04();

	return 0;
}