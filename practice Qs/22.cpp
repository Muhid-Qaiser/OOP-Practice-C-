#include <iostream>
using namespace std;

class A
{
public:
    A() {}
    A(A &a)
    {
        cout << "copy\n";
    }
    A operator+(A a)
    {
        cout << "+\n";
        return a;
    }
};

int main()
{
    A a, b, c;
    c = a + b;

    return 0;
}