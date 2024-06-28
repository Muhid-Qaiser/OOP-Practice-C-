#include <iostream>
using namespace std;

int getDays(int day, int month, int year)
{
    int pday = 1, pmonth = 1, pyear = 2023, res = 0;

    int daysinMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    while (day != pday || month != pmonth || year != pyear)
    {
        res++;
        day++;

        if (day > daysinMonth[month - 1])
        {
            day = 1;
            month++;
        }
        if (month > 12)
        {
            month = 1;

            if ((year % 4 == 0 && year % 100 == 0) || (year % 400 == 0))
            {
                res++;
            }

            year++;
        }
    }

    return res;
}

class Item
{
protected:
    char *name;
    float price;

public:
    Item() {}
    Item(char *name, float price) : name(name), price(price) {}

    virtual void print() = 0;
};

class Perishable : public Item
{
    int day;
    int month;
    int year;
    int quantity;
    int nprice;

public:
    Perishable(char *name, float p, int d, int m, int y, int q) : Item(name, p), day(d), month(m), year(y), quantity(q), nprice(p)
    {
        int age = getDays(d, m, y);
        if (age > 0)
            nprice = 0;
    }

    void print()
    {
        cout << "Item : " << name << endl
             << "Price : " << nprice << endl
             << "Quantity : " << quantity << endl
             << "Date : " << day << "/" << month << "/" << year << "\n";
    }
};

class Permanent : public Item
{
protected:
    int age;
    float nprice;
    int d, m, y;

public:
    Permanent(char *name, float p, int d, int m, int y) : Item(name, p), d(d), m(m), y(y)
    {
        age = getDays(d, m, y);
        nprice = price;
        nprice -= (0.2 * age);
    }

    void print()
    {
        cout << "Item " << name << endl
             << "Price : " << nprice << endl
             << "Date : " << d << "/" << m << "/" << y << endl;
    }
};

class Bulk_Item : public Permanent
{
    char *description;
    bool partofSet;

public:
    Bulk_Item(char *name, float p, int d, int m, int y, char *des, bool set) : description(des), partofSet(set), Permanent(name, p, d, m, y)
    {
    }

    void print()
    {
        Permanent::print();
        cout << "Description : " << description << endl
             << "Part of set : " << partofSet << endl;
    }
};

class Pharmacy
{
    Item **items;
    int count;

public:
    Pharmacy(int n) : count(n)
    {
        items = new Item *[n];
        count = 0;
    }

    void AddItem(Item *item)
    {
        this->items[count++] = item;
    }
    void DisplayItems()
    {
        for (int i = 0; i < count; i++)
        {
            items[i]->print();
            cout << endl;
        }
    }
};

int main()
{
    int itemCount = 4;
    Pharmacy ph(itemCount); // ph has a list of 4 items here
    Item *iptr = new Permanent("glucometer", 5000, 15, 11, 2020);
    // a glucometer of price 5000 and entry date 15 Nov 2020
    iptr->print(); // Print all information i.e. name, actual price, entry date, Passed days, current price.

    cout << endl;
    cout << endl;

    ph.AddItem(iptr);
    iptr = new Perishable("Panadol", 20, 16, 01, 2021, 500);
    // 500mg Panadol tablet of price 20, expiry date 16 Jan 2021
    iptr->print(); // Prints name, current price(depends on expiry

    cout << endl;
    cout << endl;

    // date), quantity and expiry date.

    ph.AddItem(iptr);
    iptr = new Bulk_Item("Gloves", 500, 12, 10, 2020, "Glove box for doctors", true); // glovesbox of cost 500 Rs. With entry date 12

    // Oct 2020

    iptr->print(); // prints name, actual price, entry date, Passeddays,current price, description and if it is part of set or not .

    cout << endl;
    cout << endl;

    ph.AddItem(iptr);
    iptr = new Bulk_Item("5CC Syringe", 90, 15, 5, 2020, "For Injections only", false);
    // Syring of cost 90 Rs. each with entry date 15 May 2020
    ph.AddItem(iptr);
    ph.DisplayItems();
    // this function should print complete information of items in list
    cout << endl;
    cout << endl;

    return 0;
}