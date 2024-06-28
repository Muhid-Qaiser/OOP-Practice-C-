#include <iostream>
using namespace std;

// ! Function Prototypes
bool isSubstr(char *str1, char *str2);

// ! Main Function
int main()
{
	// String Declarations
	char str1[100], str2[100];

	// Clearing the Strings
	str1[0] = '\0';
	str2[0] = '\0';

	cout << "\nSubString Finder Program" << endl
		 << "---------------------------------" << endl
		 << endl;

	// Inputting String in Variables
	cout << "Enter String 1 : ";
	cin.getline(str1, 100);

	cout << "Enter String 2 : ";
	cin.getline(str2, 100);

	// Function Calling and Checking
	(isSubstr(str1, str2)) ? cout << "\nYes, \"" << str2 << "\" is a substring of \"" << str1 << "\"." << endl : cout << "\nNo, \"" << str2 << "\" is not a substring of \"" << str1 << "\"." << endl;

	cout << "\n---------------------------------" << endl
		 << endl;

	return 0;
}

// ! Function Definition

// * Finding Substrings
bool isSubstr(char *str1, char *str2)
{
	// If str2 ends first, str2 is a substring
	if (*str2 == '\0')
		return true;

	// If str1 ends first, str2 is Not a substring
	if (*str1 == '\0')
		return false;

	// Checking to See if elements of str1 and str2 are same or Not
	if (*str1 == *str2)
		return isSubstr(str1 + 1, str2 + 1); // str1 and str2 are same, Move Foward together to check the Next character

	return isSubstr(str1 + 1, str2); // str1 and str2 are Not same, Move str1 Foward together to check if the next character of st1 is Same as str2
}