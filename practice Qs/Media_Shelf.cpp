#include <iostream>
#include <cstring>
#include <string>
#include <string.h>
using namespace std;

class Media
{
protected:
    char *title;

public:
    Media(){};
    Media(char *title) : title(title) {}

    virtual void display() = 0;
};

class Book : public Media
{
    char *author;
    char *isbn;

public:
    Book() {}
    Book(char *book, char *a, char *i) : author(a), isbn(i), Media(book) {}
    void display()
    {
        cout << "Book : " << title << endl;
        cout << "Author : " << author << endl;
        cout << "ISBN : " << isbn << endl;
    }
};

class Mag : public Media
{
    char *month;
    int year;

public:
    Mag() {}
    Mag(char *book, char *a, int i) : month(a), year(i), Media(book) {}
    void display()
    {
        cout << "Magazine : " << title << endl;
        cout << "Month : " << month << endl;
        cout << "Year : " << year << endl;
    }
};

class CD : public Media
{
    int capacity;

public:
    CD() {}
    CD(char *book, int c) : capacity(c), Media(book) {}
    void display()
    {
        cout << "CD : " << title << endl;
        cout << "Capacity : " << capacity << endl;
    }
};

class Shelf
{
    Media **m;
    int curr;
    int max;

public:
    Shelf() {}
    Shelf(int c, int max) : curr(c), max(max)
    {
        m = new Media *[max];
    }

    void insert(Media *p)
    {
        if (curr < max)
        {
            m[curr++] = p;
        }
        else
        {
            cout << "\n!MAX Limit reached!" << endl;
        }
    }

    void display()
    {
        for (int i = 0; i < curr; i++)
        {
            m[i]->display();
        }
    }
};

int main()
{

    Shelf s(0, 100);
    char *title = new char[100];
    char choice = '\0';

    do
    {

        cout << "1.Book \n2.Magazine \n3.CD\n4.Display \n5.Exit\n";
        cout << "Enter Choice : ";
        cin >> choice;

        switch (choice)
        {
        case '1':
        {

            char *author = new char[100], *isbn = new char[100];

            cout << "Enter Title : ";
            cin.ignore();
            cin.get(title, 30);
            cout << "Enter Author : ";
            cin.ignore();
            cin.get(author, 30);
            cout << "Enter Isbn : ";
            cin.ignore();
            cin.get(isbn, 30);
            Book *b = new Book(title, author, isbn);
            s.insert(b);
            break;
        }

        case '2':
        {

            char *month = new char[100];
            int year;
            cout << "Enter Title : ";
            cin.ignore();
            cin.get(title, 30);
            cout << "Enter Month : ";
            cin.ignore();
            cin.get(month, 30);
            cout << "Enter year : ";
            cin.ignore(); // ! ---------
            cin >> year;
            Mag *b = new Mag(title, month, year);
            s.insert(b);
            break;
        }

        case '3':
        {

            int cap;
            cout << "Enter Title : ";
            cin.ignore();
            cin.get(title, 30);
            cout << "Enter capacity : ";
            cin.ignore();
            cin >> cap; // ! ---------
            CD *b = new CD(title, cap);
            s.insert(b);
            break;
        }

        case '4':
            s.display();
            break;

        case '5':
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "ERROR: Unknown\n";
            break;
        }
    } while (choice != '5');

    return 0;
}