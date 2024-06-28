#include <iostream>
#include <string>
using namespace std;

// ! Classes and functions

class String
{
    char *data;
    int length;

public:
    String()
    {
        data = NULL;
        length = 0;
    }

    String(int size)
    {
        length = size;
        data = new char[size];
    }

    String(char *str)
    {
        int size = 0;

        while (str[size++] != '\0')
        {
        }
        size--;
        data = new char[size];

        for (int i = 0; i < size; i++)
        {
            data[i] = str[i];
        }

        data[size] = '\0';
        length = size;
    }

    String(const String &str)
    {
        int size = 0;

        data = str.data;

        while (data[size++] != '\0')
        {
        }

        size--;

        length = size;
        // cout << length << endl;
    }

    ~String() {}

    char *getData()
    {
        return data;
    }

    int strLenght()
    {
        return length;
    }

    void clear()
    {
        delete[] data;
        data = NULL;
        length = 0;
    }

    bool empty()
    {
        if (data == NULL || data[0] == '\0' || data == "\0" || data == "")
        {
            return true;
        }

        return false;
    }

    int charAt(char c)
    {
        for (int i = 0; data[i] != '\0'; i++)
        {
            if (data[i] == c)
                return i;
        }
        return -1;
    }

    bool equals(char *str)
    {
        for (int i = 0; str[i] != '\0'; i++)
            if (str[i] != data[i])
                return false;
        return true;
    }

    bool equalsIgnoreCase(char *str)
    {
        for (int i = 0; str[i] != '\0'; i++)
            if (str[i] != data[i] && str[i] + 32 != (data[i]))
                return false;
        return true;
    }

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
        {
            return isSubstr(str1 + 1, str2 + 1); // str1 and str2 are same, Move Foward together to check the Next character
        }

        return isSubstr(str1 + 1, str2); // str1 and str2 are Not same, Move str1 Foward together to check if the next character of st1 is Same as str2
    }

    char *substring(char *substr, int startIndex)
    {
        int size = 0, count = 0, index = 0, res = 0;
        int cond = 0;

        // cout << "in\n";

        while (substr[size++] != '\0')
        {
        }
        size--;

        char *ans = new char[size];
        char *checker = new char[size];
        checker[0] = '\0';

        for (int i = startIndex; data[i] != '\0'; i++)
        {
            if (data[i] != 32 || cond == 1)
            {
                cout << "cond : " << cond << "  " << data[i] << endl;
                checker[count++] = data[i];
                checker[count] = '\0';
                cout << substr[count - 1] << "  " << data[i] << endl;
            }

            else
            {
                checker[count] = '\0';
                if (isSubstr(checker, substr))
                {
                    index = i - size;
                    cond = 1;
                    checker[count++] = 32;
                    //   cout << "innn\n";
                }
                else
                    count = 0;
            }
        }

        // cout << "checker : " << checker << endl;
        count = 0;
        cond = 0;

        for (int i = 0; i < checker[i] != '\0'; i++)
        {
            if (checker[i] == substr[count] || cond == 1)
            {
                // cout << substr[count] << " " << checker[i] << endl;
                ans[count] = checker[i];
                count++;
                cond = 1;
                ans[count] = '\0';
            }
        }
        // cout << "checker : " << ans << endl;

        switch (cond)
        {
        case 1:
            return ans;
        case 0:
            return NULL;
        default:
            return NULL;
        }
        //  return NULL;
    }

    char *substring(char *substr, int startIndex, int endIndex)
    {
        int size = 0, count = 0, index = 0, res = 0;
        int cond = 0;

        // cout << "in\n";

        while (substr[size++] != '\0')
        {
        }
        size--;

        char *ans = new char[size];
        char *checker = new char[size];
        checker[0] = '\0';

        for (int i = startIndex; i <= endIndex; i++)
        {
            if (data[i] != 32 || cond == 1)
            {
                // cout << "cond : " << cond << "  " << data[i] << endl;
                checker[count++] = data[i];
                checker[count] = '\0';
                // cout << substr[count - 1] << "  " << data[i] << endl;
            }

            else
            {
                checker[count] = '\0';
                if (isSubstr(checker, substr))
                {
                    index = i - size;
                    cond = 1;
                    checker[count++] = 32;
                    //   cout << "innn\n";
                }
                else
                    count = 0;
            }
        }

        // cout << "checker : " << checker << endl;
        count = 0;
        cond = 0;

        for (int i = 0; i < checker[i] != '\0'; i++)
        {
            if (checker[i] == substr[count] || cond == 1)
            {
                // cout << substr[count] << " " << checker[i] << endl;
                ans[count] = checker[i];
                count++;
                cond = 1;
                ans[count] = '\0';
            }
        }
        // cout << "checker : " << ans << endl;

        switch (cond)
        {
        case 1:
            return ans;
        case 0:
            return NULL;
        default:
            return NULL;
        }
        return NULL;
    }

    void print()
    {
        if (length == 0)
            cout << '\0';
        else
            cout << data << endl;
    }
};

void Menu(char *ch1, char *ch2, char *ch3)
{
    String s1(ch1);
    String s2(s1), s3(ch2);

    int choice = 0, choice1 = 0, choice2 = 0;
    char ch;

    do
    {

        cout << "\n\nChoose Function"
             << "\n1.  strLength()"
             << "\n2.  clear()"
             << "\n3.  empty()"
             << "\n4.  charAt(char c)"
             << "\n5.  getData()"
             << "\n6.  equals(char *str)"
             << "\n7.  equalsIgnoreCase(char *str)"
             << "\n8.  substring(char *str, int startIndex)"
             << "\n9.  substring(char *str, int startIndex, int endIndex)"
             << "\n10. print()"
             << "\n0. Exit"
             << endl
             << "\nEnter : ";
        cin >> choice1;

        cout << "-------------------------------------------" << endl;

        switch (choice1)
        {
        case 1:
            cout << "\nUsing strLength() on s1 : " << s1.strLenght() << endl;
            break;
        case 2:
            cout << "\nEnter string do you want to clear "
                 << "\n1. string"
                 << "\n2. substring1"
                 << "\n3. substring2"
                 << endl;
            cin >> choice;

            switch (choice)
            {
            case 1:
                s1.clear();
                break;
            case 2:
                s2.clear();
                break;
            case 3:
                s3.clear();
                break;
            default:
                cout << "\nError: Invalid Input" << endl;
            }

            cout << "\nUsing Clear() on s" << choice << " : " << endl;

            break;
        case 3:
            cout << "\nEnter string do you want to check if empty "
                 << "\n1. string"
                 << "\n2. substring1"
                 << "\n3. substring2"
                 << endl;
            cin >> choice;

            switch (choice)
            {
            case 1:
                (s1.empty()) ? cout << "\nstring is Empty" << endl : cout << "\nstring is Filled" << endl;
                break;
            case 2:
                (s2.empty()) ? cout << "\nsubstring1 is Empty" << endl : cout << "\nsubstring1 is Filled" << endl;
                break;
            case 3:
                (s3.empty()) ? cout << "\nsubstring2 is Empty" << endl : cout << "\nsubstring2 is Filled" << endl;
                break;
            default:
                cout << "\nError: Invalid Input" << endl;
            }

            break;
        case 4:
            cout << "\nEnter the Character you want to find : ";
            cin >> ch;
            cout << "\nUsing charAt() : " << endl
                 << endl
                 << "character appears at " << s1.charAt(ch) << " index." << endl;
            break;
        case 5:
            cout << "\nEnter string you want to get data of "
                 << "\n1. string"
                 << "\n2. substring1"
                 << "\n3. substring2"
                 << endl;
            cin >> choice;

            switch (choice)
            {
            case 1:
                cout << "\nUsing getData() : " << endl
                     << s1.getData() << endl;

                break;
            case 2:
                cout << "\nUsing getData() : " << endl
                     << s2.getData() << endl;

                break;
            case 3:
                cout << "\nUsing getData() : " << endl
                     << s3.getData() << endl;

                break;
            default:
                cout << "\nError: Invalid Input" << endl;
            }
            break;
        case 6:
            cout << "\nUsing equals() with string and substring " << endl;

            (s1.equals(ch2)) ? cout << "Equal\n" : cout << "Not Equal\n";
            break;
        case 7:
            cout << "\nUsing equalsIgnoreCase()" << endl;

            (s1.equalsIgnoreCase(ch2)) ? cout << "Equal\n" : cout << "Not Equal\n";
            break;
        case 8:
            cout << "\nEnter Starting Index : ";
            cin >> choice;

            cout << "\nUsing subStr()" << endl
                 << "String : " << s1.getData() << endl
                 << "SubString : " << ch2 << endl
                 << "Starting Index " << choice << " : " << endl;

            if (s1.substring(ch2, choice) == NULL)
                cout << "Not Found!" << endl;

            else
                cout << s1.substring(ch2, choice) << endl;

            break;
        case 9:
            cout << "\nEnter Starting Index : ";
            cin >> choice;
            cout << "\nEnter Ending Index : ";
            cin >> choice2;

            cout << "\nUsing subString() with Ending Index" << endl
                 << "String : " << s1.getData() << endl
                 << "SubString : " << ch2 << endl
                 << "Starting Index " << choice << " : " << endl
                 << "Ending Index " << choice2 << " : " << endl;

            if (s1.substring(ch2, choice, choice2) == NULL)
                cout << "Not Found!" << endl;
            else
                cout << s1.substring(ch2, choice, choice2) << endl;
            break;
        case 10:
            cout << "\nUsing print()" << endl;
            cout << "\nEnter string you want to get data of "
                 << "\n1. string"
                 << "\n2. substring1"
                 << "\n3. substring2"
                 << endl;
            cin >> choice;

            cout << "\nDisplay : \n";

            switch (choice)
            {
            case 1:
                s1.print();

                break;
            case 2:
                s2.print();

                break;
            case 3:
                s3.print();

                break;
            default:
                cout << "\nError: Invalid Input" << endl;
            }
            break;
        case 0:
            cout << "\nExiting..." << endl;
            break;
        default:
            cout << "\nError: Invalid Input" << endl;
        }
    } while (choice1);
}

void Start()
{
    int size1 = 0, size2 = 0;
    string str1, str2;
    char *ch1 = NULL, *ch2 = NULL, *ch3 = NULL;

    cout << "\nEnter A String : ";
    getline(cin, str1);

    cout << "\nEnter A SubString : ";
    getline(cin, str2);

    while (str1[size1++] != '\0')
    {
    }
    size1--;
    while (str1[size2++] != '\0')
    {
    }
    size2--;

    ch1 = new char[size1];
    ch2 = new char[size2];

    for (int i = 0; i < size1; i++)
        ch1[i] = str1[i];

    for (int i = 0; i < size2; i++)
        ch2[i] = str2[i];

    ch1[size1] = '\0';
    ch2[size2] = '\0';
    ch3 = new char[100];

    Menu(ch1, ch2, ch3);
}

int main()
{
    cout << "\nString Manipulating System" << endl
         << "================================================" << endl;
    Start();

    //? checking option 2
    /*
    char *joe = "lIgma balls";
    char *toe = "mr";
    char *checker = new char[100];

    String s1(joe);
    String s2(s1);
    String s3(toe);

    cout << "\nUsing strLength() : " << s1.strLenght() << endl;

    cout << "\nUsing Clear() : " << endl;

    s3.clear();

    (s3.empty()) ? cout << "Empty" << endl : cout << "Filled" << endl;

    cout << "\nUsing charAt() : " << endl
         << "character appears at " << s1.charAt('g') << " index." << endl;

    cout << "\nUsing getData() : " << endl
         << s1.getData() << endl;

    cout << "\nUsing equals()" << endl;

    (s1.equals(toe)) ? cout << "Equal\n" : cout << "Not Equal\n";

    cout << "\nUsing equalsIgnoreCase()" << endl;

    (s1.equalsIgnoreCase(joe)) ? cout << "Equal\n" : cout << "Not Equal\n";

    cout << "\nUsing subStr()" << endl
         << "String : " << s1.getData() << endl
         << "SubString : " << toe << endl
         << "Starting Index : 0" << endl;

    if (s1.substring(toe, 0) == NULL)
    {
        cout << "Not Found" << endl;
    }
    else
        cout << s1.substring(toe, 0) << endl;

    // cin.ignore();

    cout << "\nUsing subString() with Ending Index" << endl
         << "String : " << s1.getData() << endl
         << "SubString : " << toe << endl
         << "Starting Index : 0" << endl
         << "Ending Index : 7" << endl;

    if (s1.substring(toe, 0, 10) == NULL)
        cout << "Not Found" << endl;
    else
        cout << s1.substring(toe, 0, 10) << endl;

    cout << "\nUsing print()" << endl;
    s1.print();

    cout << endl;
*/
    cout << "\nProgram Existed."
         << "\n\n================================================" << endl
         << endl;
    return 0;
}