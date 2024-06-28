#include <iostream>
#include "Q5.h"
using namespace std;

ostream &operator<<(ostream &output, const Array &obj)
{
    output << "{ ";
    for (int i = 0; i < obj.size; i++)
    {
        output << obj[i];
        if (i != obj.size - 1)
            output << ", ";
    }
    output << " }";

    return output;
}
istream &operator>>(istream &input, const Array &obj)
{
    for (int i = 0; i < obj.size; i++)
    {
        cout << "Array[" << i << "] : ";
        input >> obj[i];
    }
    return input;
}

// * Constructors
Array::Array()
{
    size = 0;
    array = NULL;
}
Array::Array(int size)
{
    this->size = size;
    array = new int[size];
}
Array::Array(int *arr, int size)
{
    this->size = size;
    array = new int[size];

    for (int i = 0; i < size; i++)
        array[i] = arr[i];
}
Array::Array(const Array &a)
{
    this->size = a.size;
    array = new int[size];

    for (int i = 0; i < size; i++)
        array[i] = a.array[i];
}

// * Destructor
Array::~Array()
{
    size = 0;
    delete[] array;
    array = NULL;
}

// * [] operator
int &Array::operator[](int i)
{
    int *invalid = new int;
    *invalid = -1;

    if (i <= size)
        return array[i];
    else
        return *invalid;
}
int &Array::operator[](int i) const
{
    int *invalid = new int;
    *invalid = -1;

    if (i <= size)
        return array[i];
    else
        return *invalid;
}

// * = operator
const Array &Array::operator=(const Array &a)
{
    size = a.size;
    array = new int[size];

    for (int i = 0; i < size; i++)
        array[i] = a.array[i];

    return *this;
}

// * arithmetic operator
Array Array::operator+(const Array &a)
{
    Array result;
    result.size = (size > a.size) ? size : a.size;
    result.array = new int[result.size];

    if (size > a.size)
        for (int i = 0; i < size; i++)
            if (i < a.size)
                result.array[i] = array[i] + a.array[i];
            else
                result.array[i] = array[i];

    else
        for (int i = 0; i < a.size; i++)
            if (i < size)
                result.array[i] = array[i] + a.array[i];
            else
                result.array[i] = a.array[i];
    return result;
}
Array Array::operator-(const Array &a)
{
    Array result;
    result.size = (size > a.size) ? size : a.size;
    result.array = new int[result.size];

    if (size > a.size)
        for (int i = 0; i < size; i++)
            if (i < a.size)
                result.array[i] = array[i] - a.array[i];
            else
                result.array[i] = array[i];

    else
        for (int i = 0; i < a.size; i++)
            if (i < size)
                result.array[i] = array[i] - a.array[i];
            else
                result.array[i] = a.array[i];
    return result;
}
Array Array::operator++()
{
    for (int i = 0; i < size; i++)
        this->array[i]++;
    return *this;
}
Array Array::operator++(int)
{
    for (int i = 0; i < size; i++)
        this->array[i]++;
    return *this;
}
Array &Array::operator--(int)
{
    for (int i = 0; i < size; i++)
        this->array[i]--;
    return *this;
}

// * == operator
bool Array::operator==(const Array &a) const
{
    if (size != a.size)
        return false;

    for (int i = 0; i < size; i++)
        if (array[i] != a.array[i])
            return false;
    return true;
}

// * ! operator
bool Array::operator!()
{
    if (size == 0)
        return true;
    return false;
}

// * +=/-= operator
void Array::operator+=(const Array &a)
{
    for (int i = 0; i < size; i++)
        this->array[i] += a.array[i];
}
void Array::operator-=(const Array &a)
{
    for (int i = 0; i < size; i++)
        this->array[i] -= a.array[i];
}

void leftShift(int array[], int &size, int index)
{
    for (int i = index; i < size - 1; i++)
        array[i] = array[i + 1];
    array[size - 1] = 0;
    size--;
}

// * () operator
int Array::operator()(int idx, int val)
{
    for (int i = 0; i < size; i++)
    {
        if (i == idx)
        {
            if (array[i] == val)
            {
                leftShift(array, size, i);
                return 1;
            }
        }
    }
    return -1;
}
