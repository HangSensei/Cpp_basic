#include<iostream>
#include<vector>
#include<list>
#include<algorithm>

using namespace std;

void test_list1()
{
	list<int> lt1;
	list <int> lt2(10, 1);
	vector<int> v1 = { 1, 2, 3, 4, 5, 6 };
	list<int> lt3(v1.begin(), v1.end());
	list<int> lt4 = { 1, 2, 3, 4, 5, 6, 1, 1, 1, 1 };
	//迭代器的本质模拟的就是指向数组的指针
	int a[] = {100, 10,  1, 2, 3, 4 };
	list<int> lt5(a, a + 4);
	sort(a, a + 4);
	//封装,通用的相似的遍历容器的方式,并且封装了容器底层,屏蔽了容器结构的差异,和底层的实现细节
	//通用/复用,实现算法时用迭代器函数模板方式实现,跟底层容器结构解耦
	list<int>::iterator it4 = lt4.begin();
	while (it4 != lt4.end())
	{
		cout << *it4 << " ";
		++it4;
	}
	cout << endl;

	for (auto e : lt4)
	{
		cout << e << " ";
	}
	cout << endl;

	sort(a, a + 4);
	sort(v1.begin(), v1.end());
	//list仅支持双向迭代器,不支持随机迭代器
	//sort(lt3.begin(), lt3.end());

}

void test_list2()
{
	list<int> lt2(10, 1);
	lt2.push_back(10);
	lt2.push_front(10);
	for (auto e : lt2)
	{
		cout << e << " ";
	}
	cout << endl;
	lt2.resize(20, 2);
	for (auto e : lt2)
	{
		cout << e << " ";
	}
	cout << endl;
	lt2.resize(5);
	for (auto e : lt2)
	{
		cout << e << " ";
	}
	cout << endl;
}

int main()
{
	//test_list1();
	test_list2();
	return 0;
}