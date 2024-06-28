#include <iostream>
#include "Q1.h"
using namespace std;

int getNum(int a, int b)
{

    if (b == 0)
        return a;

    return getNum(b, a % b);
}

// * constructors
Fraction::Fraction()
{
    numerator = 0;
    denominator = 1;
}
Fraction::Fraction(int numerator)
{
    this->numerator = numerator;
    denominator = 1;
}
Fraction::Fraction(int numerator, int denominator)
{
    this->numerator = numerator;
    this->denominator = denominator;

    int temp = getNum(numerator, denominator);

    this->numerator /= temp;
    this->denominator /= temp;
}

// * copy constructor
Fraction::Fraction(Fraction &f)
{
    numerator = f.numerator;
    denominator = f.denominator;
}

// * destructor
Fraction::~Fraction()
{
    numerator = 0;
    denominator = 0;
}

// * Getters
int Fraction::getNumerator() const { return numerator; }
int Fraction::getDenominator() const { return denominator; }

// * Display
void Fraction::display()
{
    cout << "\nFraction : " << numerator << "/" << denominator << endl
         << endl;
}

// * Operator Overloading Functions

// * Arithmetic Operators
Fraction &Fraction::operator+(Fraction &other)
{
    int lcm = 0, temp = 0;
    Fraction *result = new Fraction;

    lcm = (denominator * other.denominator) / getNum(denominator, other.denominator);

    result->numerator = (numerator * lcm / denominator) + (other.numerator * lcm / other.denominator);
    result->denominator = lcm;

    temp = getNum(result->numerator, result->denominator);
    result->numerator /= temp;
    result->denominator /= temp;

    return *result;
}
Fraction &Fraction::operator-(Fraction &other)
{
    int lcm = 0, temp = 0;
    Fraction *result = new Fraction;

    lcm = (denominator * other.denominator) / getNum(denominator, other.denominator);

    result->numerator = (numerator * lcm / denominator) - (other.numerator * lcm / other.denominator);
    result->denominator = lcm;

    temp = getNum(result->numerator, result->denominator);
    result->numerator /= temp;
    result->denominator /= temp;

    return *result;
}
Fraction &Fraction::operator*(Fraction &other)
{
    Fraction *result = new Fraction;

    result->numerator = this->numerator * other.numerator;
    result->denominator = this->denominator * other.denominator;

    int temp = getNum(result->numerator, result->denominator);

    result->numerator /= temp;
    result->denominator /= temp;

    return *result;
}
Fraction &Fraction::operator/(Fraction &other)
{
    Fraction *result = new Fraction;

    result->numerator = this->numerator * other.denominator;
    result->denominator = this->denominator * other.numerator;

    int temp = getNum(result->numerator, result->denominator);

    result->numerator /= temp;
    result->denominator /= temp;

    return *result;
}

// * Arithmetic Operators with =
void Fraction::operator+=(Fraction &other)
{
    int lcm = 0, temp = 0;

    lcm = (denominator * other.denominator) / getNum(denominator, other.denominator);

    numerator = (numerator * lcm / denominator) + (other.numerator * lcm / other.denominator);
    denominator = lcm;

    temp = getNum(numerator, denominator);
    numerator /= temp;
    denominator /= temp;
}
void Fraction::operator*=(Fraction &other)
{
    numerator *= other.numerator;
    denominator *= other.denominator;

    int temp = getNum(numerator, denominator);

    numerator /= temp;
    denominator /= temp;
}
void Fraction::operator-=(Fraction &other)
{
    int lcm = 0, temp = 0;

    lcm = (denominator * other.denominator) / getNum(denominator, other.denominator);

    numerator = (numerator * lcm / denominator) - (other.numerator * lcm / other.denominator);
    denominator = lcm;

    temp = getNum(numerator, denominator);
    numerator /= temp;
    denominator /= temp;
}
void Fraction::operator/=(Fraction &other)
{
    // numerator /= other.numerator;
    // denominator /= other.denominator;

    numerator *= other.denominator;
    denominator *= other.numerator;

    int temp = getNum(numerator, denominator);

    numerator /= temp;
    denominator /= temp;
}

// * << and >> operator
ostream &operator<<(ostream &display, const Fraction &other)
{
    display << other.numerator << "/" << other.denominator << endl;
    return display;
}
istream &operator>>(istream &input, Fraction &other)
{
    cout << "Enter Numerator : ";
    input >> other.numerator;
    cout << "Enter Denominator : ";
    input >> other.denominator;

    while (other.denominator == 0)
    {
        cout << "\nInvalid Denominator!" << endl
             << "Enter non-zero Denominator : ";
        cin >> other.denominator;
    }

    return input;
}

// * Conditional operator
bool Fraction::operator==(const Fraction &other)
{
    if (numerator == other.numerator && denominator == other.denominator)
        return true;
    return false;
}
bool Fraction::operator!=(const Fraction &other)
{
    if (numerator == other.numerator && denominator == other.denominator)
        return false;
    return true;
}
bool Fraction::operator<(const Fraction &other)
{
    if (numerator * other.denominator < denominator * other.numerator)
        return true;
    return false;
}
bool Fraction::operator>(const Fraction &other)
{
    if (numerator * other.denominator > denominator * other.numerator)
        return true;
    return false;
}
bool Fraction::operator>=(const Fraction &other)
{
    if (numerator * other.denominator >= denominator * other.numerator)
        return true;
    return false;
}
bool Fraction::operator<=(const Fraction &other)
{
    if (numerator * other.denominator <= denominator * other.numerator)
        return true;
    return false;
}

// * index operator
int &Fraction::operator[](int index)
{
    // ? Method 1
    return (*this)[index];

    // ? Method 2
    // if (index == 0)
    // {
    //     return numerator;
    // }
    // else if (index == 1)
    // {
    //     return denominator;
    // }
    // else
    // {
    //     cout << "Invalid index!" << endl;
    //      return -1;
    // }
}

// * Uniary operator
void Fraction::operator++()
{
    numerator++;
    denominator++;

    int temp = getNum(numerator, denominator);

    numerator /= temp;
    denominator /= temp;
}
void Fraction::operator++(int)
{
    numerator++;
    denominator++;

    int temp = getNum(numerator, denominator);

    numerator /= temp;
    denominator /= temp;
}
void Fraction::operator--()
{
    numerator--;
    denominator--;

    int temp = getNum(numerator, denominator);

    numerator /= temp;
    denominator /= temp;
}
void Fraction::operator--(int)
{
    numerator--;
    denominator--;

    int temp = getNum(numerator, denominator);

    numerator /= temp;
    denominator /= temp;
}

// * () operator
double Fraction::operator()()
{
    return (double)numerator / denominator;
}

void Fraction::operator()(int num, int den)
{
    numerator = num;
    denominator = den;

    int temp = getNum(numerator, denominator);

    numerator /= temp;
    denominator /= temp;
}

// * AND OR operator
bool Fraction::operator&&(const Fraction &other) const
{
    return (numerator * other.denominator) && (denominator * other.numerator);
}
bool Fraction::operator||(const Fraction &other) const
{
    return (numerator * other.denominator) || (denominator * other.numerator);
}
Fraction Fraction::operator&(const Fraction &other)
{
    Fraction result;

    // ? Method 1
    result.numerator = numerator & other.numerator;
    result.denominator = denominator & other.denominator;

    // ? Method 2
    // int temp = getNum(other.numerator, denominator);
    // result.numerator = numerator * other.numerator / temp;
    // result.denominator = temp * other.denominator;

    return result;
}

// * -> operator
Fraction Fraction::operator->()
{
    return *this;
}

Fraction &Fraction::operator->*(int a)
{
    int temp = 0;

    this->numerator *= a;
    this->denominator *= a;

    temp = getNum(numerator, denominator);

    this->numerator /= temp;
    this->denominator /= temp;

    return *this;
}

// }
// Fraction Fraction::operator->*(Fraction *member)
// {
//     return *this;
// }