#include <iostream>
using namespace std;

// ! Function Prototypes
long permute(int, int);

// ! Main Functuon
int main()
{
	int n = 0, r = 0;

	cout << "\nFactorial formula Calculating Program" << endl
		 << "--------------------------------" << endl
		 << endl
		 << "Enter n : ";
	cin >> n;

	cout << "Enter r : ";
	cin >> r;

	cout << "\nResult : " << permute(n, r)
		 << "\n\n--------------------------------" << endl
		 << endl;

	return 0;
}

// ! Function Definitions

// * Calcating Factorial of Denominator
long permute2(int n, int r)
{
	if (n - r <= 0)
	{
		return 1;
	}

	return (n - r);
}

// * Calculating the Factorial of the Numerator and The Result
long permute(int n, int r)
{
	if (n <= 0)
	{
		return 1;
	}

	// Other Method of Returning the Factorial
	// ? return (n * permute(n - 1, r)) / permute2(n, r); // Function recalling and returning

	long denominator = permute2(n, r), numerator = (n * permute(n - 1, r)); // Calculating Factorials

	return numerator / denominator; // Function recalling and returning
}
