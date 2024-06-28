#include <iostream>
#include <cstring>
using namespace std;

class flights
{
protected:
    char *start;
    char *destination;
    float price;
    int *seats;
    int count;

public:
    flights() {}
    flights(char *s, char *d, float p, int c) : count(c), price(p)
    {
        // cout << "this->Price : " << this->price << endl;

        int size = strlen(s);
        start = new char[size + 1];
        for (int i = 0; i < size; i++)
        {
            start[i] = s[i];
        }
        start[size + 1] = '\0';

        size = strlen(d);

        destination = new char[size + 1];
        for (int i = 0; i < size; i++)
        {
            destination[i] = d[i];
        }
        destination[size + 1] = '\0';

        // size = sizeof(seats) / sizeof(seats[0]);
        // this->seats = new int[size + 1];
        // for (int i = 0; i < size; i++)
        // {
        //     this->seats[i] = seats[i];
        // }

        seats = new int[count + 1];
        for (int i = 0; i < count; i++)
        {
            this->seats[i] = i + 1;
        }
    }
    void operator=(flights &obj)
    {
        price = obj.price;
        int size = strlen(obj.start);
        start = new char[size + 1];
        for (int i = 0; i < size; i++)
        {
            start[i] = obj.start[i];
        }
        start[size + 1] = '\0';

        size = strlen(obj.destination);

        destination = new char[size + 1];
        for (int i = 0; i < size; i++)
        {
            destination[i] = obj.destination[i];
        }
        destination[size + 1] = '\0';

        // size = sizeof(seats) / sizeof(seats[0]);
        // this->seats = new int[size + 1];
        // for (int i = 0; i < size; i++)
        // {
        //     this->seats[i] = seats[i];
        // }
        count = obj.count;
        seats = new int[obj.count];
        for (int i = 0; i < obj.count; i++)
        {
            this->seats[i] = obj.seats[i];
        }
    }
    void choose_Seats()
    {
        int choice = 0;
        cout << "\nSeats Available : ";
        for (int i = 0; i < count; i++)
        {
            cout << this->seats[i] << " ";
        }

        do
        {
            cout << "\nChoose Seat : ";
            cin >> choice;
            cout << "Seat[" << choice << "] : " << this->seats[choice - 1] << endl;
        } while (!(choice > 0 && choice <= count && seats[choice - 1] != -1));

        for (int i = 0; i < count; i++)
        {
            if (choice == seats[i])
                seats[i] = -1;
        }
    }
    void display_Seats()
    {
        cout << endl;
        for (int i = 0; i < count; i++)
        {
            cout << seats[i] << " ";
        }
    }
    bool availableSeats()
    {
        for (int i = 0; i < count; i++)
        {
            if (seats[i] != -1)
                return true;
        }
        return false;
    }
    virtual void display() = 0;
    virtual float getPrice() = 0;
    virtual ~flights(){};
};

class passenger
{
    char *name;
    char *country;
    bool passport;
    float balance;
    flights *flight;

public:
    passenger() {}
    passenger(char *name, char *country, bool pass, float bal) : passport(pass), balance(bal)
    {
        this->name = new char[strlen(name) + 1];
        this->country = new char[strlen(country) + 1];

        for (int i = 0; i < strlen(name); i++)
        {
            this->name[i] = name[i];
        }
        this->name[strlen(name)] = '\0';

        for (int i = 0; i < strlen(country); i++)
        {
            this->country[i] = country[i];
        }
        this->country[strlen(country)] = '\0';
    }
    void operator=(passenger &obj)
    {
        this->name = new char[strlen(obj.name) + 1];
        this->country = new char[strlen(obj.country) + 1];

        for (int i = 0; i < strlen(obj.name); i++)
        {
            this->name[i] = obj.name[i];
        }
        this->name[strlen(obj.name)] = '\0';

        for (int i = 0; i < strlen(obj.country); i++)
        {
            this->country[i] = obj.country[i];
        }
        this->country[strlen(obj.country)] = '\0';

        passport = obj.passport;
        balance = obj.balance;
    }
    void operator=(flights *f)
    {
        if (balance > f->getPrice())
        {
            flight = f;
            cout << "Flight Booked!\n";
        }
        else
            cout << "Insufficient Balance!\n";
    }
    void bookFlight(flights *f)
    {
        if (balance > f->getPrice())
        {
            flight = f;
            cout << "Flight Booked!\n";
        }
        else
            cout << "Insufficient Balance!\n";
    }
    void display()
    {
        cout << "Name : " << this->name << endl
             << "Country : " << this->country << endl
             << "PassPort : " << this->passport << endl
             << "Balance : " << this->balance << endl;
        flight->display();
    }
};

class business : public flights
{
    char *type;
    bool bed;

public:
    business() {}
    business(char *s, char *d, float p, int c, char *type, bool bed) : bed(bed), flights(s, d, p, c)
    {
        int size = strlen(type);

        this->type = new char[size];
        for (int i = 0; i < size; i++)
        {
            this->type[i] = type[i];
        }
        this->type[size] = '\0';
    }
    void display()
    {
        cout << "Start : " << start << endl
             << "Destination : " << destination << endl
             << "Price : " << price << endl
             << "Type : " << type << endl
             << "Bed : " << bed << endl;
    }
    float getPrice()
    {
        return price;
    }
    ~business() {}
};

class economy : public flights
{
    char *type;
    char *food;

public:
    economy() {}
    economy(char *s, char *d, float p, int c, char *type, char *food) : flights(s, d, p, c)
    {
        int size = strlen(type);
        type = new char[size];
        for (int i = 0; i < size; i++)
        {
            this->type[i] = type[i];
        }
        this->type[size] = '\0';

        size = strlen(food);
        food = new char[size];
        for (int i = 0; i < size; i++)
        {
            this->food[i] = food[i];
        }
        this->food[size] = '\0';
    }
    void display()
    {
        cout << "Start : " << start << endl
             << "Destination : " << destination << endl
             << "Price : " << price << endl
             << "Type : " << type << endl
             << "Food : " << food << endl;
    }
    float getPrice()
    {
        return price;
    }
    ~economy() {}
};

class airlines
{
    string name;
    flights **flight;
    int count;

public:
    airlines() {}
    airlines(flights **arr, int c, string name) : count(c), name(name)
    {
        flight = new flights *[count];
        for (int i = 0; i < count; i++)
        {
            flight[i] = arr[i];
        }
    }
    flights *choose_flight()
    {
        int choice = 0;

        for (int i = 0; i < count; i++)
        {
            cout << "\tFlight " << i + 1 << "\n";
            if (flight[i]->availableSeats())
            {
                flight[i]->display();
            }
        }

        cout << "Choose Flight Number : ";
        cin >> choice;
        choice--;

        flight[choice]->choose_Seats();

        cout << "Ticket Booked!\n";

        return flight[choice];
    }
    void operator=(airlines &obj)
    {
        count = obj.count;
        flight = new flights *[count];
        for (int i = 0; i < count; i++)
        {
            flight[i] = obj.flight[i];
        }
    }
    ~airlines() {}
    void display_Name()
    {
        cout << name << endl;
    }
};

class System
{
    passenger *person;
    airlines **air;
    int count;

public:
    System(passenger *person, airlines **air, int count) : count(count)
    {
        this->person = person;
        this->air = air;
    }
    ~System() {}
    void BookFlight()
    {
        int choice = 0;

        for (int i = 0; i < count; i++)
        {
            cout << "Airline " << i + 1 << "\n";
            air[i]->display_Name();
        }
        cout << "Choose Airline Number : ";
        cin >> choice;
        choice--;

        flights *f = air[choice]->choose_flight();
        this->person->bookFlight(f);
    }
    void display()
    {
        person->display();
    }
};

int main()
{
    flights **f;
    f = new flights *[2];
    f[0] = new business("Jubail", "Makkah", 500, 20, "Business", true);
    f[1] = new business("Riyadh", "Jeddah", 200, 10, "economy", false);

    airlines pia(f, 2, "PIA");
    airlines *airs[2];

    airs[0] = new airlines(f, 2, "PIA");
    airs[1] = new airlines(f, 2, "Qatar");

    passenger *joe = new passenger("jOE", "Jubail", true, 600);

    System s(joe, airs, 2);
    s.BookFlight();
    s.display();

    delete f[0];
    delete f[1];
    delete[] f;

    return 0;
}