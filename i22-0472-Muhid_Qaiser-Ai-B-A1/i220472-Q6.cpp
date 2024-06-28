#include <iostream>
#include <string.h>
using namespace std;


void countLetters(char* string, int*& array, int& size);

void DisplayCount(int* array);

int ExtractWord(char* string, int& index);

void countWordsBasedOnLength(char* string, int*& array, int& size);

bool IsWordEnd(const char ch);

void DisplayWordLength(int* array, int index);

void countingUniqueWords(char* string, char**& uwords, int*& array, int& size);

bool compareWord(char* uwords, char* word);

char* ExtractWord2(char* string, int& index);

void DisplayUwordCount(char** uwords, int* array, int size);

void initialize(int* array, int size);

int main()
{
	int size = 60, lines = 0, arraysize = 26;

	char** Files = NULL, ** uword = NULL;

	char* string = new char[100];

	int* array = new int[arraysize];


	for (int i = 0; i < arraysize; i++)
		*(array + i) = 0;
		//	array[i] = 0;
	
	for (int i = 0; i < 100; i++)
		*(string + i) = '\0';
	//	string[i] = '\0';
	

	//initialize(array, arraysize);
	
	cout << "Sentence Information" << endl 
		 << "--------------------------" << endl << endl 
		 << "Enter sentence(s) : ";

	cin.getline(string, 60);

	cout << string;



	cout << "\n\n1.";

	countLetters(string, array, arraysize);

	DisplayCount(array);

	cout << "\n2.";


	initialize(array, arraysize);

	countWordsBasedOnLength(string, array, arraysize);

	DisplayWordLength(array, arraysize);

	cout << "\n3.";

	initialize(array, arraysize);


	for (int i = 0; i < arraysize; i++)
		*(array + i) = 0;

	countingUniqueWords(string, uword, array, arraysize);

	DisplayUwordCount(uword, array, arraysize);


}


void countLetters(char* string, int*& array, int& size)
{
	char checkBigLetter = '\0',
		checkSmallLetter = '\0';


	for (int i = 0; i < 26; i++)
	{
		checkBigLetter = i + 65;
		checkSmallLetter = i + 97;

		for (int j = 0; j < 60; j++)
		{

			if (string[j] == checkBigLetter || string[j] == checkSmallLetter)
			{
				array[i]++;
				//*(array+i)++;
			
			}

		}
	}

	cout << endl;

}

void DisplayCount(int* array)
{
	char letter = '\0';

	cout << "Letter Count :-" << endl;

	for (int i = 0; i < 26; i++)
	{
		letter = i + 65;
		cout << letter << " = " << array[i] << endl;
	}
}

void countWordsBasedOnLength(char* string, int*& array, int& size)
{
	int letterCount = 0;
	static int max = 0;
	int size1 = strlen(string);

	for (int i = 0; i < size1; i++)
	{
		letterCount = ExtractWord(string, i);

		//cout << "LC : " << letterCount << endl;

		for (int j = 0; j < size; j++)
		{
			if (letterCount == j)
			{
				array[j]++;

				if (max < j)
				{
					max = j;
				}

			}


		}


	}

	size = max;

	//	DisplayWordLength(array, size);


}

bool IsWordEnd(const char ch)
{
	return (ch == '\0' || ch == ' ' || ch == ',' || ch == ':' || ch == '.');

}

int ExtractWord(char* string, int& index)
{
	char* res = new char[10];
	int count = 0, j = 0;

	for (int i = 0; i < 10; i++)
		res[i] = '\0';



	while (IsWordEnd(string[index]))
	{
		index++;
	}


	while (!(IsWordEnd(string[index])))
	{
		res[count++] = string[index++];
	}

	return count;

}

char* ExtractWord2(char* string, int& index)
{
	char* res = new char[10];
	int count = 0, j = 0;

	for (int i = 0; i < 10; i++)
		res[i] = '\0';



	while (IsWordEnd(string[index]))
	{
		index++;
	}


	while (!(IsWordEnd(string[index])))
	{
		res[count++] = string[index++];
	}

	return res;

}

void DisplayWordLength(int* array, int index)
{
	cout << "\nWord Lenght Count : " << endl;

	for (int i = 1; i <= index; i++)
	{
		cout << i << " = " << array[i] << endl;
	}
}

void countingUniqueWords(char* string, char**& uwords, int*& array, int& size)
{
	int NumOfWords = 0, size1 = strlen(string), k;

	char* word = new char[20];

	cout << "\nEnter Number of Unique Words : ";
	cin >> NumOfWords;
	cin.ignore();

	uwords = new char* [NumOfWords];

	for (int i = 0; i < NumOfWords; i++)
	{
		uwords[i] = new char[20];
		cin.getline(uwords[i], 20);
	}


	for ( k = 0; k < NumOfWords; k++)
	{
		for (int j = 0; j < size1; j++)
		{
			word = ExtractWord2(string, j);
			//cout << "EX : " << word << endl;
			//cout << "UWord : " << uwords[i] << endl;
			if (compareWord(uwords[k], word))
			{
				array[k]++;
			}

		}
	}

	/*
	for (int i = k; i < size; i++)
	{
		array[i - 1] = 0;
	}
	*/


	size = NumOfWords;

}

bool compareWord(char* uwords, char* word)
{
	int size1 = strlen(uwords), size2 = strlen(word);

	if (size1 != size2)
		return false;

	for (int i = 0; i < size1; i++)
		if (uwords[i] != word[i])
			return false;

	return true;

}

void DisplayUwordCount(char** uwords, int* array, int size)
{
	cout << "\nUnique Word Count : " << endl;

	for (int i = 0; i < size; i++)
	{
		cout << uwords[i] << " = " << array[i] << endl;
	}
}

void initialize(int* array, int size)
{
	for (int i = 0; i < size; i++)
			array[i] = 0;
}
