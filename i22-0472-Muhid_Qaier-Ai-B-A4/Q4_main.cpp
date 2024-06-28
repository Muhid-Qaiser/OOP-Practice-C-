// ? For Project files / VS
// #include "Q4.h"

// ? For VS Code
#include "Q4_fun.cpp"

#include <iostream>
using namespace std;

int main()
{
     cout << "\n\nPolynomial Manipulation System" << endl
          << "========================================\n\n";

     // Polynomial p1(2), p2;

     int degree1 = 0, degree2 = 0;

     cout << "Enter Degree of First Polynomial : ";
     cin >> degree1;

     cout << "\nEnter Degree of Second Polynomial : ";
     cin >> degree2;
     cout << endl;

     Polynomial p1(degree1), p2; // using contructors

     cout << "\nEnter p1 : \n";
     cin >> p1; // inputing polynomial
     cout << "\np1 : " << p1 << endl;

     p2 = p1; // using = operator
     cout << "\np2 = p1 : " << p2 << endl
          << endl;

     cout << "p2 == p1 : ";
     (p1 == p2) ? cout << "Same\n\n" : cout << "Not Same\n\n"; // checking to see if 2 polynomials are equal

     // Polynomial p3(3);
     Polynomial p3(degree2);

     cout << "\nEnter p3 : \n";
     cin >> p3;
     cout << "\np1 == p3 : ";
     (p1 == p3) ? cout << "Same\n\n" : cout << "Not Same\n\n"; // checking to see if 2 polynomials are equal

     Polynomial p4;
     p4 = p1 - p3; // subtracting 2 polynomials
     cout << "p4 = p1 - p3 : " << p4 << endl
          << endl;

     p4 = p3 - p1; // subtracting 2 polynomials
     cout << "p4 = p3 - p1 : " << p4 << endl
          << endl;

     p4 = p3 + p1; // adding 2 polynomials
     cout << "p4 = p3 + p1 : " << p4 << endl
          << endl;

     p4 = p1 + p3; // adding 2 polynomials
     cout << "p4 = p1 + p3 : " << p4 << endl
          << endl;

     p1 += p4; // adding 2 polynomials
     cout << "p1 += p4 : " << p1 << endl
          << endl;

     p1 -= p4; // subtracting 2 polynomials
     cout << "p1 -= p4 : " << p1 << endl
          << endl;

     p4 += p1; // adding 2 polynomials
     cout << "p4 += p1 : " << p4 << endl
          << endl;

     p4 -= p1; // subtracting 2 polynomials
     cout << "p4 -= p1 : " << p4 << endl
          << endl;

     cout << "\nProgram Ending..." << endl;
     cout << "\n========================================\n\n";

     return 0;
}