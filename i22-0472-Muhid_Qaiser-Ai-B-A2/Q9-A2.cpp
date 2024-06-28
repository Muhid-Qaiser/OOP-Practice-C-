#include <iostream>
using namespace std;

// ! Function Prototypes and Definitions

// * Printing Space
void space(int n, char ch)
{
	if (n > 0)
	{
		cout << ch;

		space(n - 1, ch); // Print the space
	}
}

// * Printing the Pattern
void Fn1(int num, char ch, int a, int b)
{

	if (num - 1 == a)
	{
		space(num, 32); // Print the Space
		cout << "*";	// Print the Character
		cout << endl;
	}

	if (a > 1)
	{
		space(a, 32); // Print the Space

		cout << "*";  // Print the Character
		space(b, 32); // Print the Space

		cout << "*"; // Print the Character
		cout << endl;

		Fn1(num, ch, a - 1, b + 1); // Function Recalling
	}
}

// * Solving the PrintPattern problem
void PrintPattern(int num, char ch)
{

	Fn1(num, ch, num - 1, 0); // Function Calling

	cout << " ";
	space(num, 42); // Print the Space
}

// ! Main Function
int main()
{

	int num = 0;
	char ch = '*';

	cout << "\nHollow Triangle Pattern Printing Program" << endl
		 << "--------------------------------" << endl
		 << endl
		 << "Enter Number : ";
	cin >> num;

	cout << endl;

	PrintPattern(num, '*');

	cout << "\n\n--------------------------------" << endl
		 << endl;
}
