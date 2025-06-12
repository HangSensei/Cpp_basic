#pragma once
#include<iostream>
using namespace std;
namespace mylist
{
	template<class T>
	struct list_node
	{
		T _data;
		list_node<T>* _next;
		list_node<T>* _prev;

		list_node(const T& x = T())
			:_data(x)
			,_next(nullptr)
			,_prev(nullptr)
		{}
	};
	
	template<class T, class Ref, class Ptr>
	struct __list_iterator
	{
		typedef list_node<T> Node;
		typedef __list_iterator<T, Ref, Ptr> Self;
		Node* _node;

		__list_iterator(Node* node)
			:_node(node)
		{}

		Ref operator*()
		{
			return _node->_data;
		}

		Ptr operator->()
		{
			return &_node->_data;
		}

		Self& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		Self& operator++(int)
		{
			Self tmp = (*this);
			_node = _node->_next;
			return tmp;
		}

		Self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		Self& operator--(int)
		{
			__list_iterator<T> tmp(*this);
			_node = _node->_prev;
			return tmp;
		}

		bool operator!=(const Self& it) const
		{
			return _node != it._node;
		}

		bool operator==(const Self& it) const
		{
			return _node == it._node;
		}
	};
	// const_iterator只能去重新生成一个类, const_iterator自身可以修改,指向的内容不行(*it),例如print等场景需要用到
	/*template<class T>
	struct __list_const_iterator
	{
		typedef list_node<T> Node;
		Node* _node;

		__list_const_iterator(Node* node)
			:_node(node)
		{
		}

		const T& operator*()
		{
			return _node->_data;
		}

		__list_const_iterator<T>& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		__list_const_iterator<T>& operator++(int)
		{
			__list_const_iterator<T> tmp = (*this);
			_node = _node->_next;
			return tmp;
		}

		__list_const_iterator<T>& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		__list_const_iterator<T>& operator--(int)
		{
			__list_const_iterator<T> tmp(*this);
			_node = _node->_prev;
			return tmp;
		}

		bool operator!=(const __list_const_iterator<T>& it) const
		{
			return _node != it._node;
		}

		bool operator==(const __list_const_iterator<T>& it) const
		{
			return _node == it._node;
		}
	};*/

	template<class T>
	class list
	{
		typedef list_node<T> Node;
	public:
		typedef __list_iterator<T, T&, T*> iterator;
		//typedef __list_const_iterator<T> const_iterator;
		typedef __list_iterator<T, const T&, const T*> const_iterator;

		iterator begin()
		{
			return iterator(_head->_next);
		}

		iterator end()
		{
			return iterator(_head);
		}

		const_iterator begin() const
		{
			return const_iterator(_head->_next);
		}

		const_iterator end() const
		{
			return const_iterator(_head);
		}

		void empty_init()
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
		}

		list()
		{
			empty_init();
		}
		// lt2(lt1)
		list(const list<T>& lt)
		{
			empty_init();
			for (const auto& e : lt)
			{
				push_back(e);
			}
		}
		list(initializer_list<T> il)
		{
			empty_init();
			for (const auto& e : il)
			{
				push_back(e);
			}
		}

		/*list<T>& operator=(const list<T>& lt)
		{
			if (this != &lt)
			{
				clear();
				for (const auto& e : lt)
				{
					push_back(e);
				}
			}
			return *this;
		}*/

		void swap(list<T>& lt)
		{
			std::swap(_head, lt._head);
			std::swap(_size, lt._size);
		}

		list<T>& operator=(list<T> lt)
		{
			swap(lt);
			return *this;
		}

		//~list()
		//{
		//	/*iterator it = begin();
		//	while (it != end())
		//	{
		//		it = erase(it);
		//	}
		//	delete _head;
		//	_head = nullptr;*/
		//}

		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}

		void push_back(const T& x)
		{
			/*Node* newnode = new Node(x);
			Node* tail = _head->_prev;

			tail->_next = newnode;
			newnode->_prev = tail;
			newnode->_next = _head;
			_head->_prev = newnode;*/
			insert(end() ,x);
		}

		void push_front(const T& x)
		{
			insert(begin(), x);
		}

		void pop_back()
		{
			erase(--end());
		}

		void pop_front()
		{
			erase(begin());
		}

		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				it = erase(it);
			}
		}

		iterator insert(iterator pos, const T& val)
		{
			Node* cur = pos._node;
			Node* newnode = new Node(val);
			Node* prev = cur->_prev;
			//prev newnode cur
			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;

			++_size;

			return iterator(newnode);
		}

		iterator erase(iterator pos)
		{
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* next = cur->_next;

			prev->_next = next;
			next->_prev = prev;
			delete cur;

			return iterator(next);
		}
		
		size_t size() const
		{
			return _size;
		}

	private:
		Node* _head;
		size_t _size = 0;
	};
}
