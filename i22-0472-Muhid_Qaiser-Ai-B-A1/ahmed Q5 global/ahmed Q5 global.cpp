#include<iostream>
#include<string>
using namespace std;


char*** Files = nullptr;
char** FileNames = nullptr;
int* Lines = nullptr;
int total = 0;

void Initialize()
{
	total++;
	Files = new char** [total];
	FileNames = new char* [total];
	Lines = new int[total];
}
void ExpandAll()
{
	char** tempF = new char* [total + 1];
	for (int i = 0; i < total; i++)
		tempF[i] = Files[i];
	delete Files;
	Files = tempF;
	tempF = nullptr;

	char** tempFN = new char* [total + 1];
	for (int i = 0; i < total; i++)
		tempFN[i] = FileNames[i];
	delete FileNames;
	FileNames = tempFN;
	tempFN = nullptr;

	int* tempL = new int[total + 1];
	for (int i = 0; i < total; i++)
		tempL[i] = Lines[i];
	delete Lines;
	Lines = tempL;
	tempL = nullptr;
	total++;
}

void InputToFile(char** Files, int lines)
{
	cout << "Enter '~' to End File Editing" << endl
		<< "Enter Data to File: " << endl
		<< "-----------------------------------------------------------\n";
	for (int i = 0; i < lines; i++)
	{
		cin.getline(Files[i], 60);
		if (Files[i][0] == '~')
		{
			Files[i][0] = ' ';
			break;
		}
	}
	cout << "-----------------------------------------------------------\n"
		<< "File Closed" << endl;
}

bool CompareStr(char* str1, string str2)
{
	int i;
	for (i = 0; str1[i] != '\0' && str2[i] != '\0'; i++)
		if (str1[i] != str2[i])
			return false;

	return str1[i] == str2[i];
}

int createNewFile(string filename, int lines)
{
	for (int i = 0; i < total; i++)
		if (CompareStr(FileNames[i], filename))
		{
			cout << "Error: Unable to Create File" << endl
				<< "File named " << filename << " already exists" << endl;
			return -1;
		}

	cout << "Creating File...\n";
	int size, decision;
	ExpandAll();

	Lines[total - 1] = lines;
	Files[total - 1] = new char* [lines];
	for (int i = 0; i < lines; i++)
		Files[total - 1][i] = new char[60];

	for (size = 0; filename[size] != '\0'; size++);
	FileNames[total - 1] = new char[size + 1];
	for (int i = 0; i < size + 1; i++)
		FileNames[total - 1][i] = filename[i];

	cout << "File Created..." << endl;
	//cout << "1. Write Data to File" << endl
	//	<< "0. Close File" << endl;
	//cin >> decision;

	//if (decision) InputToFile(Files[total-1], lines);
	return 0;
}

void Display(char** File, int size)
{
	for (int i = 0; i < size; i++)
		cout << File[i] << endl;
	cout << endl;
}

void viewExistingFile(string filename)
{
	for (int index = 0; index < total; index++)
		if (CompareStr(FileNames[index], filename))
		{
			Display(Files[index], Lines[index]);
			return;
		}
	cout << "File Not Found" << endl;
}
void ShiftClear(char**& files, char& filenames, int& lines, int index)
{
	for (int i = 0; i < Lines[index]; i++)
		delete[] files[index][i];
	delete[] filenames[index];

	for (int i = index; i < total - 1; i++)
	{
		files[i] = files[i + 1];
		filenames[i] = filenames[i + 1];
		lines[i] = lines[i + 1];
	}
	total--;
}
int deleteExistingFile(string filename)
{
	for (int index = 0; index < total; index++)
		if (CompareStr(FileNames[index], filename))
		{
			ShiftClear(Files, FileNames, Lines, index);
			cout << "File Deleted Successfully" << endl;
			return 0;
		}
	cout << "File Not Found" << endl;
	return -1;
}
int copyExistingFile(string existingFileName, string newFileName)
{
	int ExisIndex = -1;
	for (int i = 0; i < total; i++)
	{
		if (CompareStr(FileNames[i], existingFileName))
		{
			ExisIndex = i;
			break;
		}
		if (CompareStr(FileNames[i], newFileName))
		{
			cout << "Error: Unable to Create File" << endl
				<< "File named " << newFileName << " already exists" << endl;
			return -1;
		}
	}

	if (ExisIndex == -1)
	{
		cout << "File Not Found" << endl;
		return -1;
	}

	int check = createNewFile(newFileName, Lines[ExisIndex]);
	for (int i = 0; i < Lines[ExisIndex]; i++)
		for (int j = 0; j < 60; j++)
			Files[total - 1][i][j] = Files[ExisIndex][i][j];

	if (check == 0)
		cout << "File Successfully Copied" << endl;
	return 0;
}
int editExistingFile(string fileName, int lineNumber, string newContent)
{
	for (int i = 0; i < total; i++)
		if (CompareStr(FileNames[i], fileName))
		{
			if (lineNumber > Lines[i])
			{
				cout << "Error : Unable To Edit File" << endl
					<< lineNumber << " exceedes lines in file" << endl;
				return -1;
			}
			int size;
			for (int j = 0; j < 60 && newContent[j] != '\0'; j++)
				Files[i][lineNumber][j] = newContent[j];
			return 0;
		}
	cout << "File Not Found" << endl;
	return -1;
}

void viewFileList()
{
	for (int i = 0; i < total; i++)
		cout << i + 1 << "  " << FileNames[i] << endl;
	cout << endl << endl;
}



void MainMenu()
{
	char decision;
	cout << "Welcome to File Management System" << endl
		<< "--------------------------------------" << endl
		<< "Select an Operation" << endl
		<< " 1. Create new File" << endl
		<< " 2. View Existing File" << endl
		<< " 3. Edit Existing File" << endl
		<< " 4. Copy an Existing File" << endl
		<< " 5. Delete an Existing File" << endl
		<< " 6. View List of All Files" << endl
		<< "Enter Decision : ";
	cin >> decision;

	switch (decision)
	{
	case 1:
		createNewFile();
		cout << "1. Write Data to File" << endl
		<< "0. Close File" << endl;
		cin >> decision;

		if (decision)
			InputToFile(Files[total - 1], Lines[total-1]);

		break;
	case 2 :
		viewExistingFile();
		break;
	case 3:
		editExistingFile();
		break;
	case 4:
		copyExistingFile();
		break;
	case 5:
		deleteExistingFile();
		break;
	case 6:
		viewFileList();
	default :
		cout << "Invalid Input" << endl;
		break;
	}
}

//createNewFile
//copyExistingFile
//viewFilesList
//deleteFile


int main()
{
	MainMenu();
//	createNewFile("File1", 10);
//	createNewFile("File2", 10);
//	createNewFile("File3", 10);
//	viewFileList();
//	copyExistingFile("File1", "File3");
	cout << "\n\n\n";
//	viewFileList();
	return 0;
}