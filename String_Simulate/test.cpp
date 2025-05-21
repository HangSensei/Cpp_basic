#define _CRT_SECURE_NO_WARNINGS
#include"string.h"

namespace suhangx
{
	void test_string1()
	{
		string s1;
		cout << s1.c_str() << endl;

		string s2("hello world");
		cout << s2.c_str() << endl;

		for (size_t i = 0; i < s2.size(); ++i)
		{
			s2[i]++;
		}
		cout << s2.c_str() << endl;

		for (auto e : s2)
		{
			cout << e << " ";
		}
		cout << endl;

		string::iterator it1 = s1.begin();
		while (it1 != s1.end())
		{
			cout << *it1 << " ";
			++it1;
		}

		const string s3("hello world");
		string::const_iterator it3 = s3.begin();
		while (it3 != s3.end())
		{
			//*it1 = 'x'; const, could not modify
			cout << *it3 << " ";
			++it3;
		}
		cout << endl;

	}

	void test_string2()
	{
		string s1("hello world");
		s1.push_back('x');
		cout << s1.c_str() << endl;
		s1.append("???");
		cout << s1.c_str() << endl;
		s1 += '>';
		cout << s1.c_str() << endl;
		s1 += "ohhhhh";
		cout << s1.c_str() << endl;
		string s2("hello world");
		s2 += '\0';
		s2 += '\0';
		s2 += '!';
		cout << s2 << endl;
		cout << s2.c_str() << endl;
		s2 += "yyyyyyyyyyyyyyyyyyyyyyyy";
		cout << s2 << endl;
		cout << s2.c_str() << endl;

	}

	void test_string3()
	{
		string s1("hello world");
		s1.insert(6, 'x');
		cout << s1 << endl;

		s1.insert(0, 'x');
		cout << s1 << endl;

		string s2("hello world");
		s2.insert(6, "????????");
		cout << s2 << endl;
		s2.insert(0, "<<<<");
		cout << s2 << endl;

		string s3("hello world");
		s3.erase(7);
		cout << s3 << endl;

		string s4("hello world");
		s4.erase(7, 100);
		cout << s4 << endl;

		string s5("hello world");
		s5.erase(7, 3);
		cout << s5 << endl;

		s5.pop_back();
		s5.pop_back();
		cout << s5 << endl;
	}

	void split_url(const string& url)
	{
		size_t i1 = url.find(':');
		if (i1 != string::npos)
		{
			cout << url.substr(0, i1) << endl;
		}
		size_t i2 = i1 + 3;
		size_t i3 = url.find('/', i2);
		if (i3 != string::npos)
		{
			cout << url.substr(i2, i3 - i2) << endl;
			cout << url.substr(i3 + 1) << endl;
		}
		cout << endl;
	}

	void test_string4()
	{
		string url1 = "https://legacy.cplusplus.com/reference/string/string/?kw=string";
		split_url(url1);
	}

	void test_string5()
	{
		string s1("hello"), s2("hello");

		string s3("hellox"), s4("hello");

		string s5("hello"), s6("hellox");

		cout << (s1 < s2) << endl;
		cout << (s3 < s4) << endl;
		cout << (s5 < s6) << endl;
	}

	void test_string6()
	{
		/*string s1("hello"), s2("hello");
		cout << s1 << " " << s2 << endl;
		cin >> s1 >> s2;
		cout << s1 << " " << s2 << endl;*/
		string line;
		//getline(cin, line);
		getline(cin, line);
		cout << line << endl;
	}

	void test_string7()
	{
		string s1("hello"), s2("worldxxxxx");
		string s3(s1);
		cout << s1 << endl;
		cout << s3 << endl;
		s1[0] = 'x';
		cout << s1 << endl;
		cout << s3 << endl;

		s1 = s2;
		cout << s1 << endl;
		cout << s2 << endl;
	}
	void test_string8()
	{

	}
}
int main()
{
	//suhangx::test_string1();
	//suhangx::test_string2();
	//suhangx::test_string3();
	//suhangx::test_string4();
	//suhangx::test_string5();
	//suhangx::test_string6();
	//suhangx::test_string7();
	suhangx::test_string8();

	return 0;
}