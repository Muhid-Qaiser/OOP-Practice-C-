#include <iostream>
#include <string>
using namespace std;

// ! Function Prototypes
int SearchDigit(long long int A, int B, int C);

int checkSize(long long int A, int base);

// ! Main Function
int main()
{
    long long int A = 0; // Declaring long long int so that number > 9 digits can be entered to check it's Validity

    int B = 0, C = 1, temp = 0, count = 0;

    cout << "\nNumber Placement Calculator" << endl
         << "----------------------------------------------" << endl;

    cout << "\nEnter the first number(less than 9 digits): ";
    cin >> A;

    cout << "\nEnter the number you want to find : ";
    cin >> B;

    if (SearchDigit(A, B, C) != -1) // Function calling and Checking the result
        cout << endl
             << "Result : "
             << B << " was situated on the " << SearchDigit(A, B, C) << "th Postion in " << A << endl
             << endl
             << "----------------------------------------------" << endl
             << endl;

    else
        cout << endl
             << "Error : " << endl
             << B << " was not Found in " << A << endl
             << "OR" << endl
             << A << " exceeds the maximum digits allowed(9)" << endl
             << endl
             << "----------------------------------------------" << endl
             << endl;

    return 0;
}

// ! Function Definitions

// * Checking Size of A
int checkSize(long long int num, int base)
{

    if (base > 0 && num > 0)
    {
        return checkSize(num / 10, base - 1); // dividing by zero to check it's size
    }

    else if (base >= 0 && num == 0) // If num == 0 and base >=0, then return true
        return true;

    else
        return false;
}

// * Searching for the Digit from Right Hand Side
int SearchDigit(long long int A, int B, int C)
{
    // ? Second Method
    /*
        if (!checkSize(A, 9))
            return -1;

        if (A == 0)
            return -1;
    */

    //? Optimized Method
    if (A == 0 || (!checkSize(A, 9))) // Checking for Validity and If the Digit is Present in the Number
        return -1;

    else if (A % 10 == B) // Checking for Position of the Digit in the Number
        return C;         // Return the position of the Digit

    else
    {
        C++;
        A /= 10;

        SearchDigit(A, B, C); // Function Recalling
    }
}
