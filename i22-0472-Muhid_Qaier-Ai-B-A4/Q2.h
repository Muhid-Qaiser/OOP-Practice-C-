// #include "Q2_fun.cpp"
#ifndef Q2
#define Q2
#include <iostream>
using namespace std;

class String
{
    char *str1;
    int len;

public:
    String();
    String(char *str);
    String(const String &other);
    String(int x);

    char &operator[](int i);
    char &operator[](int i) const;

    String &operator+(const String &str);
    String &operator+(const char &str);
    String &operator+(char *&str);

    String &operator-(const String &substr);
    String &operator-(const string &substr);

    bool operator!();

    String &operator=(const String &str);
    String &operator=(char *str);
    String &operator=(const string &str);

    bool operator==(const String &str) const;
    bool operator==(const string &str) const;
    bool operator==(char *str) const;

    int &operator()(char ch);
    int &operator()(const String &ch);
    int &operator()(const string &ch);
    int &operator()(char *ch);

    String operator*(int a);

    int length();

    ~String();

    friend ostream &operator<<(ostream &display, const String &other);
    friend istream &operator>>(istream &display, const String &other);
};

// non member function to check is substr is a substring of str
int findstring(String &str, const string &substr);
int findstring(String &str, String substr);

#endif