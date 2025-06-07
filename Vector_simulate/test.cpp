#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include"vector.h"
using namespace std;
//泛型 函数模板
template<class Container>
void Print(const Container& con)
{
	for (auto e : con)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_vector1()
{
	myvector::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
	Print(v);
}

void test_vector2()
{
	myvector::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	Print(v);
	v.pop_back();
	v.pop_back();
	v.pop_back();
	v.pop_back();
	
	Print(v);
}

void test_vector3()
{
	myvector::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	Print(v);
	v.insert(v.begin(), 0);
	Print(v);
	v.insert(v.begin() + 2, 8);
	Print(v);

	int x;
	cin >> x;
	auto it = find(v.begin(), v.end(), x);
	if (it != v.end())
	{
		//更新迭代器
		it = v.insert(it, x * 10);
		*it = 10;
	}
	Print(v);
}

void test_vector4()
{
	myvector::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	Print(v);
	v.insert(v.begin(), 0);
	Print(v);
	v.erase(v.begin());
	Print(v);

	int x;
	cin >> x;
	auto it = find(v.begin(), v.end(), x);
	if (it != v.end())
	{
		v.erase(it);
	}
	Print(v);
}

void test_vector5()
{
	myvector::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(4);
	v.push_back(4);
	Print(v);
	//删除所有的偶数
	auto it = v.begin();
	while (it != v.end())
	{
		if (*it % 2 == 0)
		{
			//重新赋值更新迭代器
			it = v.erase(it);
		}
		else
		{
			++it;
		}
	}
	Print(v);
}

void test_vector6()
{
	myvector::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	Print(v);
	v.resize(7);
	Print(v);
	v.resize(20, 1);
	Print(v);
	v.resize(2);
	Print(v);
}

void test_vector7()
{
	myvector::vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	Print(v1);
	myvector::vector<int> v2(v1);
	Print(v1);

	myvector::vector<int> v3 = {1, 2, 3, 4, 5};
	Print(v3);

	myvector::vector<int> v5(v3.begin() + 1, v3.end() - 1);
	Print(v5);

	myvector::vector<int> v7(10, 1);
	Print(v7);

	/*myvector::vector<size_t> v8(10, 1);
	Print(v8);*/
	
	v1 = v7;
	Print(v1);
}

void test_vector8()
{
	myvector::vector<string> v1;
	v1.push_back("11111111111111111111111");
	v1.push_back("11111111111111111111111");
	v1.push_back("11111111111111111111111");
	v1.push_back("11111111111111111111111");
	v1.push_back("11111111111111111111111");
	Print(v1);

}


int main()
{
	//test_vector1();
	/*cout << typeid(std::vector<int>::iterator).name() << endl;
	cout << typeid(myvector::vector<int>::iterator).name() << endl;*/
	//test_vector2();
	//test_vector3();
	//test_vector4();
	//test_vector5();
	//test_vector6();
	//test_vector7();
	test_vector8();



	return 0;
}