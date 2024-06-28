#include <iostream>
using namespace std;

// ! Function Prototypes
void Pattern(int, int, char, char);

void print(int, char);

// ! Main function
int main()
{
	int first = 0, end = 0;

	cout << "\nPattern Printing Program" << endl
		 << "--------------------------------" << endl
		 << endl;

	cout << "Enter First Number : ";
	cin >> first;

	cout << "Enter Ending Number : ";
	cin >> end;

	cout << endl;

	cout << "Result : ";
	Pattern(first, end, '^', '*');

	cout << "\n\n--------------------------------" << endl
		 << endl;
}

// ! Function Definitions

// * Pattern Constructor
void Pattern(int first, int end, char a, char b)
{
	// Printing the First Half of the pattern
	if (first >= end)
	{
		cout << first;

		// Checking to see which Symbol to Print
		if (first % 2 == 0)
			print(first, '^');

		else
			print(first, '*');

		return;
	}

	cout << first;

	// Checking to see which Symbol to Print
	if (first % 2 == 0)
		print(first, '^');

	else
		print(first, '*');

	// Function recalling
	Pattern(first + 1, end, a, b);

	// Printing the Second Half of the Pattern
	cout << first;

	// Checking to see which Symbol to Print
	if (first % 2 == 0)
		print(first, '^');

	else
		print(first, '*');
}

// * Printing the Symbol
void print(int num, char symbol)
{
	if (num > 0)
	{
		cout << symbol;

		print(num - 1, symbol);
	}
}
