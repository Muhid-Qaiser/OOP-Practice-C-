#include <iostream>
#include <string>
using namespace std;

// ! Function Prototypes

int additionOfRollNumber(string rollnumber);

int FillArray(int arr[], int index, int calculatedNumber);

// ! Main Function
int main()
{
    // Variable Initialize
    int calculatedNumber = 0;

    // Declaring Roll Number and Clearing it from Garbage Value
    string rollnumber = "";

    // Initializing arr with 50 Numbers
    int arr[50] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
                   21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39,
                   40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50};

    cout << "\nRoll Number Addition Calculator " << endl
         << "-------------------------------------\n\n"

         << "Enter Roll Number : ";
    cin >> rollnumber;

    calculatedNumber = additionOfRollNumber(rollnumber); // Function calling

    cout << "\nSum of Roll Number : " << calculatedNumber << endl;

    cout << "\nSum at intervals : " << FillArray(arr, 0, calculatedNumber) << endl; // Function calling

    cout << "\n-------------------------------------\n\n";
}

// ! Function Definition

// * Function to add Roll Number
int additionOfRollNumber(string rollnumber)
{
    int sum = rollnumber[0] - 48 + rollnumber[1] - 48 + rollnumber[4] - 48 + rollnumber[5] - 48 + rollnumber[6] - 48 + rollnumber[7] - 48;

    return sum / 2;
}

// * Function to calculate Sum of Roll Number on the Number's Indexes
int FillArray(int arr[], int index, int calculatedNumber)
{
    // ? other method here
    /*
    if (index == 50)
    {
        return 0;
    }

    if ((index + 1) % calculatedNumber == 0)
    {
        return arr[index] + FillArray(arr, index + 1, calculatedNumber);
    }

    return FillArray(arr, index + 1, calculatedNumber);
     */

    if (index < 50)
    {
        if ((index + 1) % calculatedNumber == 0)
        {
            return arr[index] + FillArray(arr, index + 1, calculatedNumber);
        }

        return FillArray(arr, index + 1, calculatedNumber);
    }

    return 0;
}
