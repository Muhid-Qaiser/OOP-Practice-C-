#include <iostream>
#include "Q4.h"
using namespace std;

ostream &operator<<(ostream &output, Polynomial &n)
{
    for (int i = 0; i <= n.degree; i++)
    {
        output << "(" << n.polynomial[i] << "x^" << n.degree - i << ")";
        if (i != n.degree)
            cout << " + ";
    }

    return output;
}
istream &operator>>(istream &input, const Polynomial &n)
{
    for (int i = 0; i <= n.degree; i++)
    {
        cout << "[?].x^" << n.degree - i << " : ";
        input >> n.polynomial[i];
    }

    return input;
}

Polynomial::Polynomial()
{
    degree = 0;
    polynomial = NULL;
}
Polynomial::Polynomial(int x)
{
    degree = x;
    polynomial = new int[x];

    for (int i = 0; i <= x; i++)
        polynomial[i] = 0;
}
Polynomial::Polynomial(const Polynomial &p)
{
    degree = p.degree;
    polynomial = new int[degree];

    for (int i = 0; i <= degree; i++)
        polynomial[i] = p.polynomial[i];
}

Polynomial::~Polynomial()
{
    degree = 0;
    delete[] polynomial;
    polynomial = NULL;
}

Polynomial &Polynomial::operator=(const Polynomial &p)
{
    degree = p.degree;
    polynomial = new int[degree];

    for (int i = 0; i <= degree; i++)
        polynomial[i] = p.polynomial[i];
    return *this;
}
bool Polynomial::operator==(const Polynomial &p)
{
    if (degree != p.degree)
        return false;

    for (int i = 0; i <= degree; i++)
        if (polynomial[i] != p.polynomial[i])
            return false;
    return true;
}

Polynomial Polynomial::operator+(const Polynomial &p)
{
    int count = 0;

    Polynomial result;
    result.degree = (degree > p.degree) ? degree : p.degree;
    result.polynomial = new int[result.degree];

    if (degree < p.degree)
    {
        for (int i = p.degree; i >= 0; i--)
        {
            if (i <= degree)
                result.polynomial[p.degree - i] = this->polynomial[count++] + p.polynomial[p.degree - i];
            else
                result.polynomial[p.degree - i] = p.polynomial[p.degree - i];
        }
    }
    else
    {
        for (int i = degree; i >= 0; i--)
        {
            if (i <= p.degree)
                result.polynomial[degree - i] = this->polynomial[degree - i] + p.polynomial[count++];
            else
                result.polynomial[degree - i] = this->polynomial[degree - i];
        }
    }
    return result;
}
Polynomial Polynomial::operator-(const Polynomial &p)
{
    int count = 0;

    Polynomial result;
    result.degree = (degree > p.degree) ? degree : p.degree;
    result.polynomial = new int[result.degree];

    if (degree < p.degree)
    {
        for (int i = p.degree; i >= 0; i--)
        {
            if (i <= degree)
                result.polynomial[p.degree - i] = this->polynomial[count++] - p.polynomial[p.degree - i];
            else
                result.polynomial[p.degree - i] = p.polynomial[p.degree - i];
        }
    }
    else
    {
        for (int i = degree; i >= 0; i--)
        {
            if (i <= p.degree)
                result.polynomial[degree - i] = this->polynomial[degree - i] - p.polynomial[count++];
            else
                result.polynomial[degree - i] = this->polynomial[degree - i];
        }
    }
    return result;
}

void Polynomial::operator+=(const Polynomial &p)
{
    int count = 0;

    Polynomial result;
    result.degree = (degree > p.degree) ? degree : p.degree;
    result.polynomial = new int[result.degree];

    if (degree < p.degree)
    {
        for (int i = p.degree; i >= 0; i--)
        {
            if (i <= degree)
                result.polynomial[p.degree - i] = this->polynomial[count++] + p.polynomial[p.degree - i];
            else
                result.polynomial[p.degree - i] = p.polynomial[p.degree - i];
        }
    }
    else
    {
        for (int i = degree; i >= 0; i--)
        {
            if (i <= p.degree)
                result.polynomial[degree - i] = this->polynomial[degree - i] + p.polynomial[count++];
            else
                result.polynomial[degree - i] = this->polynomial[degree - i];
        }
    }

    this->degree = result.degree;
    this->polynomial = new int[this->degree];

    for (int i = 0; i <= this->degree; i++)
        this->polynomial[i] = result.polynomial[i];
}
void Polynomial::operator-=(const Polynomial &p)
{
    int count = 0;

    Polynomial result;
    result.degree = (degree > p.degree) ? degree : p.degree;
    result.polynomial = new int[result.degree];

    if (degree < p.degree)
    {
        for (int i = p.degree; i >= 0; i--)
        {
            if (i <= degree)
                result.polynomial[p.degree - i] = this->polynomial[count++] - p.polynomial[p.degree - i];
            else
                result.polynomial[p.degree - i] = p.polynomial[p.degree - i];
        }
    }
    else
    {
        for (int i = degree; i >= 0; i--)
        {
            if (i <= p.degree)
                result.polynomial[degree - i] = this->polynomial[degree - i] - p.polynomial[count++];
            else
                result.polynomial[degree - i] = this->polynomial[degree - i];
        }
    }

    this->degree = result.degree;
    delete[] this->polynomial;
    // ? Method : Shallow Copy
    // this->polynomial = result.polynomial;

    // ? Method 2 : Deep Copy
    this->polynomial = new int[this->degree];
    for (int i = 0; i <= this->degree; i++)
        this->polynomial[i] = result.polynomial[i];

    while (true)
    {
        if (this->polynomial[0] == 0)
            leftShift(*this, this->degree);
        else
            break;
    }
}

// * Left shift the polynomial where first degree is a Zero
void leftShift(Polynomial &obj, int &size)
{
    for (int i = 0; i < size; i++)
        obj.polynomial[i] = obj.polynomial[i + 1];
    size--;
}

// ? Method 2
/*
void Polynomial::operator-=(const Polynomial &p)
{
    int size = 0;
    (degree < p.degree) ? size = degree : size = p.degree;

    for (int i = 0; i <= size; i++)
        this->polynomial[i] -= p.polynomial[i];
}

void Polynomial::operator+=(const Polynomial &p)
{
    int size = 0;
    (degree < p.degree) ? size = degree : size = p.degree;

    for (int i = 0; i <= size; i++)
        this->polynomial[i] += p.polynomial[i];
}
*/
