#include <iostream>
#include<string.h>
using namespace std;

// Function prototypes
int Strlen(char* s1);

char* Strcpy(char* s1, const char* s2);

char* Strncpy(char* s1, const char* s2, size_t n);

void initialize(char* arr, int size);

char* StrCat(char* s1, const char* s2);

char* StrnCat(char* s1, const char* s2, size_t n);

int StrCmp(const char* s1, const char* s2);

int StrnCmp(const char* s1, const char* s2, size_t n);

char** StrTok(char* s1, const char s2);

int StrFind(char* s1, char* s2);

bool check(char* word, char* s2);

char* SubStr(char* s1, int pos, int len);

int main()
{
    // data type initializing
    int size1 = 0, size2 = 0, n = 0, choice = 0, res_int = 0, pos = 0, len = 0, size = 0;

    char character = '\0';

    cout << "Press 1. int Strlen( char *s1 )" << endl
        << "Press 2. char *Strcpy( char *s1, const char *s2 )" << endl
        << "Press 3. char *Strncpy( char *s1, const char *s2, size_t n )" << endl
        << "Press 4. char *Strcat( char *s1, const char *s2 )" << endl
        << "Press 5. char *Strncpy( char *s1, const char *s2, size_t n )" << endl
        << "Press 6. char int StrnCmp( const char *s1, const char *s2 )" << endl
        << "Press 7. char int StrnCmp( const char *s1, const char *s2, size_t n )" << endl
        << "Press 8. char **StrTok( char *s1, const char s2)" << endl
        << "Press 9. int StrFind( char *s1, char *s2 )" << endl
        << "Press 10. char * SubStr ( char *, int pos, int len )" << endl << endl
        << "Enter Choice : ";

    cin >> choice;


    cout << "\nEnter size 1 for S1 : ";
    cin >> size1;
    cin.ignore();

    cout << "Enter size 2 for S2 : ";
    cin >> size2;
    cin.ignore();


    //size1 = 100, size2 = 100;


    char* result = new char[size2], * s1 = new char[size1], * s2 = new char[size2];

    char** Res_2D = new char* [50];

    //initializing Res_2D
    for (int j = 0; j < 50; j++)
    {
        Res_2D[j] = new char[100];
    }

    //clearing Res_2D
    for (int i = 0; i < 50; i++)
    {
        for (int j = 0; j < 100; j++)
            Res_2D[i][j] = '\0';
    }


    //clearing s1 and s2
    initialize(s1, size1);
    initialize(s2, size2);

    //Function callings
    switch (choice)
    {

    case 1: {

        cout << "\nEnter S1 :";
        cin.getline(s1, size1);

        cout << "\nSize of S1 : " << Strlen(s1) << endl;;

    } break;

    case 2: {

        cout << "\nEnter S1 :";
        cin.getline(s1, size1);

        cout << "Enter S2 :";
        cin.getline(s2, size2);

        // strcpy1 = Strcpy(s1, s2);
        result = Strcpy(s1, s2);

        cout << "\nStrcpy : " << result << endl;


    } break;

    case 3: {

        cout << "\nEnter S1 :";
        cin.getline(s1, size1);

        cout << "Enter S2 :";
        cin.getline(s2, size2);

        cout << "Enter n : ";
        cin >> n;
        cin.ignore();

        // strcpy2 = Strncpy(s1, s2, n);
        result = Strncpy(s1, s2, n);

        cout << "\nStrncpy : " << result << endl;

    } break;

    case 4: {

        cout << "\nEnter S1 :";
        cin.getline(s1, size1);

        cout << "Enter S2 :";
        cin.getline(s2, size2);

        result = StrCat(s1, s2);

        cout << "StrCat : " << result << endl;

    } break;

    case 5: {

        cout << "\nEnter S1 :";
        cin.getline(s1, size1);

        cout << "Enter S2 :";
        cin.getline(s2, size2);

        cout << "Enter n : ";
        cin >> n;
        cin.ignore();

        result = StrnCat(s1, s2, n);

        cout << "StrnCat : " << result << endl;

    } break;

    case 6: {

        cout << "\nEnter S1 :";
        cin.getline(s1, size1);

        cout << "Enter S2 :";
        cin.getline(s2, size2);

        res_int = StrCmp(s1, s2);

        cout << "\nStrCmp : " << res_int << endl;

    } break;

    case 7: {

        cout << "\nEnter S1 :";
        cin.getline(s1, size1);

        cout << "Enter S2 :";
        cin.getline(s2, size2);

        cout << "Enter n :";
        cin >> n;

        res_int = StrnCmp(s1, s2, n);

        cout << "\nStrnCmp : " << res_int << endl;

    } break;

    case 8: {

        cout << "Enter Delimiter : ";
        cin.get(character);
        cin.ignore();

        cout << "\nEnter S1 :";
        cin.getline(s1, size1);

        Res_2D = StrTok(s1, character);

        cout << "\nStrTok : " << endl;

        for (int i = 0; Res_2D[i] != NULL; i++)
            cout << Res_2D[i] << endl;


    } break;

    case 9: {

        cout << "\nEnter S1 :";
        cin.getline(s1, size1);

        cout << "Enter S2 :";
        cin.getline(s2, size2);

        res_int = StrFind(s1, s2);

        cout << "\nStrFind : " << res_int << endl;

    } break;

    case 10: {

        cout << "\nEnter S1 :";
        cin.getline(s1, size1);

        cout << "Enter Pos : ";
        cin >> pos;

        cout << "Enter Len : ";
        cin >> len;

        size = strlen(s1);

        if (size < pos)
            cout << "\nterminate called after throwing an instance of 'std::out_of_range'" << endl
            << "what() : basic_string::substr : __pos(which is " << pos << ") > this->size() (which is " << size << ")" << endl << endl;

        else
        {

            result = SubStr(s1, pos, len);

            cout << "\nSubStr : " << result << endl;

        }


    } break;

    default: cout << "\nInvalid Input!" << endl;  break;

    }



    return 0;

}

//function Definition
void initialize(char* arr, int size)
{
    for (int i = 0; i < size; i++)
        arr[i] = '\0';
}

int Strlen(char* s1)
{
    cout << s1 << endl;
    int size = 0;

    while (s1[size] != '\0')
    {
        size++;
    }

    return size;
}

char* Strcpy(char* s1, const char* s2)
{
    int size1 = 0, size2 = 0, size = 0;

    size1 = strlen(s1);
    size2 = strlen(s2);

    size = (size1 < size2) ? size2 : size1;


    for (int i = 0; i < size; i++)
    {
        s1[i] = s2[i];
    }

    return s1;
}

char* Strncpy(char* s1, const char* s2, size_t n)
{

    for (int i = 0; i < n; i++)
    {
        s1[i] = s2[i];
    }

    return s1;
}

char* StrCat(char* s1, const char* s2)
{

    int size1 = 0, size2 = 0, count = 0;

    size1 = strlen(s1);
    size2 = strlen(s2);

    for (int i = size1; i < size1 + size2; i++)
    {
        s1[i] = s2[count++];
    }

    return s1;
}

char* StrnCat(char* s1, const char* s2, size_t n)
{
    int size1 = 0, count = 0;

    size1 = strlen(s1);
    // size2 = strlen(s2);

    for (int i = size1; i < size1 + n; i++)
    {
        s1[i] = s2[count++];
    }

    return s1;
}

int StrCmp(const char* s1, const char* s2)
{
    int size1 = 0, size2 = 0, size = 0;

    size1 = strlen(s1);
    size2 = strlen(s2);

    (size1 < size2) ? size = size2 : size = size1;

    for (int i = 0; i < size; i++)
    {
        if (s1[i] < s2[i])
            return -1;
        else if (s1[i] > s2[i])
            return 1;
    }

    return 0;
}

int StrnCmp(const char* s1, const char* s2, size_t n)
{
    for (int i = 0; i < n; i++)
    {
        if (s1[i] < s2[i])
            return -1;
        else if (s1[i] > s2[i])
            return 1;
    }

    return 0;
}

char** StrTok(char* s1, const char s2)
{
    char** ans;
    int totalTokens = 0, currSize = 0, currTok = 0, i;

    for (int i = 0; s1[i] != '\0'; i++)
        if (s1[i] == s2)
            totalTokens++;

    totalTokens += 2;

    currTok = 0;

    ans = new char* [totalTokens];

    for (i = 0; s1[i] != '\0'; i++)
    {
        if (s1[i] == s2)
        {
            ans[currTok] = new char[currSize + 1];

            for (int j = 0; j < currSize; j++)
                ans[currTok][j] = s1[i - currSize + j];

            ans[currTok][currSize] = '\0';
            currSize = 0;
            currTok++;
        }

        else
            currSize++;
    }


    ans[currTok] = new char[currSize + 1];

    for (int j = 0; j < currSize; j++)
        ans[currTok][j] = s1[i - currSize + j];

    ans[currTok][currSize] = '\0';
    ans[currTok + 1] = NULL;

    return ans;
}

int StrFind(char* s1, char* s2)
{
    char* word = new char[50];
    int i = 0, count = 0, res = 0, size = 0;

    //initialize(word, 50);

    size = strlen(s1);

    s1[size] = ' ';

    while (s1[i] != '\0')
    {

        if (s1[i] != 32)
        {
            word[count++] = s1[i];
        }

        else
        {

            word[count] = '\0';

            if (check(word, s2))
            {
                return res;
            }

            res = i + 1;
            count = 0;

        }

        i++;

    }

    return -1;
}

bool check(char* word, char* s2)
{
    int size1 = 0, size2 = 0;

    size1 = strlen(word);
    size2 = strlen(s2);

    if (size1 != size2)
        return false;

    for (int i = 0; i < size1; i++)
        if (word[i] != s2[i])
            return false;

    return true;

}

char* SubStr(char* s1, int pos, int len)
{
    int count = 0;

    char* ans = new char[50];

    for (int i = pos; i <= len; i++)
    {
        ans[count++] = s1[i];
    }

    ans[count] = '\0';


    return ans;
}
