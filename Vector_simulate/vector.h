#pragma once
#include<assert.h>
#include<initializer_list>
using namespace std;

namespace myvector
{
	template<class T>
	struct VectorIterator
	{
		using Self = VectorIterator<T>;

		T* _ptr;

		VectorIterator(T* ptr = nullptr)
			: _ptr(ptr)
		{}

		T& operator*() 
		{ 
			return *_ptr; 
		}
		T* operator->() 
		{ 
			return _ptr; 
		}

		Self& operator++() 
		{ 
			++_ptr; return *this; 
		}
		Self operator++(int) 
		{ 
			Self tmp(*this); 
			++_ptr; 
			return tmp; 
		}

		Self& operator--() 
		{ 
			--_ptr; 
			return *this; 
		}
		Self operator--(int) 
		{ 
			Self tmp(*this); 
			--_ptr; 
			return tmp; 
		}

		bool operator!=(const Self& rhs) const { return _ptr != rhs._ptr; }
		bool operator==(const Self& rhs) const { return _ptr == rhs._ptr; }

		Self operator+(int n) const { return Self(_ptr + n); }
		Self operator-(int n) const { return Self(_ptr - n); }
		ptrdiff_t operator-(const Self& rhs) const { return _ptr - rhs._ptr; }

		T& operator[](int n) { return *(_ptr + n); }
		bool operator<(const Self& rhs) const { return _ptr < rhs._ptr; }
	};



	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		const_iterator begin() const
		{
			return _start;
		}

		const_iterator end() const
		{
			return _finish;
		}

		vector()
		{}
		//强制编译器生成默认构造
		//vector() = default;
		vector(initializer_list<T> il)
		{
			reserve(il.size());
			for (auto& e : il)
			{
				push_back(e);
			}
		}
		//v2(v1)
		vector(const vector<T>& v)
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			reserve(v.capacity());
			for (auto& e : v)
			{
				push_back(e);
			}
		}

		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_endofstorage, v._endofstorage);

		}

		vector<T>& operator=(vector<T> v)
		{
			swap(v);
			return *this;
		}
		//函数模板
		//任意类型容器迭代器初始化
		template<class InputIterator>
		vector(InputIterator start, InputIterator end)
		{
			while (start != end)
			{
				push_back(*start);
				++start;
			}
		}

		vector(int n, T val = T())
		{
			resize(n, val);
		}

		/*vector(size_t n, T val = T())
		{
			resize(n, val);
		}*/

		~vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = nullptr;
				_finish = nullptr;
				_endofstorage = nullptr;
			}
		}
	
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t old_size = size();
				T* tmp = new T[n];
				//拷贝旧空间数据到新空间
				if (_start)
				{
					//memcpy导致了深层次的浅拷贝
					//int之类的类型(POD),赋值可以完成浅拷贝, string这样的类型,赋值调用operator=完成深拷贝
					//memcpy(tmp, _start, size() * sizeof(T));
					for (size_t i = 0; i < old_size; i++)
					{
						tmp[i] = _start[i];
					}
					delete[] _start;
				}
				_start = tmp;
				_finish = _start + old_size;
				_endofstorage = _start + n;
				
			}
		}

		void resize(size_t n, T val = T())
		{
			if (n > size())
			{
				reserve(n);
				while (_finish != _start + n)
				{
					*_finish = val;
					++_finish;
				}
			}
			else
			{
				_finish = _start + n;
			}
		}

		T& operator[](size_t i)
		{
			assert(i < size());
			return _start[i];
		}

		const T& operator[](size_t i) const
		{
			assert(i < size());
			return _start[i];
		}

		void clear()
		{
			_finish = _start;
		}

		size_t size() const
		{
			return _finish - _start;
		}

		size_t capacity() const
		{
			return _endofstorage - _start;
		}

		void push_back(const T& x)
		{
			if (_finish == _endofstorage)
			{
				reserve(capacity() == 0 ? 4 : 2 * capacity());
			}

			*_finish = x;
			++_finish;
		}

		void pop_back()
		{
			assert(!empty());
			--_finish;
		}

		iterator insert(iterator pos, const T& x)
		{
			assert(pos >= _start && pos <= _finish);
			if (_finish == _endofstorage)
			{
				size_t len = pos - _start;
				reserve(capacity() == 0 ? 4 : capacity() * 2);
				//update iterator pos
				//// pos 是按值传递，修改它只影响函数内部 —— 重新计算插入位置
				pos = _start + len;
			}

			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}
			*pos = x;
			++_finish;
			return pos;
		}

		iterator erase(iterator pos)
		{
			assert(pos >= _start && pos < _finish);
			iterator it = pos + 1;
			while (it != _finish)
			{
				*(it - 1) = *it;
				++it;
			}
			--_finish;
			return pos;

		}

		bool empty() const
		{
			return _start == _finish;
		}

	private:
		iterator _start = nullptr;
		iterator _finish = nullptr;
		iterator _endofstorage = nullptr;
	};
	 
}
