#include <iostream>
#include <string>
using namespace std;

class Flight
{
protected:
    string flightNumber;
    string source;
    string destination;

public:
    Flight(const string &flightNumber, const string &source, const string &destination)
        : flightNumber(flightNumber), source(source), destination(destination) {}

    virtual void display() = 0;
    virtual void bookTicket() = 0;
};

class EconomyFlight : public Flight
{
public:
    EconomyFlight(const string &flightNumber, const string &source, const string &destination)
        : Flight(flightNumber, source, destination) {}

    void display() override
    {
        cout << "Economy Flight " << flightNumber << " from " << source << " to " << destination << endl;
    }

    void bookTicket() override
    {
        cout << "Booking economy class ticket for flight " << flightNumber << endl;
        // Additional booking logic for economy class
    }
};

class BusinessFlight : public Flight
{
public:
    BusinessFlight(const string &flightNumber, const string &source, const string &destination)
        : Flight(flightNumber, source, destination) {}

    void display() override
    {
        cout << "Business Flight " << flightNumber << " from " << source << " to " << destination << endl;
    }

    void bookTicket() override
    {
        cout << "Booking business class ticket for flight " << flightNumber << endl;
        // Additional booking logic for business class
    }
};

class Passenger
{
private:
    string name;

public:
    Passenger(const string &name) : name(name) {}

    void bookFlight(Flight *flight)
    {
        cout << "Passenger " << name << " is booking a flight." << endl;
        flight->display();
        flight->bookTicket();
        cout << "Flight booked successfully!" << endl;
    }
};

int main()
{
    // Create flight objects
    Flight *economyFlight = new EconomyFlight("E123", "City A", "City B");
    Flight *businessFlight = new BusinessFlight("B456", "City B", "City C");

    // Create passenger objects
    Passenger passenger1("John");
    Passenger passenger2("Alice");

    // Book flights
    passenger1.bookFlight(economyFlight);
    passenger2.bookFlight(businessFlight);

    // Clean up memory
    delete economyFlight;
    delete businessFlight;

    return 0;
}
