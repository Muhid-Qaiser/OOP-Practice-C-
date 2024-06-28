// #include "Q4_fun.cpp"
#ifndef Q4
#define Q4
#include <iostream>
using namespace std;

class Polynomial
{
    int *polynomial;
    int degree;

public:
    Polynomial();
    Polynomial(int);
    Polynomial(const Polynomial &);

    Polynomial &operator=(const Polynomial &);
    bool operator==(const Polynomial &);

    Polynomial operator+(const Polynomial &);
    Polynomial operator-(const Polynomial &);

    void operator+=(const Polynomial &);
    void operator-=(const Polynomial &);

    ~Polynomial();

    friend ostream &operator<<(ostream &output, Polynomial &);
    friend istream &operator>>(istream &input, const Polynomial &);
    friend void leftShift(Polynomial &obj, int &size);
};

#endif