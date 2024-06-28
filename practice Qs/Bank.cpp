#include <iostream>
#include <cstring>
using namespace std;

class Bank
{
    char *name;
    int accNo;
    char *type;
    float bal;

public:
    Bank() : accNo(0), bal(0.0) {}
    Bank(char *n, int acc, char *t, float b) : accNo(acc), bal(b)
    {
        int size;
        for (size = 0; n[size] != '\0'; size++)
        {
        }
        name = new char[size];

        for (int i = 0; i < size; i++)
        {
            name[i] = n[i];
        }

        name[size] = '\0';

        for (size = 0; t[size] != '\0'; size++)
        {
        }
        type = new char[size];

        for (int i = 0; i < size; i++)
        {
            type[i] = t[i];
        }

        type[size] = '\0';
    }
    Bank(Bank &obj)
    {
        accNo = obj.accNo;
        bal = obj.bal;

        int size;
        for (size = 0; obj.name[size] != '\0'; size++)
        {
        }
        name = new char[size];

        for (int i = 0; i < size; i++)
        {
            name[i] = obj.name[i];
        }
        name[size] = '\0';

        for (size = 0; obj.type[size] != '\0'; size++)
        {
        }
        type = new char[size];

        for (int i = 0; i < size; i++)
        {
            type[i] = obj.type[i];
        }
        type[size] = '\0';
    }
    void setBal(int x)
    {
        bal += x;
    }
    void withdrawBal(int x)
    {
        if (bal > x && bal > 0)
        {
            bal -= x;
            cout << "\nAmount : " << x << " has been Withdrawn.\nRemaining Balance : " << bal << endl;
        }
        else
            cout << "\nInSufficient Balance!!" << endl;
    }
    void display()
    {
        cout << "\nName : " << name << endl
             << "Account Number : " << accNo << endl
             << "Type : " << type << endl
             << "Balance : " << bal << endl;
    }
};

int main()
{
    Bank b1("joe", 101, "saving", 5000), b2;
    b1.display();

    b2 = b1;
    b2.display();

    b2.setBal(10);
    b2.display();
    b2.withdrawBal(1000);
    b2.display();
    b1.display();

    return 0;
}