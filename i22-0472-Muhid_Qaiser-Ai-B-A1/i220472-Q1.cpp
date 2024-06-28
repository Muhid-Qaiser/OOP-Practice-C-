#include <iostream>
using namespace std;

bool verifyPassword(const char* password);

int main()
{
    int size;

    char password[20] = { '\0' };

    bool ans = 0;

    cout << "Password Must Have : " << endl
        << "1. Atleat 1 Capital letter " << endl
        << "2. Atleast 1 Small letter " << endl
        << "3. Atleast 1 Digit " << endl << endl
        << "Enter Password : ";
    cin >> password;

    for (size = 0; *(password + size) != '\0'; size++);

    while (size < 6)
    {
        cout << "\n\nPassword Too Short\n"
            << "Try Again With Atleast a 6 Character Long Password\n"
            << "Enter Password : ";
        cin >> password;

        for (size = 0; *(password + size) != '\0'; size++);

    }

    ans = verifyPassword(password);


    if (ans)
        cout << "\nPassword is Strong!\n\n";
    

    else
        cout << "\nPassword is Weak!\n\n";
    
    return 0;

}

bool verifyPassword(const char* password) { // checks for strenght of password
        

    int size = 0, Upper_case = 0, Lower_case = 0, digit = 0;

    for (size = 0; *(password + size) != '\0'; size++);

    // cout << size;

    for (int i = 0; i < size; i++)
    {
        if (*(password + i) >= '0' && *(password + i) <= '9')
        {
            digit++;
        }

        else  if (*(password + i) >= 'A' && *(password + i) <= 'Z')
        {
            Upper_case++;
        }

        else  if (*(password + i) >= 'a' && *(password + i) <= 'z')
        {
            Lower_case++;
        }

    }

    //    cout << "UL : " << Upper_case << "\nLc : " << Lower_case << "\ndig : " << digit << endl;

    if (Upper_case == 0)
        cout << "\nPassword contains No Upper Case Characters!\n";

    if (Lower_case == 0)
        cout << "\nPassword contains No Lower Case Characters!\n";

    if (digit == 0)
        cout << "\nPassword contains No Digits!\n";


    if (Upper_case > 0 && Lower_case > 0 && digit > 0)
        return true;

    else
        return false;


}

