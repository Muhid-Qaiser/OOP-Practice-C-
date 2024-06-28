#include <iostream>
#include <string>
using namespace std;

class Car
{
    string make;
    string carModel;
    string regNo;
    int year;

public:
    Car() {}

    Car(string m, string c, string r, int y) : make(m), carModel(c), regNo(r), year(y) {}

    string getMake() const
    {
        return make;
    }

    void setMake(string m)
    {
        make = m;
    }

    string getCarModel() const
    {
        return carModel;
    }

    void setCarModel(string c)
    {
        carModel = c;
    }

    string getRegNo() const
    {
        return regNo;
    }

    void setRegNo(string r)
    {
        regNo = r;
    }

    int getYear() const
    {
        return year;
    }

    void setYear(int y)
    {
        year = y;
    }
};

class Garage
{
    string name;
    int index;
    int capacity;
    Car **cars;

public:
    Garage() : name(""), index(0), capacity(10)
    {
        cars = new Car *[capacity];
    }

    Garage(string n, int i, int c) : name(n), index(i), capacity(c)
    {
        cars = new Car *[capacity];
    }

    ~Garage()
    {
        for (int i = 0; i < index; i++)
        {
            delete cars[i];
        }
        delete[] cars;
    }

    bool IsEmpty()
    {
        return index == 0;
    }

    bool IsFull()
    {
        return index == capacity;
    }

    bool Push(Car *c)
    {
        if (!IsFull())
        {
            cars[index] = c;
            index++;
            return true;
        }
        return false;
    }

    bool Find(string reg)
    {
        for (int i = 0; i < index; i++)
        {
            if (cars[i]->getRegNo() == reg)
            {
                return true;
            }
        }
        return false;
    }

    bool Remove(string reg)
    {
        for (int i = 0; i < index; i++)
        {
            if (cars[i]->getRegNo() == reg)
            {
                delete cars[i];
                for (int j = i; j < index - 1; j++)
                {
                    cars[j] = cars[j + 1];
                }
                index--;
                cout << "Car with registration number " << reg << " has been removed from the garage." << endl;
                return true;
            }
        }
        cout << "Car with registration number " << reg << " was not found in the garage." << endl;
        return false;
    }

    void Display()
    {
        if (IsEmpty())
        {
            cout << "The garage is currently empty." << endl;
        }
        else
        {
            cout << "Cars parked in the garage:" << endl;
            for (int i = 0; i < index; i++)
            {
                Car *car = cars[i];
                cout << "Make: " << car->getMake() << ", Model: " << car->getCarModel() << ", Registration: " << car->getRegNo() << ", Year: " << car->getYear() << endl;
            }
        }
    }
};

int main()
{
    Garage garage("My Garage", 0, 10);

    // Create and add cars to the garage
    Car *car1 = new Car("Honda", "Civic", "ABC123", 2018);
    Car *car2 = new Car("Toyota", "Corolla", "XYZ789", 2020);
    Car *car3 = new Car("Ford", "Mustang", "DEF456", 2019);

    garage.Push(car1);
    garage.Push(car2);
    garage.Push(car3);

    // Check if the garage is empty or full
    cout << "Is the garage empty? " << (garage.IsEmpty() ? "Yes" : "No") << endl;
    cout << "Is the garage full? " << (garage.IsFull() ? "Yes" : "No") << endl;

    // Find a car in the garage
    cout << "Car with registration number ABC123 is " << (garage.Find("ABC123") ? "found" : "not found") << " in the garage." << endl;

    // Remove a car from the garage
    garage.Remove("XYZ789");

    // Display the cars in the garage
    garage.Display();

    // Clean up memory
    delete car1;
    delete car2;
    delete car3;

    return 0;
}
