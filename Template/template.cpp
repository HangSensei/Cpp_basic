#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

//template<typename T1, typename T2>
//
//T2 Add(T1 left, T2 right)
//{
//	return left + right;
//}
//
//int main()
//{
//	int a1 = 10;
//	double a2 = 11.11;
//	std::cout << Add(a1, a2) << std::endl;
//	return 0;
//}
using namespace std;
namespace bit
{
	template<class T>
	class Stack
	{
	public:
		Stack(int n = 4)
			:_a(new T[n])
			, _top(0)
			, _capacity(n)
		{
			cout << "Stack(int n = 4)" << endl;
		}

		~Stack()
		{
			delete[] _a;
			_a = nullptr;
			_top = 0;
			_capacity = 0;
			cout << "~Stack" << endl;
		}

		void Push(const T& x)
		{
			_a[_top] = x;
			++_top;
		}


	private:
		T* _a;
		int _top;
		int _capacity;
	};
}

int main()
{
	try
	{
		bit::Stack<int> st1;
		bit::Stack<double> st2;

		st1.Push(1);
		st1.Push(2);

		st2.Push(1.1);
		st2.Push(1.2);
	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
	}
	return 0;
}