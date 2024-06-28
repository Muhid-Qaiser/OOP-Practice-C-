class DateTime
{
    // Suppose this class provides full date and time functionality and does not require destructor
};
class Location
{
    // Suppose this class provides full functionality of
    // location coordinates and does not require destructor
};
class Vehicle
{
private:
    int category;         // 1= Bike, 2= Rikshaw, 3=Car
    char *color;          // “Black”, “White” etc.
    char *registrationNo; // e.g. ”LEC-1234”
};
class Ride
{
private:
    DateTime startTime;
    DateTime endTime;
    Location stratLocation;
    Location endLocation;
    Driver *driver;     // reference of driver of ride
    Customer *customer; // reference of customer of

    // ride

    float rideDuration; //(endTime - startTime)
    float rideDistance; // Total distance covered
    float cost;         // Cost of the ride
public:
    static int totalRides;
};

class Person
{
private:
    char *phoneNo; // required for Registration
    char *name;
    Ride **ridesHistory; // Containing references of all
    // the rides of a person
};
class Customer : public Person
{
private:
    int accountBalance;
    // For Example, accountBalance = -50 means
    // customer needs to pay Rs. 50 to PnD and vice versa
    // for accountBalance = 50
public:
    static int totalCustomers;
};
class Driver : public Person
{
private:
    Vehicle vehicle; // Information about Driver’s

    // vehicle

public:
    static int totalDrivers;
};
class PnD
{
private:
    Customer **allCustomers; // list of all Customers
    Driver **allDrivers;     // list of all Drivers
    Ride **allRides;         // list of all Rides
};