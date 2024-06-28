#include <iostream>
using namespace std;

// todo change matrix type to float and return float value at i,j

class Matrix
{
    float **matrix;
    int row;
    int col;

public:
    Matrix();
    Matrix(int, int);
    Matrix(const Matrix &);

    float &operator()(int &i, int &j);
    float &operator()(int &i, int &j) const;

    Matrix &operator=(const Matrix &);

    bool operator==(const Matrix &);

    Matrix operator+(const Matrix &);
    Matrix operator-(const Matrix &);

    Matrix operator*(const Matrix &);

    Matrix &operator++(int);

    void operator+=(const Matrix &);
    void operator-=(const Matrix &);

    int getRow();
    int getCol();

    ~Matrix();

    friend istream &operator>>(istream &input, Matrix &obj);
    friend ostream &operator<<(ostream &output, const Matrix &obj);
};
