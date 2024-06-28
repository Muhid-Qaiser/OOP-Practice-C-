// #include "Q1_fun.cpp"
#ifndef Q1
#define Q1
#include <iostream>
using namespace std;

int getNum(int a, int b);

class Fraction
{
    int numerator;
    int denominator;

public:
    // * constructors
    Fraction();
    Fraction(int numerator);
    Fraction(int numerator, int denominator);

    // * copy constructor
    Fraction(Fraction &f);

    // * destructor
    ~Fraction();

    // * Getters
    int getNumerator() const;
    int getDenominator() const;

    // * Display
    void display();

    // * Operator Overloading Functions

    // * Arithmetic Operators
    Fraction &operator+(Fraction &other);
    Fraction &operator-(Fraction &other);
    Fraction &operator*(Fraction &other);
    Fraction &operator/(Fraction &other);

    // * Arithmetic Operators with =
    void operator+=(Fraction &other);
    void operator-=(Fraction &other);
    void operator*=(Fraction &other);
    void operator/=(Fraction &other);

    // * << and >> operator
    friend ostream &operator<<(ostream &display, const Fraction &other);
    friend istream &operator>>(istream &input, Fraction &other);

    // * Conditional operator
    bool operator==(const Fraction &other);
    bool operator!=(const Fraction &other);
    bool operator<(const Fraction &other);
    bool operator>(const Fraction &other);
    bool operator>=(const Fraction &other);
    bool operator<=(const Fraction &other);

    // * index operator
    int &operator[](int x);

    // * Uniary operator
    void operator++();
    void operator++(int);
    void operator--();
    void operator--(int);

    // * () operator
    double operator()();
    void operator()(int num, int den);

    // * AND OR operator
    bool operator&&(const Fraction &other) const;
    bool operator||(const Fraction &other) const;
    Fraction operator&(const Fraction &other);

    // * -> operator
    Fraction operator->();
    Fraction &operator->*(int a);
    // Fraction operator->*(Fraction *member);
};

#endif
