#include <iostream>
using namespace std;

const int Namelen = 10;
const int Numberlen = 8;
const int Addresslen = 30;

class MyDirectory
{
protected:
    int id;
    // char name[Namelen + 1];
    char *name;
    char *address;
    char *number;

public:
    MyDirectory()
    {
        name = new char[Namelen + 1];
        address = new char[Addresslen + 1];
        number = new char[Numberlen + 1];
    }
    MyDirectory(int id, char *name, char *num, char *add) : id(id)
    {
        this->name = new char[Namelen];
        this->address = new char[Addresslen];
        this->number = new char[Numberlen];

        for (int i = 0; i < Namelen; i++)
        {
            this->name[i] = name[i];
        }
        this->name[Namelen] = '\0';
        for (int i = 0; i < Numberlen; i++)
        {
            this->number[i] = num[i];
        }
        this->number[Numberlen] = '\0';

        for (int i = 0; i < Addresslen; i++)
        {
            this->address[i] = add[i];
        }
        this->address[Addresslen] = '\0';
    }

    void operator=(MyDirectory &obj)
    {
        this->id = obj.id;

        // delete[] name;
        // delete[] number;
        // delete[] address;
        // this->name = new char[Namelen];
        // this->address = new char[Addresslen];
        // this->number = new char[Numberlen];

        for (int i = 0; i < Namelen; i++)
        {
            this->name[i] = obj.name[i];
        }
        this->name[Namelen] = '\0';
        for (int i = 0; i < Numberlen; i++)
        {
            this->number[i] = obj.number[i];
        }
        this->number[Numberlen] = '\0';

        for (int i = 0; i < Addresslen; i++)
        {
            this->address[i] = obj.address[i];
        }
        this->address[Addresslen] = '\0';
    }

    char &operator[](int x)
    {
        return number[x];
    }

    friend ostream &operator<<(ostream &out, MyDirectory &directory);
};
ostream &operator<<(ostream &out, MyDirectory &directory)
{
    out << directory.id << endl
        << directory.name << endl
        << directory.number << endl
        << directory.address << endl;

    return out;
}

int main()
{
    MyDirectory d(20, "Fast Nu", "11112812", "Block B, Faisal Town"), d2;
    cout << d << endl;

    d[3] = '9';
    cout << d << endl;

    char x = d[5];
    cout << "x : " << x << endl;

    d2 = d;
    cout << "d2 : " << d2 << endl;
    d2[3] = '0';

    cout << "d2 : " << d2 << endl
         << "d : " << d << endl;

    return 0;
}