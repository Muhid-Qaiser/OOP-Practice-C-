// ? For Project files / VS
// #include "Q3.h"

// ? For VS Code
#include "Q3_fun.cpp"

#include <iostream>
using namespace std;

int main()
{
     cout << "\n\nMatrix Manipulating System " << endl
          << "================================\n\n";

     //  Matrix m1(2, 2), m2(2, 2);
     int x = 0, y = 0, a = 0, b = 0, val = 0;

     cout << "Enter Row : ";
     cin >> x;
     cout << "Enter Column : ";
     cin >> y;

     Matrix m1(x, y), m2(x, y), m3;

     cout << "\nEnter m1 : \n\n";
     cin >> m1; // input matrix

     cout << endl
          << "m1 : \n"
          << m1 << endl; // output matrix

     // ? Input of m2
     // cout << "m2 : \n";
     // cin >> m2;
     // cout << endl
     //      << m2;

     m3 = m1; // using = operator
     cout << "m3 = m1 : \n"
          << m3 << endl;

     cout << "m1 == m3 : ";
     (m1 == m3) ? cout << "Same\n" : cout << "Not Same\n"; // checking to see if the matrix are equal

     m2 = m1 + m3; // adding 2 matrixes
     cout << "\nm2 = m1 + m3 : \n"
          << m2 << endl;

     m2 = m1 - m3; // subtracting 2 matrixes
     cout << "\nm2 = m1 - m3 : \n"
          << m2 << endl;

     m2 = m1 * m3; // multiplying 2 matrixes
     cout << "\nm2 = m1 * m3 : \n"
          << m2 << endl;

     m2++; // incrementing each element of matrix by 1
     cout << "m2++ : \n"
          << m2 << endl;

     m2 += m1; // adding 2 matrixes
     cout << "m2 += m1 : \n"
          << m2 << endl;

     m2 -= m1; // subtracting 2 matrixes
     cout << "m2 -= m1 : \n"
          << m2 << endl;

     // val = 9;
     // m2(a, b) = 9;

     cout << "\nEnter row index 0-" << x - 1 << " : ";
     cin >> a;

     while (a >= x)
     {
          cout << "\nInvalid row index !!" << endl
               << "\nEnter row index 0-" << x - 1 << " : ";
          cin >> a;
     }

     cout << "\nEnter column index 0-" << y - 1 << " : ";
     cin >> b;

     while (b >= y)
     {
          cout << "\nInvalid column index !!" << endl
               << "\nEnter row index 0-" << y - 1 << " : ";
          cin >> b;
     }

     cout << "\nEnter the Value you want to replace at matrix(" << a << " , " << b << ") : ";
     cin >> val;

     m2(a, b) = val; // replacing the value at index(a,b) with val

     cout << "\nm2(" << a << " , " << b << ") = " << val << " : \n"
          << m2 << endl;

     cout << "\nProgram Ending..." << endl;
     cout << "\n================================\n\n";

     return 0;
}