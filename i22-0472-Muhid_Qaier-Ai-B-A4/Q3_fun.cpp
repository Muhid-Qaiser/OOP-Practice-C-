#include <iostream>
#include "Q3.h"
using namespace std;

// * >> and << operator
ostream &operator<<(ostream &output, const Matrix &obj)
{
    for (int i = 0; i < obj.row; i++)
    {
        cout << "| ";
        for (int j = 0; j < obj.col; j++)
            output << obj.matrix[i][j] << " ";
        cout << "| \n";
    }
    return output;
}
istream &operator>>(istream &input, Matrix &obj)
{
    for (int i = 0; i < obj.row; i++)
        for (int j = 0; j < obj.col; j++)
        {
            cout << "Element[" << i << "][" << j << "] : ";
            input >> obj.matrix[i][j];
        }

    return input;
}

// * getters
int Matrix::getRow()
{
    return row;
}
int Matrix::getCol()
{
    return col;
}

// * constructor
Matrix::Matrix()
{
    matrix = NULL;
    row = 0;
    col = 0;
}
Matrix::Matrix(int r, int c)
{
    row = r;
    col = c;

    matrix = new float *[row];
    for (int i = 0; i < row; i++)
    {
        matrix[i] = new float[col];
        for (int j = 0; j < col; j++)
            matrix[i][j] = 0;
    }
}
Matrix::Matrix(const Matrix &m)
{
    row = m.row;
    col = m.col;

    matrix = new float *[row];

    for (int i = 0; i < row; i++)
    {
        matrix[i] = new float[col];
        for (int j = 0; j < col; j++)
            matrix[i][j] = m.matrix[i][j];
    }
}

// * destructor
Matrix::~Matrix()
{
    for (int i = 0; i < row; i++)
    {
        delete[] matrix[i];
        matrix[i] = NULL;
    }
    delete[] matrix;
    matrix = NULL;

    row = 0;
    col = 0;
}

// * () operator
float &Matrix::operator()(int &i, int &j)
{
    return this->matrix[i][j];
}
float &Matrix::operator()(int &i, int &j) const
{
    return this->matrix[i][j];
}

// * = and == operator
Matrix &Matrix::operator=(const Matrix &m)
{
    row = m.row;
    col = m.col;
    matrix = new float *[row];

    for (int i = 0; i < row; i++)
    {
        matrix[i] = new float[col];
        for (int j = 0; j < col; j++)
            matrix[i][j] = m.matrix[i][j];
    }

    return *this;
}
bool Matrix::operator==(const Matrix &m)
{
    if (row != m.row || col != m.col)
        return false;

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            if (matrix[i][j] != m.matrix[i][j])
                return false;
    return true;
}

// *     + , - and * operator
Matrix Matrix::operator+(const Matrix &m)
{
    Matrix result;
    result.row = row;
    result.col = col;

    result.matrix = new float *[result.row];

    for (int i = 0; i < row; i++)
    {
        result.matrix[i] = new float[result.col];
        for (int j = 0; j < col; j++)
            result.matrix[i][j] = matrix[i][j] + m.matrix[i][j];
    }
    return result;
}
Matrix Matrix::operator-(const Matrix &m)
{
    Matrix result;
    result.row = row;
    result.col = col;

    result.matrix = new float *[result.row];

    for (int i = 0; i < row; i++)
    {
        result.matrix[i] = new float[result.col];
        for (int j = 0; j < col; j++)
            result.matrix[i][j] = matrix[i][j] - m.matrix[i][j];
    }
    return result;
}
Matrix Matrix::operator*(const Matrix &m)
{
    Matrix result;
    result.row = row;
    result.col = col;

    result.matrix = new float *[result.row];

    for (int i = 0; i < row; i++)
    {
        result.matrix[i] = new float[result.col];
        for (int j = 0; j < col; j++)
            result.matrix[i][j] = matrix[i][j] * m.matrix[i][j];
    }
    return result;
}

// * ++ operator
Matrix &Matrix::operator++(int)
{
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            matrix[i][j]++;
    return *this;
}

// * += and -= operator
void Matrix::operator+=(const Matrix &m)
{
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            matrix[i][j] += m.matrix[i][j];
}
void Matrix::operator-=(const Matrix &m)
{
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            matrix[i][j] -= m.matrix[i][j];
}
