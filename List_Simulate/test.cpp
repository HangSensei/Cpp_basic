#include "list.h"

namespace mylist
{
	template<class T>
	void print(const list<T>& lt)
	{
		//类模板未实例化,不能去类模板找后面的东西
		//编译器就分不清const_iterator是嵌套内类,还是静态成员变量
		//typename告诉编译器,我确认过了, 这里是类型
		//或者可以直接用auto类型自动推导
		auto it = lt.begin();
		//typename list<T>::const_iterator it = lt.begin();
		while (it!= lt.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}

	void test_list1()
	{
		mylist::list<int> lt1;
		lt1.push_back(1);
		lt1.push_back(2);
		lt1.push_back(3);
		lt1.push_back(4);
		print(lt1);

		list<int>::iterator it = lt1.begin();
		while (it != lt1.end())
		{
			*it += 1;
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}

	struct Pos
	{
		int _row;
		int _col;
		Pos(int row = 0, int col = 0)
			:_row(row)
			,_col(col)
		{}
		
	};

	void test_list3()
	{
		mylist::list<Pos> lt1;
		lt1.push_back({1, 1});
		lt1.push_back({2, 2});
		lt1.push_back({3, 3});
		lt1.push_back({4, 4});
		//list<Pos>::iterator it = lt1.begin();
		auto it = lt1.begin();
		while (it != lt1.end())
		{
			//cout << (*it)._row << "," << (*it)._col << " ";
			//为了可读性,这里省略了一个->
			cout << it->_row << "," << it->_col << endl;
			//cout << it.operator->()->_row << "," << it.operator->()->_col << endl;
			++it;
		}
		cout << endl;
	}

	void test_list4()
	{
		mylist::list<int> lt1;
		lt1.push_back(1);
		lt1.push_back(2);
		lt1.push_back(3);
		lt1.push_back(4);
		print(lt1);

		lt1.push_front(10);
		lt1.push_front(20);
		print(lt1);

		lt1.pop_back();
		lt1.pop_back();
		print(lt1);

		lt1.pop_front();
		lt1.pop_front();
		print(lt1);
	}

	void test_list5()
	{
		mylist::list<double> lt1;
		lt1.push_back(1.1);
		lt1.push_back(2.1);
		lt1.push_back(3.1);
		lt1.push_back(4.1);
		print(lt1);

		mylist::list<double> lt2 = lt1;
		print(lt1);

		mylist::list<double> lt3 = { 10, 20, 30 ,40};
		lt1 = lt3;
		print(lt1);
	}
}


int main()
{
	//mylist::test_list1();
	//mylist::test_list3();
	//mylist::test_list4();
	mylist::test_list5();

	return 0;
}