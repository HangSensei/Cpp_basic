#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    size_t pos = s.rfind(' ');
    if (pos != string::npos)
    {
        cout << s.size() - pos - 1 << endl;
    }
    else
    {
        cout << s.size() << endl;
    }

}
