#include <iostream>

// Base class
class Base
{
public:
    Base()
    {
        std::cout << "Base constructor" << std::endl;
    }

    virtual ~Base()
    {
        std::cout << "Base destructor" << std::endl;
    }

    void display()
    {
        std::cout << "Base class" << std::endl;
    }
};

// Intermediate class A, virtual inheritance from Base
class A : virtual public Base
{
public:
    A()
    {
        std::cout << "Derived class A constructor" << std::endl;
    }

    ~A()
    {
        std::cout << "Derived class A destructor" << std::endl;
    }

    void displayA()
    {
        std::cout << "Derived class A" << std::endl;
    }
};

// Intermediate class B, virtual inheritance from Base
class B : virtual public Base
{
public:
    B()
    {
        std::cout << "Derived class B constructor" << std::endl;
    }

    ~B()
    {
        std::cout << "Derived class B destructor" << std::endl;
    }

    void displayB()
    {
        std::cout << "Derived class B" << std::endl;
    }
};

// Derived class, inherits from A and B
class Derived : public A, public B
{
public:
    Derived()
    {
        std::cout << "Derived class constructor" << std::endl;
    }

    ~Derived()
    {
        std::cout << "Derived class destructor" << std::endl;
    }

    void displayDerived()
    {
        std::cout << "Derived class" << std::endl;
    }
};

int main()
{
    // Derived d;
    Base *a = new B;
    delete a;

    // Ambiguity resolved, calling the member functions
    // d.display();        // Accessing display from Base class
    // d.displayA();       // Accessing displayA from class A
    // d.displayB();       // Accessing displayB from class B
    // d.displayDerived(); // Accessing displayDerived from Derived class

    return 0;
}
