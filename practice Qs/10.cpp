#include <iostream>
using namespace std;
bool compareChars(const char *str1, const char *str2)
{
    // Compare the characters of the two strings
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0')
    {
        if (str1[i] < str2[i])
        {
            return true; // str1 should appear before str2
        }
        else if (str1[i] > str2[i])
        {
            return false; // str1 should appear after str2
        }
        i++;
    }

    // Handle the case when one string is a prefix of the other
    if (str1[i] == '\0' && str2[i] != '\0')
    {
        return true; // str1 should appear before str2
    }
    else if (str1[i] != '\0' && str2[i] == '\0')
    {
        return false; // str1 should appear after str2
    }

    // The strings are equal
    return false;
}

class MyClass
{
private:
    const int x;

public:
    MyClass(int a = 0) : x(a)
    {
        // Constructor body
    }

    void someFunction()
    {
        cout << x << endl;
    }
};

int main()
{
    MyClass f;
    f.someFunction();

    return 0;
}