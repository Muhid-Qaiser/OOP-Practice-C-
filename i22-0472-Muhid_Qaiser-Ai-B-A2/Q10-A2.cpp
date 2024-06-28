#include <iostream>
using namespace std;

// ! Function Prototypes and Definitions

// * Printing Spaces
void space(int n)
{
    if (n > 0)
    {
        cout << "  ";
        space(n - 1);
    }
}

// * Printing '*' Symbols
void print(int n)
{
    if (n > 1)
    {
        cout << "* ";
        print(n - 1);
    }
}

// * Printing Pattern
void PrintPattern(int num1, int num2, int num3)
{
    // Prints the Upper Half of the pattern
    if (num1 > 0)
    {
        space(num1);
        cout << "| ";
        space(num1);

        if (num2 != 1)
            print(num2);

        cout << "| ";

        if (num2 != 1)
            print(num2);

        space(num1);
        cout << "| ";
        cout << endl;

        PrintPattern(num1 - 1, num2 + 2, num3); // Function recalling

        // Prints the Lower Half of the pattern
        if (num1 != 1)
        {

            space(num1);
            cout << "| ";

            space(num1);
            print(num2);
            cout << "| ";

            print(num2);
            space(num1);
            cout << "| ";
            cout << endl;
        }
    }
}

// ! Main Function
int main()
{
    // Variables Initialization
    int num1 = 0, num2 = 0, num3 = 0;

    cout << "\nPattern Printing Program " << endl
         << "---------------------------------------------" << endl
         << endl

         << "Enter First Number : ";
    cin >> num1;

    cout << "Enter Second Number : ";
    cin >> num2;

    cout << "Enter Third Number : ";
    cin >> num3;

    cout << "\nResult : " << endl
         << endl;

    PrintPattern(num1, num2, num3); // Function calling

    cout << "\n\n---------------------------------------------" << endl
         << endl;

    return 0;
}