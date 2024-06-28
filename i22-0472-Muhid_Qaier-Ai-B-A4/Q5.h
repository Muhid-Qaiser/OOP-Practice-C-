// #include "Q5_fun.cpp"
#ifndef Q5
#define Q5
#include <iostream>
using namespace std;

class Array
{
    int *array;
    int size;

public:
    // * Constructors
    Array();
    Array(int size);
    Array(int *arr, int size);
    Array(const Array &);

    // * [] operator
    int &operator[](int i);
    int &operator[](int i) const;

    // * = operator
    const Array &operator=(const Array &);

    // * arithmetic operator
    Array operator+(const Array &);
    Array operator-(const Array &);
    Array operator++();
    Array operator++(int);
    Array &operator--(int);

    // * == operator
    bool operator==(const Array &) const;

    // * ! operator
    bool operator!();

    // * +=/-= operator
    void operator+=(const Array &);
    void operator-=(const Array &);

    // * () operator
    int operator()(int idx, int val);

    // * Destructor
    ~Array();

    friend ostream &operator<<(ostream &output, const Array &);
    friend istream &operator>>(istream &input, const Array &);
};

#endif
