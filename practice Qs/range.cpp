#include <iostream>
using namespace std;

int main()
{
    int row = 4, col = 4, min = 0, max = 0, ans = 0, count = 0;

    int **matrix = new int *[row];

    for (int i = 0; i < row; i++)
    {
        matrix[i] = new int[col];
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            matrix[i][j] = count++;
        }
    }

    min = matrix[0][0];
    max = matrix[0][0];

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] > max)
            {
                max = matrix[i][j];
            }
            if (matrix[i][j] < min)
            {
                min = matrix[i][j];
            }
        }
    }

    ans = ((max - min) / row) + min;

    cout << ans << endl;

    return 0;
}