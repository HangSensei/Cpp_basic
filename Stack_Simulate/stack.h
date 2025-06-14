#pragma once
#include<iostream>
#include<vector>
#include<list>

//ÊÊÅäÆ÷, Åä½ÓÆ÷
//ÈİÆ÷ÊÊÅäÆ÷
namespace mystack
{
	template<class T, class Container = vector<T>>
	class stack
	{
	public:
		void push(const T& x)
		{
			_con.push_back(x);
		}

		void pop()
		{
			_con.pop_back();
		}

		size_t size() const
		{
			return _con.size();
		}

		bool empty() const
		{
			return _con.empty();
		}

		const T& top() const
		{
			return _con.back();
		}

		T& top()
		{
			return _con.back();
		}

	private:
		Container _con;
	};

}

