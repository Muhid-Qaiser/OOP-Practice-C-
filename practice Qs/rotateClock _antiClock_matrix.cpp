#include <iostream>
using namespace std;

char **AllocateMemory(int rows, int col)
{
    char **matrix = new char *[rows];

    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new char[col];
    }

    return matrix;
}

void inputMatrix(char **matrix, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << "Enter Matrix[" << i << "][" << j << "] : ";
            cin >> matrix[i][j];
        }
    }
}

void DisplayMatrix(char **matrix, int row, int col)
{
    cout << "\nMatrix:\n";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

bool isAllDiagonal(char **matrix, int row, int col)
{
    int *temp = new int[row];
    int count = 0;

    for (int i = 0; i < row; i++)
    {
        temp[i] = 0;
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i == j)
            {
                temp[count++] = matrix[i][j];
            }
            // else if (i + j == row)
            // {
            //     temp[count++] = matrix[i][j];
            // }
        }
    }

    for (int i = 0; i < count - 1; i++)
    {
        if (temp[i] != temp[i + 1])
            return false;
    }
    return true;
}

void rotateAntiClockwise(char **matrix, int row, int col)
{
    char **temp = new char *[row];

    for (int i = 0; i < row; i++)
    {
        temp[i] = new char[col];
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            temp[j][i] = matrix[i][j];
        }
    }

    char **temp2 = new char *[col];

    for (int i = 0; i < col / 2; i++)
    {
        temp2[i] = temp[i];
        temp[i] = temp[col - i - 1];
        temp[row - 1 - i] = temp2[i];
    }

    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            matrix[i][j] = temp[i][j];
        }
    }
}

void rotateClockwise(char **matrix, int row, int col)
{
    /*
    for (int i = 0; i < n; i++)
    {
        int top = 0;
        int bottom = n - 1;
        while (top < bottom)
        {
            int temp = matrix[top][i];
            matrix[top][i] = matrix[bottom][i];
            matrix[bottom][i] = temp;
            top++;
            bottom--;
        }
    }
    */

    char **temp = new char *[col];

    for (int i = 0; i < col; i++)
    {
        temp[i] = new char[row];
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            temp[j][i] = matrix[i][j];
        }
    }

    int left = 0, right = row - 1, temp2 = 0;

    for (int i = 0; i < col; i++)
    {
        left = 0;
        right = row - 1;

        while (left < right)
        {
            temp2 = temp[i][left];
            temp[i][left] = temp[i][right];
            temp[i][right] = temp2;
            left++;
            right--;
        }
    }

    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            matrix[i][j] = temp[i][j];
        }
    }
    delete[] temp;
}

int main()
{
    char **matrix = AllocateMemory(4, 4);
    inputMatrix(matrix, 4, 4);
    DisplayMatrix(matrix, 4, 4);
    cout << "diagonal : " << isAllDiagonal(matrix, 4, 4) << endl;
    // rotateAntiClockwise(matrix, 4, 4);
    rotateClockwise(matrix, 4, 4);
    DisplayMatrix(matrix, 4, 4);

    return 0;
}