#include <iostream>
using namespace std;

void fun(int arr[][4], int row, int col)
{
    int temp = arr[0][0];

    // left shift top row
    for (int i = 0; i < col - 1; i++)
    {
        arr[0][i] = arr[0][i + 1];
    }

    // right col shift up
    for (int i = 0; i < row - 1; i++)
    {
        arr[i][row - 1] = arr[i + 1][row - 1];
    }

    // right shift bottom row
    for (int i = col - 1; i > 0; i--)
    {
        arr[row - 1][i] = arr[row - 1][i - 1];
    }

    // left col shift down
    for (int i = row - 1; i > 0; i--)
    {
        arr[i][0] = arr[i - 1][0];
    }

    arr[1][0] = temp;
}

int main()
{
    int arr[4][4];
    int count = 0;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            arr[i][j] = count++;
        }
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr[i][j] << "  ";
        }
        cout << endl;
    }

    fun(arr, 4, 4);
    cout << endl
         << endl;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr[i][j] << "  ";
        }
        cout << endl;
    }

    return 0;
}