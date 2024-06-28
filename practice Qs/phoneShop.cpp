#include <iostream>
using namespace std;

class mobile
{
protected:
    int battery;
    bool cam;
    char *os;

public:
    mobile() {}
    mobile(int battey, bool cam, char *os) : battery(battey), cam(cam), os(os)
    {
    }

    virtual void print() = 0;
    virtual ~mobile() {}
};

class Andriod : public mobile
{
    int ram;

public:
    Andriod(int b, bool c, char *os, int ram) : ram(ram), mobile(b, c, os) {}
    void print()
    {
        cout << "Type : Andriod" << endl
             << "Battery : " << battery << endl
             << "Camera : " << cam << endl
             << "Os : " << os << endl
             << "RAM : " << ram << endl;
    }
    ~Andriod() {}
};

class iPhone : public mobile
{
    bool jack;

public:
    iPhone(int b, bool c, char *os, bool ram) : jack(ram), mobile(b, c, os) {}
    void print()
    {
        cout << "Type : iPhone" << endl
             << "Battery : " << battery << endl
             << "Camera : " << cam << endl
             << "Os : " << os << endl
             << "Headphone Jack : " << jack << endl;
    }
    ~iPhone() {}
};

class Shop
{
    mobile **m;
    int count;
    int max;

public:
    Shop() {}
    Shop(int count) : max(count)
    {
        this->count = 0;
        m = new mobile *[max];
    }
    Shop(mobile *m, int count) : max(count)
    {
        count = 0;
        this->m = new mobile *[count];
        this->m[this->count] = m;
    }
    void AddPhone(mobile *m)
    {
        if (count < max)
        {
            this->m[this->count++] = m;
        }
        else
            cout << "Limit Reached\n";
    }
    void print()
    {
        for (int i = 0; i < count; i++)
        {
            m[i]->print();
        }
    }
};

int main()
{
    Shop shop(10);

    mobile *p1 = new Andriod(5000, 1, "UI 2.0", 8);
    mobile *p2 = new iPhone(5000, 1, "UI 2.0", 0);

    shop.AddPhone(p1);
    cout << endl
         << endl;
    shop.AddPhone(p2);
    shop.print();

    return 0;
}