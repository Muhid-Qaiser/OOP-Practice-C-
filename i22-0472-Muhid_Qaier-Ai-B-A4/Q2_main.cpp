#include <iostream>
// #include <string> // Only Used for Input Of string. (Built in string).
using namespace std;

// ? for Project files / VS
// #include "Q2.h"

// ? For VS Code
#include "Q2_fun.cpp"

int main()
{
     cout << "\n\nString Definition Sytem" << endl
          << "===================================\n\n";

     int Index_choice = 0;
     char letter = '\0', temp_index = '\0';

     // * assigning value in char*
     char *ch = new char[100];
     cout << "Enter String ch : ";
     cin.get(ch, 100);
     // ch = "joe a mom";

     char *ch2 = new char[100];
     cout << "\nEnter SubStr char* ch2 : ";
     cin.ignore();
     cin.get(ch2, 100);
     //  ch2 = "a mo";

     String s1(ch);
     String s2(s1);
     String s6(ch2);

     cout << "\ns1(ch) : " << s1 << endl;
     cout << "s2(s1) : " << s2 << endl;

     // * Adding 2 Strings
     String s3;

     s3 = (s1 + s2);
     cout << "\ns3 = (s1+s2) : " << s3 << endl;

     // * Adding char pointer to String
     String s5;

     s5 = s1 + ch;
     cout << "\ns5 = (s1+ch) : " << s5 << endl;

     // * Subtracting 2 Strings
     String s7;

     s7 = s1 - s6;
     cout << "\ns6(ch2) \n\n\ns7 = (s1-s6) : " << s7 << endl;

     // * Taking string input
     string s;

     cout << "\nEnter SubStr string s (one word) : ";

     // ? Method 1 : With string library
     // cin.ignore();
     // getline(cin, s);

     // ? Method 2 : With cin
     cin >> s;

     // ? Method 3 : Hardcode
     //   s = "a mo";

     // * Subtracting a String and a string
     String s8;

     s8 = s1 - s;
     cout << "\n\ns8 = s1-s : " << s8 << endl;

     // * Adding a Symbol to a String
     String s4;

     cout << "\nEnter Symbol : ";
     cin >> letter;

     s4 = s1 + letter;
     cout << "\ns4 = s1 + \'" << letter << "\' : " << s4 << endl;

     // * Finding element at index
     cout << "\nEnter Index : ";

     // ? Method 1 : Using char and int
     // cin >> temp_index;
     // while ((temp_index - 48) > s1.length() - 1)
     // {
     //      cout << "\nInvalid Index!!" << endl
     //           << "\nEnter Index from 0-" << s1.length() - 1 << " : ";
     //      cin >> temp_index;
     // }
     // Index_choice = (temp_index - 48);

     // ? Method 2 : With int only
     cin >> Index_choice;
     while (Index_choice > s1.length() - 1)
     {
          cout << "\nInvalid Index!!" << endl
               << "\nEnter Index from 0-" << s1.length() - 1 << " : ";
          cin >> Index_choice;
     }

     cout << "\ns1[" << Index_choice << "] : " << s1[Index_choice] << endl
          << endl;

     // * Checking to see if String is empty
     char *empty = new char;
     empty[0] = '\0';
     String s9(empty);

     cout << "\ns9(NULL) : ";
     (!s9) ? cout << "Empty!\n" : cout << "Not Empty!\n";

     // * Taking input of char* ch1
     char *ch1 = new char[100];

     cout << "\n\nEnter char* ch1 : ";

     // ? Method 1 : With cin.get()
     cin.ignore();
     cin.get(ch1, 100);

     // ? Method 2 : With cin
     // cin >> ch1;

     // * assigning char* ch1 to String
     String s10;

     s10 = ch1;
     cout << "\ns10 = ch1 : " << s10 << endl;

     // * assigning string to String
     string str2;
     String s11;

     // ? Method 1 : input using cin
     cout << "\nEnter string str2 (one word) : ";
     cin >> str2;

     // ? Method 2 : HardCode
     // str2 = "1234567";

     s11 = str2;
     cout << "\nstr2 = " << str2 << "\n\ns11 = str2 : " << s11 << endl;

     // * Getting Length of String
     cout << "\nlenght of s11 : " << s11.length() << endl
          << endl;

     // * Multiplying String with mult
     String s12;
     int mult = 0;

     cout << "\nEnter Multiplier : ";
     cin.ignore();
     cin >> mult;
     s12 = s1 * mult;
     cout << "\ns12 = s1*" << mult << " : " << s12 << endl;

     // * Find index of char
     char ch3;

     cout << "\nEnter char ch3 to Find it's index in s1 : ";
     cin >> ch3;

     cout << "\nIndex of char \'" << ch3 << "\' in - " << s1 << ": " << s1(ch3) << endl;

     // * Find index of string
     string str3;

     cout << "\n\nEnter string str3 to Find it's index in s1 : ";
     cin >> str3;

     cout << "\nIndex of string \'" << str3 << "\' in - " << s1 << ": " << s1(str3) << endl;

     // * Find index of char *
     char *ch4 = new char;

     cout << "\n\nEnter char* ch4 to Find it's index in s1 : ";
     cin >> ch4;

     cout << "\nIndex of char* \'" << ch4 << "\' in - " << s1 << ": " << s1(ch4) << endl;

     // * Find index of String
     String s13(ch4);

     cout << "\n\nIndex of String - " << s13 << "in - " << s1 << ": " << s1(s13) << endl;

     cout << "\n\nProgram Ending..." << endl;
     cout << "\n================================\n\n\n";

     return 0;
}
