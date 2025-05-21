#pragma once
#include<iostream>
#include<string.h>
#include<assert.h>
using namespace std;
namespace suhangx
{
	class string
	{
	public:
		typedef char* iterator;
		typedef const char* const_iterator;
		iterator begin();
		iterator end();
		const_iterator begin() const;
		const_iterator end() const;
		//string();
		string(const char* str = "");
		string(const string& s);
		const char* c_str() const;
		~string();
		size_t size() const;
		const char& operator[](size_t i) const;
		char& operator[](size_t i);

		void reserve(size_t n);
		void push_back(char ch);
		void append(const char* str);
		void pop_back();

		string& operator+=(char ch);
		string& operator+=(const char* str);
		string& operator=(string s);
		void swap(string& s);

		string& insert(size_t pos, char ch);
		string& insert(size_t pos, const char* str);
		string& erase(size_t pos, size_t len = npos);

		size_t find(char ch, size_t pos = 0) const;
		size_t find(const char* str , size_t pos = 0) const;

		string substr(size_t pos, size_t len = npos) const;

		void clear();

		bool operator<(const string& s) const;
		bool operator<=(const string& s) const;
		bool operator>(const string& s) const;
		bool operator>=(const string& s) const;
		bool operator==(const string& s) const;
		bool operator!=(const string& s) const;

	private:
		char* _str;
		size_t _size = 0;
		size_t _capacity = 0;
	public:
		static const size_t npos;
	};

	ostream& operator<<(ostream& out, const string& s);
	istream& operator>>(istream& in, string& s);

	istream& getline(istream& in, string& str, char delim = '\n');
}
