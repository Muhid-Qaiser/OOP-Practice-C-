// ? For Project files / VS
// #include "Q5.h"

// ? For VS Code
#include "Q5_fun.cpp"

#include <iostream>
using namespace std;

int main()
{
    cout << "\n\nArray Manipulation System" << endl
         << "================================\n\n";

    //  Array a1(3), a2, a3, a4(6);

    int size1 = 0, size2 = 0, i = 0, value = 0;

    cout << "Enter Size of Array1 : ";
    cin >> size1;

    cout << "Enter Size of Array4 : ";
    cin >> size2;

    Array a1(size1), a2, a3, a4(size2);

    cout << "\nEnter Array1 : \n";
    cin >> a1; // input array
    cout << "\na1 : " << a1 << endl;

    a2 = a1; // using = operator
    cout << "\na2 = a1 : " << a2 << endl;

    // int i = 9;
    cout << "\nEnter Index : ";
    cin >> i;
    cout << "\nindex at " << i << " : " << a1[i] << endl; // finds value at index

    cout << "\nEnter Array4 : \n";
    cin >> a4;

    a3 = a1 + a4; // adds 2 arrays
    cout << "\na3 = a1 + a4 : " << a3 << endl;

    a3++; // increments the entire array's value by 1
    cout << "\na3++ : " << a3 << endl;

    a3--; // decrements the entire array's value by 1
    cout << "\na3-- : " << a3 << endl;

    cout << "\nEnter index for a3 : ";
    cin >> i;
    cout << "\nEnter Value for Index[" << i << "] that you want to eliminate in a3 : ";
    cin >> value;
    (a3(i, value)) ? cout << "\nValue Eliminated Successfully!\n" : cout << "\nValue Not Eliminated!\n"; // Delete a value at index if Fount
    cout << "\na3 : " << a3 << endl;
    // cout << a3(1, 8);

    cout << "\nProgram Ending..." << endl;
    cout << "\n================================\n\n";

    return 0;
}