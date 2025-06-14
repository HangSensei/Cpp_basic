#pragma once

#pragma once
#include<iostream>
#include<vector>
#include<list>

//ÊÊÅäÆ÷, Åä½ÓÆ÷
//ÈİÆ÷ÊÊÅäÆ÷
namespace myqueue
{
	template<class T, class Container = list<T>>
	class queue
	{
	public:
		void push(const T& x)
		{
			_con.push_back(x);
		}

		void pop()
		{
			_con.pop_front();
		}

		size_t size() const
		{
			return _con.size();
		}

		bool empty() const
		{
			return _con.empty();
		}

		const T& front() const
		{
			return _con.front();
		}

		T& front()
		{
			return _con.front();
		}

		const T& back() const
		{
			return _con.back();
		}

		T& back()
		{
			return _con.back();
		}

	private:
		Container _con;
	};

}


