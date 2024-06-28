#include <iostream>
using namespace std;

// ! Function Prototypes

int countDigits(int, int);

int FindCount(int, int);

// ! Main Function
int main()
{
	// Variable Initialization
	int n = 0, m = 0;

	cout << "\nCount Digit Function"
		 << "\n------------------------------------------\n\n";

	cout << "Enter the Big Number : ";
	cin >> n;

	cout << "\nEnter the Number you want to find the Occurance of : ";
	cin >> m;

	cout << "\nThe Number " << m << " appears in 0-" << n << " , " << countDigits(n, m) << " times" // Function calling
		 << "\n\n------------------------------------------\n\n";
}

// ! Function Definitions

// * Finding the Occurance of a Number in a Big Number
int FindCount(int n, int m)
{

	if (n <= 0)
		return 0;

	else
	{
		if (n % 10 == m)
		{

			return 1 + FindCount(n / 10, m);
		}
		FindCount(n / 10, m);
	}
}

// * Function to Find Total Occurance of a Number from 0 - n
int countDigits(int n, int m)
{
	if (n > 0)
		return FindCount(n, m) + countDigits(n - 1, m);

	return 0;
}
