#include <iostream>
#include <string.h>
using namespace std;

// ! Function Prototypes
int countSubstrs(string str, int starting, int index, int size);

// ! Main Function
int main()
{
	int size = 0;
	string str = "abcab"; // declaration of string

	cout << "\nNumber Of SubString Program" << endl
		 << "--------------------------------" << endl
		 << endl
		 << "Enter String : ";
	cin >> str;

	for (; str[size] != '\0'; size++)
		; // Calculate size of string

	size--;

	cout << "\nNumber of Substrings : " << countSubstrs(str, 0, 0, size) << endl; // Function Calling

	cout << "\n--------------------------------" << endl
		 << endl;

	return 0;
}

// ! Function Definitions

// * Calculating Number of Substrings
int countSubstrs(string str, int starting, int index, int size)
{

	int count = 0;

	if (index <= size)
	{

		if (str[starting] == str[index]) // Comparing elements of String to find Total Combinations
			count++;

		count += countSubstrs(str, starting, index + 1, size); // Calculating Number of Combinations of Substrings
	}

	else if (starting <= size)
	{
		index = starting + 1;
		return count + countSubstrs(str, starting + 1, index, size); // Returning and adding to get total number of Combinations
	}

	return count; // Return the number of Combinations
}
