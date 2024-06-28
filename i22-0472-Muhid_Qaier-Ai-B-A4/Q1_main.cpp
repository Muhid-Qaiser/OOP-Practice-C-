// ? For Project files / VS
// #include "Q1.h"

// ? For VS Code
#include "Q1_fun.cpp"

#include <iostream>
using namespace std;

int main()
{
    cout << "\n\nFraction Manipulation System" << endl
         << "================================\n\n";

    int a = 0, b = 0;

    Fraction f1, f2, result, f[2];

    cout << "Fraction f1 : \n";
    cin >> f1;

    cout << "\nFraction f2 : \n";
    cin >> f2;

    // Fraction f1(3, 4), f2(5, 6), result, f[2];
    Fraction *f3 = &f1;

    f1.display();

    result = f1 + f2;
    cout << "result = f1 + f2 : " << result << endl;
    result = f1 - f2;
    cout << "result = f1 - f2 : " << result << endl;
    result = f1 * f2;
    cout << "result = f1 * f2 : " << result << endl;
    // ? Method 1 :
    // result = f1 / f2;
    // cout << "result = f1 / f2 : " << result << endl;

    // ? Method 2 :
    if ((f1.getDenominator() * f2.getNumerator()) == 0)
    {
        cout << "result = f1 / f2 : Undefined. \n\n!Error : Denominator = 0!" << endl
             << endl;
        result(0, 1);
    }
    else
    {
        result = f1 / f2;
        cout << "result = f1 / f2 : " << result << endl;
    }

    result += f1;
    cout << "result += f1 : " << result << endl;
    result -= f1;
    cout << "result -= f1 : " << result << endl;
    result *= f1;
    cout << "result *= f1 : " << result << endl;
    // ? Method 1 :
    // result /= f1;
    // cout << "result /= f1 : " << result << endl;

    // ? Method 2 :
    if ((result.getDenominator() * f1.getNumerator()) == 0)
    {
        cout << "result /= f1 : Undefined. \n\n!Error : Denominator = 0!" << endl
             << endl;
        result(0, 1);
    }
    else
    {
        result = f1 / f2;
        cout << "result /= f1 : " << result << endl;
    }

    cout << "f1 == f2 : ";
    (f1 == f2) ? cout << " - True\n\n" : cout << " - False \n\n";
    cout << "f1 != f2 : ";
    (f1 != f2) ? cout << " - True\n\n" : cout << " - False \n\n";
    cout << "f1 > f2  : ";
    (f1 > f2) ? cout << " - True\n\n" : cout << " - False\n\n";
    cout << "f1 < f2  : ";
    (f1 < f2) ? cout << " - True\n\n" : cout << " - False\n\n";
    cout << "f1 >= f2 : ";
    (f1 >= f2) ? cout << " - True\n\n" : cout << " - False\n\n";
    cout << "f1 <= f2 : ";
    (f1 <= f2) ? cout << " - True\n\n" : cout << " - False\n\n";

    f[0] = 4;
    cout << "f[0] : " << f[0] << endl;

    result++;
    cout << "result++ = " << result << endl;

    // ? Method 1 :
    // result--;
    // cout << "result-- = " << result << endl;

    // ? Method 2 :
    if (result.getDenominator() - 1 == 0)
    {
        cout << "result-- = Undefined. \n\n!Error : Denominator = 0!" << endl;
        result(0, 1);
    }
    else
    {
        result--;
        cout << "result-- = " << result << endl;
    }

    // result(4, 20);

    cout << "\nEnter a : ";
    cin >> a;
    cout << "\nEnter b : ";
    cin >> b;
    result(a, b);

    cout << "\nresult(" << a << " , " << b << ") = " << result << endl;

    cout << "f1 && f2 : " << (f1 && f2) << endl;

    cout << "\nf1 || f2 : " << (f1 || f2) << endl;

    result = f1 & f2;
    cout << "\nf1 & f2 : " << result << endl;

    cout << "\nf3 : ";
    f3->display();

    // todo ->* was not taught
    cout << "Enter a Value : ";
    cin >> a;

    if (a != 0)
        cout << "\nf1->*" << a << " : " << f1->*a << endl;
    else
        cout << "\nf1->*" << a << " : 0/0" << endl;

    cout << "\n\nProgram Ending..." << endl;
    cout << "\n================================\n\n";

    // result = f1 + f1 * f1 / f2 / f2;
    // cout << "res : " << result << endl;

    // result -= f1 + f2;
    // cout << "res : " << result << endl;
    // result += f1 + f2;
    // cout << "res : " << result << endl;
    // result *= f1 + f2;
    // cout << "res : " << result << endl;
    // result /= f1 + f2;
    // cout << "res : " << result << endl;

    return 0;
}