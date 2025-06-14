#include "stack.h"
#include "queue.h"
using namespace std;

void test01()
{
	//mystack::stack<int, vector<int>> st;
	mystack::stack<int, list<int>> st;
	st.push(1);
	st.push(2);
	cout << st.top() << " ";
	st.pop();

	st.push(3);
	st.push(4);
	while (!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl;
}

void test02()
{
	myqueue::queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);

	while (!q.empty())
	{
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
}

int main()
{
	test02();
	return 0;
}