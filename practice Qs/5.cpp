#include <iostream>
#include <cstring>
using namespace std;

class ChineseNum
{
    // static arrays to store the digit names from 0 to 10000.
    static char *positionNames[4];
    static char *digitNames[10];
    int num;        // Decimal number
    char **numName; // Chinese digits Names
    int length;     // Number of digits
public:
    ChineseNum();
    ChineseNum(int);
    ChineseNum(const ChineseNum &);
    ~ChineseNum();
    void encodeToChinese();
    void deallocateMemory();
    ChineseNum &operator=(const ChineseNum &);
    ChineseNum operator+(int);
    ChineseNum &operator++();
    ChineseNum operator+(ChineseNum &);
    friend ChineseNum operator+(int, ChineseNum &);
    friend ostream &operator<<(ostream &, const ChineseNum &);
};
char *ChineseNum::positionNames[4] = {"shih", "pai", "chien", "wan"};
char *ChineseNum::digitNames[10] = {"ling", "yi", "erh", "san", "ssu", "wu", "liu", "chi", "pa",
                                    "chiu"};
ChineseNum::ChineseNum()
{
    num = 0;
    encodeToChinese();
}
ChineseNum::ChineseNum(int num)
{
    this->num = num;
    encodeToChinese();
}
ChineseNum::ChineseNum(const ChineseNum &n)
{
    this->num = n.num;
    encodeToChinese();
}
ChineseNum::~ChineseNum()
{

    deallocateMemory();
}
void ChineseNum::deallocateMemory()
{
    for (int i = 0; i < length; i++) // deallocate whole memory
        delete[] numName[i];
    delete[] numName;
}
// ChineseNum &ChineseNum::operator=(ChineseNum &n)
// {
//     if (this != &n)
//     {
//         deallocateMemory();
//         this->num = n.num;
//         encodeToChinese();
//     }
//     return *this;
// }
ChineseNum &ChineseNum::operator=(const ChineseNum &n)
{
    if (this != &n)
    {
        deallocateMemory();
        this->num = n.num;
        encodeToChinese();
    }
    return *this;
}
ChineseNum ChineseNum::operator+(int n)
{
    ChineseNum r(this->num + n);
    r.encodeToChinese();
    return r;
}
ChineseNum ChineseNum::operator+(ChineseNum &n)
{
    ChineseNum r(this->num + n.num);
    r.encodeToChinese();
    return r;
}
ChineseNum &ChineseNum::operator++()
{
    num++;
    deallocateMemory();
    encodeToChinese();
    return *this;
}
ChineseNum operator+(int v, ChineseNum &n)
{
    return n + v;
}
ostream &operator<<(ostream &out, const ChineseNum &n)
{
    out << "Number is: " << n.num << " ";
    if (n.length == 1)
    {
        out << n.numName[0] << " ";
    }
    else
    {
        for (int i = 0; i < n.length; i++)
        {
            bool flag = false;
            // Rule No 1 do not add "shih", "pai", "chien","wan" corresponding to zeros
            if (i > 1 && strcmp(n.numName[i - 1], "ling") == 0)
            {
                for (int j = 0; j < 4; j++)
                {
                    if (strcmp(n.numName[i], n.positionNames[j]) == 0)
                        flag = true;
                }
            }
            // Rule No 2 Add single zero if there are consecutive zeros
            // Rule No 3 Exclude all trailing zeros
            else if (strcmp(n.numName[i], "ling") == 0)
            {

                if (i + 2 < n.length && strcmp(n.numName[i + 2], "ling") == 0 ||

                    i == n.length - 1)

                    flag = true;
            }
            if (!flag)
                out << n.numName[i] << " ";
        }
    }
    out << endl;
    return out;
}
void ChineseNum::encodeToChinese()
{
    if (num < 10)
    {
        length = 1;
        numName = new char *[length];
        numName[0] = new char[strlen(digitNames[num]) + 1];
        strcpy(numName[0], digitNames[num]);
    }
    else
    {
        int dcount = 0, n = num, d = 0;
        int digits[5] = {0};
        while (n)
        {
            digits[dcount++] = n % 10;
            n /= 10;
        }
        length = dcount + dcount - 1;
        numName = new char *[length];
        for (int i = 0, j = dcount - 1; i < length; i++, j--)
        {
            numName[i] = new char[strlen(digitNames[digits[j]]) + 1];
            strcpy(numName[i], digitNames[digits[j]]);
            i++;
            if (i < length)
            {
                numName[i] = new char[strlen(positionNames[j - 1]) + 1];
                strcpy(numName[i], positionNames[j - 1]);
            }
        }
    }
}

int main()
{
    ChineseNum n1(45);
    // Set decimal Number 45, and encodes
    ChineseNum n2; // by default the decimal value of a number is 0
    ChineseNum n4(90600);
    ChineseNum n3 = n1 + (++n2) + 5000;
    n1 = n3 + n2; // Sum the numbers and returns update number with Name
    cout << n1 << n2 << 30 + n3 << n4 << endl;

    // Prints the complete Number according to THE THREE RULES
    // Note: Rules are implemented only while printing, the original encoding saved in numName does not change,
    // you can use built in CString functions
}