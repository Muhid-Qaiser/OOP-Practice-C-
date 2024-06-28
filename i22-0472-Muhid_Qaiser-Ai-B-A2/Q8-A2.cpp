#include <iostream>
using namespace std;

// ! Function Prototypes and Definitions

// * Prints Space
void space(int n)
{
    if (n > 0)
    {
        cout << " ";
        space(n - 1);
    }
}

// * Prints X Pattern
void PrintPattern(int start, int end)
{
    // Prints Upper Half of Pattern
    if (start <= end)
    {
        space(start);
        cout << "*";
        space(end - start + 1);
        cout << "*";
        cout << endl;
        PrintPattern(start + 1, end - 1);
    }

    // Prints Lower Half of Pattern
    space(start);
    cout << "*";

    if (start != end + 2)
    {
        space(end - start + 1);
        cout << "*";
    }

    cout << endl;
}

// ! Main Function
int main()
{
    // Variables Initialization
    int start = 1, end = 0;

    cout << "\nX Pattern Printing Program" << endl
         << "--------------------------------" << endl
         << endl

         << "Enter Dimension of the X : ";
    cin >> end;

    cout << "\nPattern : "
         << endl
         << endl;

    PrintPattern(start, end); // Function Calling

    cout << "\n--------------------------------" << endl
         << endl;

    return 0;
}