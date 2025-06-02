#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<iostream>
#include<initializer_list>
#include<string>
using namespace std;

void test01()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);

	vector<int> v2(10, 1);
	vector<int> v3(v1.begin(), v1.end());

	for (size_t i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " ";
	}
	cout << endl;

	for (auto e : v2)
	{
		cout << e << " ";
	}
	cout << endl;

	vector<int>::iterator it = v3.begin();
	while (it != v3.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

void test02()
{
	vector<int> v1;
	v1.reserve(10);
	size_t old = v1.capacity();
	cout << "initail capacity:" << old << endl;
	for (size_t i = 0; i < 100; i++)
	{
		v1.push_back(i);
		if (v1.capacity() != old)
		{
			cout << v1.capacity() << endl;
			old = v1.capacity();
		}
	}
	v1.insert(v1.begin(), 1000);
	v1.insert(v1.begin() + 3, 9999);
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;

	auto it = find(v1.begin(), v1.end(), 5);
	if (it != v1.end())
	{
		v1.insert(it, 50);
	}
	v1.erase(v1.begin());
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test03()
{
	vector<string> v;
	string s1("yan");
	v.push_back(s1);
	v.push_back("hang");
	for (const auto& e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	auto i1 = { 10, 20 ,30 };
	cout << typeid(i1).name() << endl;
	for (auto e : i1)
	{
		cout << e << " ";
	}
	cout << endl;
	vector<int> v1({ 10, 20, 30 });
	vector<int> v2 = { 10, 20, 30 };//more common
	//vector<int> v2{ 10, 20, 30 };//c++ 11
}
void test04()
{
	struct A
	{
		A(int a1, int a2)
			:_a1(a1)
			,_a2(a2)
		{}
		int _a1;
		int _a2;
	};

	vector<A> v3;
	A aa1(1, 1);
	v3.push_back(aa1);//有名对象
	v3.push_back(A(2, 2));//匿名对象
	v3.push_back({ 3, 3 });//多参数构造隐式类型转换

	v3.emplace_back(aa1);//
	v3.emplace_back(A(2, 2));//
	//v3.emplace_back({ 3, 3 });不适用于emplace_back

	//传构造A的参数,高效率,少一次copy construction
	v3.emplace_back(3, 3);//这是正确用法
	vector<A>::iterator it2 = v3.begin();
	while (it2 != v3.end())
	{
		cout << it2->_a1 << ":" << it2->_a2 << endl;
		++it2;
	}
	cout << endl;
	//C++ 11
	for (auto& e : v3)
	{
		cout << e._a1 << ":" << e._a2 << endl;
	}
	cout << endl;
	//C++ 17 结构化绑定
	for (auto& [x, y] : v3)
	{
		cout << x << ":" << y << endl;
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