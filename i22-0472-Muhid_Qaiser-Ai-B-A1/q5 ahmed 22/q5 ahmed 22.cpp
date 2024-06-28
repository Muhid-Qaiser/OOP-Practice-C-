#include <iostream>
#include <string>
#include<string.h>
using namespace std;


char*** Files = NULL;
char** FileNames = NULL;
int* Lines = NULL;
int total = 0;

void ExpandAll()
{
    char*** tempF = new char** [total + 1];
    
    for (int i = 0; i < total; i++)
        tempF[i] = Files[i];

    delete Files;
    
    Files = tempF;
    
    tempF = NULL;


    char** tempFN = new char* [total + 1];
   
    for (int i = 0; i < total; i++)
        tempFN[i] = FileNames[i];
    
    delete FileNames;
    
    FileNames = tempFN;
    
    tempFN = NULL;


    int* tempL = new int[total + 1];
    
    for (int i = 0; i < total; i++)
        tempL[i] = Lines[i];
    
    delete Lines;
    
    Lines = tempL;
    
    tempL = NULL;
    
    total++;
}

int Copy(char**& File, char* String, int& lineNo, int maxLines)
{
    int i, j;

    for (i = 0; i < 59 && String[i] != '\0'; i++)
        File[lineNo][i] = String[i];

    File[lineNo][i++] = '\0';

    if (i < 60) 
        return 0;

    else if (lineNo + 1 >= maxLines) 
        return -1;

    lineNo++;

    for (j = 0; String[i + j] != '\0'; j++)
        File[lineNo][j] = String[i + j];

    File[lineNo][j] = '\0';

    cout << lineNo + 1 << " : " << File[lineNo] << endl;

    return 0;
}

void InputToFile(char** Files, int lines)
{
    char* InputBuf = new char[100];

    cout << "Enter '~' to End File Editing" << endl
        << "Enter Data to File: " << endl
        << "---------------------------------------------------------------\n";

    for (int i = 0; i < lines; i++)
    {
        cout << i + 1 << " : ";
        cin.getline(InputBuf, 100);

        if (Copy(Files, InputBuf, i, Lines[i]) == -1)
            break;

        if (Files[i][0] == '~')
            break;
       
    }

    cout << "---------------------------------------------------------------\n"
        << "File Closed" << endl;
}

bool CompareStr(char* str1, string str2)
{
    int i;
    for (i = 0; str1[i] != '\0' && str2[i] != '\0'; i++)
        if (str1[i] != str2[i])
            return false;

    return true;
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

    return 0;
}

void Display(char** File, int size)
{
    for (int i = 0; i < size && File[i][0] != '~'; i++)
        cout << File[i] << endl;

    cout << endl;
}

void viewExistingFile(string filename)
{
    for (int index = 0; index < total; index++)
        if (CompareStr(FileNames[index], filename))
        {
            cout << "\n\n---------------------------------------------------------------\n";

            Display(Files[index], Lines[index]);

            cout << "---------------------------------------------------------------\n";

            return;
        }

    cout << "File Not Found" << endl;
}

void ShiftClear(char***& files, char**& filenames, int*& lines, int index)
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

            int j;

            for (j = 0; j < 59 && newContent[j] != '\0'; j++)
                Files[i][lineNumber][j] = newContent[j];

            Files[i][lineNumber][j] = '\0';

            return 0;
        }

    cout << "File Not Found" << endl;

    return -1;
}

int viewFileList()
{
    if (total == 0) return -1;
    for (int i = 0; i < total; i++)
        cout << i + 1 << " " << FileNames[i] << endl;

    cout << endl << endl;

    return 0;
}

void MainMenu()
{
    string InputStr, SecondaryStr;
    int decision, count;

    do {
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
        cin.ignore();

        if (decision != 6)
        {
            cout << "\n\nEnter File Name : ";
            getline(cin, InputStr);
        }
        else
            cout << "\n\n";


        switch (decision)
        {
        case 1:
            cout << "Enter the Number of Lines : ";
            cin >> count;

            createNewFile(InputStr, count);

            cout << "1. Write Data to File" << endl
                << "0. Close File" << endl;
            cin >> decision;
            cin.ignore();
            if (decision)
                InputToFile(Files[total - 1], Lines[total - 1]);

            break;
        case 2:
            viewExistingFile(InputStr);
            break;
        case 3:
            cout << "Enter Line Number : ";
            cin >> count;
            cin.ignore();
            cout << "Enter New Content : ";
            getline(cin, SecondaryStr);

            editExistingFile(InputStr, count - 1, SecondaryStr);
            break;
        case 4:
            cout << "Enter New File Name : ";
            getline(cin, SecondaryStr);
            copyExistingFile(InputStr, SecondaryStr);
            break;
        case 5:
            deleteExistingFile(InputStr);
            break;
        case 6:
            if (viewFileList() == -1)
                cout << "File System Empty" << endl;
            break;
        default:
            cout << "Invalid Input" << endl;
            break;
        }
        cout << "Enter 1/0 to Continue/Exit : ";
        cin >> decision;
        cout << "\n\n---------------------------------------------------------\n";
    } while (decision);
}

int main()
{
    MainMenu();
    return 0;
}