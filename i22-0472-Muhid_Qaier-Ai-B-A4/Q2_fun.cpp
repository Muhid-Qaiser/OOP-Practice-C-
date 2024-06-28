#include <iostream>
#include "Q2.h"
using namespace std;

// * Constructor
String::String()
{
    this->str1 = NULL;
    len = 0;
}
String::String(char *str)
{
    int size = 0;
    for (; str[size] != '\0'; size++)
    {
    }

    len = size;

    str1 = new char[size + 1];

    for (int i = 0; i < size; i++)
        this->str1[i] = str[i];
    this->str1[size] = '\0';
}
String::String(const String &other)
{
    len = other.len;
    str1 = new char[len + 1];

    for (int i = 0; i < len; i++)
        this->str1[i] = other.str1[i];
    this->str1[len] = '\0';
}
String::String(int x)
{
    len = x;

    // ? Method 1
    str1 = new char[len + 1]; // +1 is for terminating null character

    // ? Method 2
    // str1 = new char[len];
}

// * Destructor
String::~String()
{
    len = 0;
    delete[] str1;
    str1 = NULL;
}

// * [] operator
char &String::operator[](int i)
{
    return str1[i];
}
char &String::operator[](int i) const
{
    return str1[i];
}

// * Arithmetic operator
String &String::operator+(const String &str)
{
    String *result = new String;
    result->len = str.len + len;
    result->str1 = new char[len + str.len + 2];

    for (int i = 0; i < len; i++)
        result->str1[i] = str1[i];

    for (int i = len; i < str.len + len; i++)
        result->str1[i] = str.str1[i - len];

    result->str1[str.len + len + 1] = '\0';

    return *result;
}
String &String::operator+(const char &str)
{
    String *result = new String;
    result->len = len + 1;
    result->str1 = new char[result->len + 1];

    for (int i = 0; i < result->len - 1; i++)
        result->str1[i] = str1[i];

    result->str1[result->len - 1] = str;

    result->str1[result->len] = '\0';

    return *result;
}
String &String::operator+(char *&str)
{
    int size = 0;
    for (; str[size] != '\0'; size++)
    {
    }

    String *result = new String;
    result->len = size + len;
    result->str1 = new char[size + len + 1]; // +1 is for terminating null character

    for (int i = 0; i < len; i++)
        result->str1[i] = str1[i];

    for (int i = len; i < size + len; i++)
        result->str1[i] = str[i - len];

    result->str1[size + len] = '\0';

    return *result;
}

// non member function to check is substr is a substring of str and Removing the substring
int findstring(String &str, const string &substr)
{
    bool found = false;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == substr[0])
        {
            found = true;
            for (int j = 0; j < substr.length() && i + j < str.length(); j++)
                if (str[i + j] != substr[j])
                {
                    found = false;
                    break;
                }
        }
        if (found)
            return i;
    }
    return -1;
}
String &String::operator-(const string &substr)
{

    int size = 0;

    while (substr[size] != '\0')
        size++;

    int idx = findstring(*this, substr);
    if (idx == -1)
        return *this;

    String *result = new String;
    result->len = len;
    result->str1 = new char[result->len + 1];

    int index = 0;
    for (int i = 0; i < len; i++)
    {
        if (i == idx)
            i += size - 1;
        else
            result->str1[index++] = str1[i];
    }
    result->str1[index] = '\0';
    return *result;
}

int findstring(String &str, String substr)
{
    bool found = false;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == substr[0])
        {
            found = true;
            for (int j = 0; j < substr.length() && i + j < str.length(); j++)
                if (str[i + j] != substr[j])
                {
                    found = false;
                    break;
                }
        }
        if (found)
            return i;
    }
    return -1;
}
String &String::operator-(const String &substr)
{
    int idx = findstring(*this, substr);
    if (idx == -1)
        return *this;

    String *result = new String;
    result->len = len;
    result->str1 = new char[result->len + 1];

    int index = 0;
    for (int i = 0; i < len; i++)
    {
        if (i == idx)
            i += substr.len - 1;
        else
            result->str1[index++] = str1[i];
    }
    result->str1[index] = '\0';
    return *result;
}

/*
String &String::operator-(const String &substr)
{
    bool check = false;

    int count = 0, index = 0;

    String *result = new String;
    result->len = len;
    result->str1 = new char[result->len + 1];

    for (int i = 0; i < len; i++)
    {
        if (str1[i] == substr.str1[0])
        {
            for (int j = 0; j < substr.len; j++)
            {
                if (str1[i + j] == substr.str1[j])
                    count++;
            }
        }

        if (count == substr.len)
        {
            index = i;
            break;
        }
        else
            count = 0;
    }

    count = 0;

    for (int i = 0; i < len; i++)
    {
        if (i != index)
        {
            result->str1[count++] = str1[i];
        }
        else
            i += substr.len - 1;
    }

    result->str1[count] = '\0';
    return *result;
}
String &String::operator-(const string &substr)
{
    int size = 0, count = 0, index = 0;

    while (substr[size] != '\0')
    {
        size++;
    }

    String *result = new String;
    result->len = len;
    result->str1 = new char[result->len + 1];

    for (int i = 0; i < len; i++)
    {
        if (str1[i] == substr[0])
        {
            for (int j = 0; j < size; j++)
            {
                if (str1[i + j] == substr[j])
                    count++;
            }
        }

        if (count == size)
        {
            index = i;
            break;
        }
        else
            count = 0;
    }

    count = 0;

    for (int i = 0; i < len; i++)
    {
        if (i != index)
        {
            result->str1[count++] = str1[i];
        }
        else
            i += size - 1;
    }

    result->str1[count] = '\0';
    return *result;
}
*/

// * Checking to see if the String is empty
bool String::operator!()
{
    return (str1 == "" || str1[0] == '\0' || str1 == NULL || str1 == "\0");
}

// * Assigning String str to *this
String &String::operator=(const String &str)
{
    this->len = str.len;
    this->str1 = new char[this->len + 1];

    for (int i = 0; i <= this->len; i++)
        this->str1[i] = str.str1[i];

    this->str1[this->len] = '\0';
    return *this;
}

// * Assigning char* str to *this
String &String::operator=(char *str)
{
    int size = 0;
    while (str[size] != '\0')
    {
        size++;
    }

    this->len = size;
    this->str1 = new char[this->len + 1];

    for (int i = 0; i < this->len; i++)
        this->str1[i] = str[i];

    this->str1[this->len] = '\0';
    return *this;
}

// * Assigning string str to *this
String &String::operator=(const string &str)
{
    int size = 0;
    while (str[size] != '\0')
    {
        size++;
    }

    this->len = size;
    this->str1 = new char[this->len + 1];

    for (int i = 0; i <= this->len; i++)
        this->str1[i] = str[i];

    this->str1[this->len + 1] = '\0';
    return *this;
}

// * Checking to see if the Strings are equal
bool String::operator==(const String &str) const
{
    if (len != str.len)
        return false;

    for (int i = 0; i < this->len; i++)
        if (this->str1[i] == str.str1[i])
            return false;
    return true;
}

// * Checking to see if the String and string are equal
bool String::operator==(const string &str) const
{
    int size = 0;

    while (str[size] != '\0')
    {
        size++;
    }

    if (len != size)
        return false;

    for (int i = 0; i < this->len; i++)
        if (this->str1[i] == str[i])
            return false;
    return true;
}

// * Checking to see if the String and char* are equal
bool String::operator==(char *str) const
{
    int size = 0;

    while (str[size] != '\0')
    {
        size++;
    }

    if (len != size)
        return false;

    for (int i = 0; i < this->len; i++)
        if (this->str1[i] == str[i])
            return false;
    return true;
}

// * Finding index of ch in *this
int &String::operator()(char ch)
{
    int *result = new int;

    for (int i = 0; i < len; i++)
        if (str1[i] == ch)
        {
            *result = i;
            return *result;
        }
    *result = -1;
    return *result;
}
int &String::operator()(const String &ch)
{
    int *result = new int;

    for (int i = 0; i < len; i++)
        if (str1[i] == ch.str1[0])
        {
            *result = i;
            return *result;
        }
    *result = -1;
    return *result;
}
int &String::operator()(const string &ch)
{
    int *result = new int;

    for (int i = 0; i < len; i++)
        if (str1[i] == ch[0])
        {
            *result = i;
            return *result;
        }
    *result = -1;
    return *result;
}
int &String::operator()(char *ch)
{
    int *result = new int;

    for (int i = 0; i < len; i++)
        if (str1[i] == ch[0])
        {
            *result = i;
            return *result;
        }

    *result = -1;
    return *result;
}

// * Multiplying String with a
String String::operator*(int a)
{
    int count = 0;

    String result;
    result.len = a * len;
    result.str1 = new char[result.len + 2];

    for (int i = 0; i < a; i++)
        for (int j = 0; j < len; j++)
            result.str1[count++] = str1[j];

    result.str1[count] = '\0';

    return result;
}

// * getter
int String::length()
{
    return len;
}

// * >> and << operator
ostream &operator<<(ostream &display, const String &other)
{
    display << other.str1 << endl;
    return display;
}
istream &operator>>(istream &input, const String &other)
{
    input >> other.str1;
    return input;
}