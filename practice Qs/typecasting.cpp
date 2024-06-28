#include <iostream>
using namespace std;

class A
{
    int a;
    int b;

public:
    A(int a, int b) : a(a), b(b) {}
    void p()
    {
        cout << a << " " << b << endl;
    }
    void operator=(int a)
    {
        this->a = a;
        b = 0;
    }
    operator int()
    {
        return this->a;
    }
    void operator=(A &obj)
    {
        a = obj.a;
        b = obj.b;
    }
};

int main()
{
    A a(1, 3);
    a.p();
    a = 5;
    a.p();
    int s = a;
    cout << s << endl;
    A b(0, 0);
    b = a;
    b.p();
    return 0;
}