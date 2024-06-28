#include <iostream>
#include <cstring>
using namespace std;

class joe
{
    char *arr;
    int size;
    char *word;
    char *uword;

public:
    joe(char *a, int s) : arr(a), size(s) {}

    void print()
    {
        cout << arr << endl;
    }

    char *ExtractWord(int &index)
    {
        char ch;
        int count = 0;

        for (int i = index; i < size; i++)
        {
            ch = arr[i];

            if (ch == ' ' || ch == '\0' || ch == '.')
            {
                index += strlen(word);
                return word;
            }
            else
            {
                word[count++] = ch;
                word[count] = '\0';
            }
        }
        index += strlen(word);
        return word;
    }

    bool isword(char ch)
    {
        return (ch == ' ' || ch == '\0' || ch == '.' || ch == ',');
    }

    char *Extractword(int &index)
    {
        char *res;
        int count = 0;

        while (isword(arr[index++]))
            ;
        index--;

        while (!isword(arr[index]))
        {
            word[count++] = arr[index++];
        }
        word[count] = '\0';
        // cout << word << endl;
        return word;
    }

    void rightShift(int index)
    {
        char *temp = new char[strlen(arr) + 2];

        for (int i = 0; i < size; i++)
        {
            temp[i] = arr[i];
        }
        cout << temp << endl;
        cout << size << endl;
        cout << strlen(arr) << endl;

        for (int i = size - 1; i > index; i++)
        {
            temp[i] = temp[i - 1];
        }
        cout << temp << endl;
    }

    void fun()
    {
        for (int i = 0; i < size; i++)
        {
            word = Extractword(i);

            if (arr[i] == ',')
            {
                for (int j = 0; j < size; j++)
                {
                    uword = Extractword(i);
                    if (uword == word)
                    {
                        j += strlen(uword);

                        cout << j << endl;
                        cout << "in\n";
                        rightShift(j);
                        arr[j] = ',';
                        cout << arr << endl;
                    }
                }
            }
        }
    }
};

int main()
{
    // string str = "joe, mama. ligma";
    // char *s;
    // for (int i = 0; i < str[i] != '\0'; i++)
    // {
    //     s[i] = str[i];
    // }
    // int size = strlen(s);
    // joe j(s, size);

    joe j("joe, mama. ligma", 16);
    j.fun();

    return 0;
}