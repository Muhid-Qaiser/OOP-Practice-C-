#include <iostream>
using namespace std;

// ! Function Definitions

// * Multiplying the values
int multiply(int num1, int num2)
{
	if ((num2 | 0) == 0) // Base condition, if(num2==0)
		return num2;

	return num1 + multiply(num1, num2 - 1); // Adding num1 with itself, num2 number of times And Then Returning the Result
}

// * Cacluating the Power
int power(int base, int exponent, int extra = 1)
{
	if ((exponent | 0) == 0) // Base condition, if(exponent==0)
		return extra;

	return power(base, exponent - 1, multiply(extra, base)); // Returning the result
}

// ! Main Function
int main()
{
	// Variables Initialization
	int base = 0, exponent = 0, extra = 1;

	cout << "\nPower Calculator \n"
		 << "--------------------------------------------\n\n";

	cout << "Enter Base Number : ";
	cin >> base;

	cout << "Enter Exponent Number : ";
	cin >> exponent;

	cout << "\nResult : " << base << "^" << exponent << " = " << power(base, exponent, extra) // Function Calling
		 << "\n\n--------------------------------------------\n\n";

	return 0;
}
