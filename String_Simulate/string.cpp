#define _CRT_SECURE_NO_WARNINGS

#include"string.h"

namespace suhangx
{
	const size_t string::npos = -1;

	/*string::string()
			:_str(new char[1]{'\0'})
			,_size(0)
			,_capacity(0)
	{}*/

	string::string(const char* str)
		:_size(strlen(str))
	{
		_str = new char[_size + 1];
		_capacity = _size;
		memcpy(_str, str, _size + 1);
	}

	/*string::string(const string& s)
	{
		_str = new char[s._capacity + 1];
		memcpy(_str, s._str, s.size() + 1);
		_size = s._size;
		_capacity = s._capacity;

	}*/

	void string::swap(string& s)
	{
		std::swap(_str, s._str);
		std::swap(_size, s._size);
		std::swap(_capacity, s._capacity);
	}

	string::string(const string& s)
	{
		string tmp(s._str);
		swap(tmp);

	}

	/*string& string::operator=(const string& s)
	{
		if (this != &s)
		{
			char* tmp = new char[s._capacity + 1];
			memcpy(tmp, s._str, s._size + 1);
			delete[] _str;
			_str = tmp;
			_size = s._size;
			_capacity = s._capacity;
		}
		return *this;
	}*/

	string& string::operator=(string tmp)//¡°Copy-and-Swap Assignment Idiom¡±
	{
		swap(tmp);
		return *this;
	}

	string::~string()
	{
		delete[] _str;
		_str = nullptr;
		_size = _capacity = 0;
	}

	const char* string::c_str() const
	{
		return _str;
	}

	size_t string::size() const
	{
		return _size;
	}
	const char& string::operator[](size_t i) const
	{
		assert(i < _size);
		return _str[i];
	}
	char& string::operator[](size_t i)
	{
		assert(i < _size);
		return _str[i];
	}

	string::iterator string::begin()
	{
		return _str;
	}

	string::iterator string::end()
	{
		return _str + _size;
	}

	string::const_iterator string::begin() const
	{
		return _str;
	}

	string::const_iterator string::end() const
	{
		return _str + _size;
	}

	void string::reserve(size_t n)
	{
		if (n > _capacity)
		{
			char* str = new char[n + 1];
			memcpy(str, _str, _size + 1);//copy previous space data
			delete[] _str;
			_str = str;
			_capacity = n;
		}
	}


	void string::push_back(char ch)
	{
		if (_size >= _capacity)
		{
			size_t newcapacity = _capacity == 0 ? 4 : 2 * _capacity;
			reserve(newcapacity);
		}
		_str[_size] = ch;
		++_size;
		_str[_size] = '\0';

	}
	void string::append(const char* str)
	{
		size_t len = strlen(str);
		if (_size + len > _capacity)
		{
			size_t newcapacity = 2 * _capacity > _size + len ? 2 * _capacity : _size + len;
			reserve(newcapacity);
		}

		memcpy(_str + _size, str, len + 1);
		_size += len;
	}

	void string::pop_back()
	{
		assert(_size > 0);
		--_size;
		_str[_size] = '\0';
	}

	string& string::operator+=(char ch)
	{
		push_back(ch);
		return *this;
	}
	string& string::operator+=(const char* str)
	{
		append(str);
		return *this;
	}
	string& string::insert(size_t pos, char ch)
	{
		assert(pos <= _size);
		if (_size >= _capacity)
		{
			size_t newcapacity = _capacity == 0 ? 4 : 2 * _capacity;
			reserve(newcapacity);
		}
		int end = _size;
		while (end >= (int)pos)
		{
			_str[end + 1] = _str[end];
			--end;
		}
		_str[pos] = ch;
		++_size;

		/*size_t end = _size + 1;
		while (end > pos)
		{
			_str[end] = _str[end - 1];
			--end;
		}*/
		return *this;
	}
	string& string::insert(size_t pos, const char* str)
	{
		size_t len = strlen(str);
		if (_size + len > _capacity)
		{
			size_t newcapacity = 2 * _capacity > _size + len ? 2 * _capacity : _size + len;
			reserve(newcapacity);
		}
		int end = _size;
		while (end >= (int)pos)
		{
			_str[end + len] = _str[end];
			--end;
		}
		/*size_t end = _size;
		while (end > pos + len - 1)
		{
			_str[end] = _str[end - len];
			--end;
		}*/
		for (size_t i = 0; i < len; i++)
		{
			_str[pos + i] = str[i];
		}

		_size += len;
		return *this;
	}

	string& string::erase(size_t pos, size_t len)
	{
		assert(pos < _size);

		if (len == npos || len >= (_size - pos))
		{
			_size = pos;
			_str[_size] = '\0';
		}
		else
		{
			size_t i = pos + len;
			memmove(_str + pos, _str + i, _size + 1 - i);
			_size -= len;
		}
		return *this;

	}

	size_t string::find(char ch, size_t pos) const
	{
		for (size_t i = pos; i < _size; i++)
		{
			if (_str[i] == ch)
			{
				return i;
			}
		}

		return npos;
	}
	size_t string::find(const char* str, size_t pos) const
	{
		const char* p1 = strstr(_str + pos, str);
	 	if (p1 == nullptr)
		{
			return npos;
		}
		else
		{
			return p1 - _str;
		}
	}

	string string::substr(size_t pos, size_t len) const
	{
		if (len == npos || len >= _size - pos)
		{
			len = _size - pos;
		}

		string ret;
		ret.reserve(len);
		for (size_t i = 0; i < len; i++)
		{
			ret += _str[pos + i];
		}
		return ret;
	}

	bool string::operator<(const string& s) const
	{
		size_t i1 = 0, i2 = 0;
		while (i1 < _size && i2 < s._size)
		{
			if (_str[i1] < s[i2])
			{
				return true;
			}
			else if (_str[i1] > s[i2])
			{
				return false;
			}
			else
			{
				++i1;
				++i2;
			}
		}
		return i2 < s._size;
	}
	bool string::operator<=(const string& s) const
	{
		return *this < s || *this == s;
	}
	bool string::operator>(const string& s) const
	{
		return !(*this <= s);
	}
	bool string::operator>=(const string& s) const
	{
		return !(*this <= s);
	}
	bool string::operator==(const string& s) const
	{
		size_t i1 = 0, i2 = 0;
		while (i1 < _size && i2 < s._size)
		{
			if (_str[i1] != s[i2])
			{
				return false;
			}
			else
			{
				++i1;
				++i2;
			}
		}
		return i1 == _size && i2 == s._size;
	}
	bool string::operator!=(const string& s) const
	{
		return !(*this == s);
	}

	void string::clear()
	{
		_str[0] = '\0';
		_size = 0;
	}

	ostream& operator<<(ostream& out, const string& s)
	{
		//out << s.c_str(); could not handle the condition with '\0' in the middle
		/*for (size_t i = 0; i < s.size(); i++)
		{
			out << s[i];
		}*/

		for (auto e : s)
		{
			out << e;
		}
		return out;
	}
	istream& operator>>(istream& in, string& s)
	{
		s.clear();
		char buffer[128];
		char ch = in.get();
		int i = 0;
		while (ch != ' ' && ch != '\n')
		{
			buffer[i++] = ch;
			if (i == 127)
			{
				buffer[i] = '\0';
				s += buffer;
				i = 0;
			}
			ch = in.get();
		}
		if (i > 0)
		{
			buffer[i] = '\0';
			s += buffer;
			i = 0;
		}
		return in;
	}

	istream& getline(istream& in, string& str, char delim)
	{
		str.clear();
		char buffer[128];
		int i = 0;
		char ch = in.get();
		while (ch != delim)
		{
			buffer[i++] = ch;
			if (i == 127)
			{
				buffer[i] = '\0';
				str += buffer;
				i = 0;
			}
			ch = in.get();
		}
		if (i > 0)
		{
			buffer[i] = '\0';
			str += buffer;
		}
		return in;
	}

}
