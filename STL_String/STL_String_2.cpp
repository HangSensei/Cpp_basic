#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

void test01()
{
	string s1 = "hello world";
	string s2 = s1;
	string::iterator it1 = s1.begin();
	while (it1 != s1.end())
	{
		(*it1)--;
		++it1;
	}
	cout << s1 << endl;

	string::const_iterator it2 = s2.begin();
	while (it2 != s2.end())
	{
		//(*it2)--;
		++it2;
	}
	cout << s2 << endl;

	string::reverse_iterator it3 = s2.rbegin();
	while (it3 != s2.rend())
	{
		cout << *it3 << " ";
		++it3;
	}
	cout << endl;

	reverse(s2.begin(), s2.end());

	for (auto e : s2)
	{
		cout << e << " ";
	}
	cout << endl;

}

void test02()
{
	string s1 = "123456";
	cout << s1.max_size() << endl;
	cout << s1.size() << endl;// not include \0
	cout << s1.capacity() << endl;

	string s2;
	size_t old = s2.capacity();// initial capacity
	cout << "initial capacity:" << old << endl;
	for (size_t i = 0; i < 100; i++)
	{
		s2.push_back('x');

		if (s2.capacity() != old)
		{
			cout << "dynamic capacity:" << s2.capacity() << endl;
			old = s2.capacity();
		}
	}
	cout << s1 << endl;
	s1.clear();
	cout << s1 << endl;
	string s3(100, '-');
	cout << s3 << endl;

	cout << "s2 size:" << s2.size() << endl;
	cout << "capacity:" << s2.capacity() << endl;
	//s2.clear();
	cout << "after clear" << endl;
	cout << "s2 size:" << s2.size() << endl;
	cout << "capacity:" << s2.capacity() << endl;

	cout << "s2 initial capacity:" << old << endl;
	for (size_t i = 0; i < 50; i++)
	{
		s2.pop_back();
	}
	s2.shrink_to_fit();
	cout << "s2 size:" << s2.size() << endl;
	cout << "s2 dynamic capacity:" << s2.capacity() << endl;
}

void test03()
{
	string s1 = "123456";
	cout << "size:" << s1.size() << endl;// not include \0
	cout << "capacity:" << s1.capacity() << endl;
	//kaikon¿ª¿Õ¼äÀ©ÈÝ,ËõÈÝno binding
	s1.reserve(1);
	cout << "size:" << s1.size() << endl;// not include \0
	cout << "capacity:" << s1.capacity() << endl;

	string s2 = "123456";
	cout << "size:" << s2.size() << endl;// not include \0
	cout << "capacity:" << s2.capacity() << endl;
	//kaikon¿ª¿Õ¼äÀ©ÈÝ,ËõÈÝno binding
	s2.resize(10,'x');
	cout << "size:" << s2.size() << endl;// not include \0
	cout << "capacity:" << s2.capacity() << endl;
	cout << s2 << endl;
}

void test04()
{
	string s1 = "hello bit";
	s1.append("oh?");
	cout << s1 << endl;
	s1 += "xxxx";
	s1.assign(10, 'y');
	cout << s1 << endl;
	string s2 = "hello world";
	s2.insert(0,"yyyy");
	s2.insert(0, 1, 'x');
	s2.insert(s2.begin(), '!');
	cout << s2 << endl;
	string s3 = "hello world";
	s3.erase(5, 1);
	cout << s3 << endl;
	s3.erase(5);
	cout << s3 << endl;
	s3.replace(4, 1, "xxxx");
	cout << s3 << endl;
	string s5 = "hello world hello bit";
	size_t pos = s5.find(' ');
	while (pos != string::npos)
	{
		s5.replace(pos, 1, "**");
		pos = s5.find(' ', pos+2 );
	}
	cout << s5 << endl;

	string s6;
	for (auto e : s5)
	{
		if (e == ' ')
		{
			s6 += "%%";
		}
		else
		{
			s6 += e;
		}
	}
	cout << s6 << endl;
}

int main()
{
	//test01();
	//test02();
	//test03();
	test04();

	return 0;
}