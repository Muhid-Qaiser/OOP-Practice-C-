#include <iostream>
#include <string.h>
using namespace std;

// ! Function Protoypes and Definitions

// * Converting Decimal to Binary
int toBinary(int num, int extra = 0)
{
	if (num < 2)
		return num;
	return (toBinary(num / 2) * 10) + num % 2; // multiplying num/10 with 10 to get a number in 0-1 and then adding it with the Mod of 2 of the Number
}

// * Converting Decimal to Octal
int toOctal(int num, int extra = 0)
{
	if (num < 8)
		return num;
	return (toOctal(num / 8) * 10) + num % 8; // multiplying num/8 with 10 to get a number in 0-7 and then adding it with the Mod of 8 of the Number
}

// * Converting Decimal to Hexadecimal
string toHexa(int num, int extra = 0)
{
	char digit;
	if (num % 16 < 10)
		digit = num % 16 + 48; // calculating digit in the form of a hexadecimal and getting result, 0-9
	else
		digit = 65 + (num % 16) % 10; // calculating digit in the form of a hexadecimal and getting result, A-F

	if (num < 16)
	{
		string temp;
		temp += digit; // returning digit in the form of a string
		return temp;
	}
	return toHexa(num / 16) + digit; // Dividing num by 16 to get a number in 0-15 and then adding it with digit
}

// ! Main Function
int main()
{
	// Variables Initialization
	int num = 0;

	cout << "\nDecimal Conversion Program" << endl
		 << "-----------------------------------------------------\n\n"

		 << "Enter Number : ";
	cin >> num;

	cout << "\nDecimal : " << num << " , Binary : " << toBinary(num) << endl // Function calling
		 << endl

		 << "Decimal : " << num << " , Octal : " << toOctal(num) << endl // Function calling
		 << endl

		 << "Decimal : " << num << " , Hexadecimal : " << toHexa(num) << endl // Function calling
		 << endl

		 << "-----------------------------------------------------\n\n";
}
