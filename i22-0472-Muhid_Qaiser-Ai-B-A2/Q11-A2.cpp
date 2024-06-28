#include <iostream>
using namespace std;

// ! Function Prototypes
void printBoard(char **board, int N, int, int);

bool checkSafe(char **board, int N, int row, int col, int, int);

bool nQueens(char **board, int N, int row = 0, int col = 1);

// ! Main
int main()
{
    // initialization and declaration
    int N = 9;
    char **board = new char *[N];

    // Filling the board
    for (int i = 0; i < N; i++)
    {
        board[i] = new char[N];

        for (int j = 0; j < N; j++)
            board[i][j] = '.';
    }

    cout << "\nNine Queen Placement Program" << endl
         << "================================================" << endl
         << endl
         << "Enter 1 to Exit " << endl;
    nQueens(board, N); // Function calling

    cout << "\nProgram Ending..." << endl
         << endl
         << "================================================" << endl
         << endl;

    return 0;
}

// ! Function Definitions

// * print board
void printBoard(char **board, int N, int i = 0, int j = 0)
{
    if (i == N)
        return;

    else if (j == 0)
    {
        cout << "|" << board[i][j] << " ";
        printBoard(board, N, i, j + 1);
    }

    else if (j < N)
    {
        cout << " " << board[i][j] << " ";
        printBoard(board, N, i, j + 1);
    }
    else
    {
        cout << "|" << endl;
        printBoard(board, N, i + 1, j = 0);
    }
}

// * check if a queen can be placed in row i and column j
bool checkSafe(char **board, int N, int row, int col, int i = 0, int j = 0)
{
    // base condition
    if (i == N)
        return true;

    else if (j < N)
    {

        // Check row
        if (board[row][j] == 'Q')
            return false;

        // Check column
        if (board[i][col] == 'Q')
            return false;

        // Check diagonals
        if (board[i][j] == 'Q' && (i - j == row - col || i + j == row + col))
            return false;

        checkSafe(board, N, row, col, i, j + 1); // moving Column wise
    }

    else if (j == N)
        checkSafe(board, N, row, col, i + 1, j = 0); // moving Row wise
}

// * solve Nine Queens problem recursively
bool nQueens(char **board, int N, int row, int col)
{
    // base case: all queens placed
    if (row == N)
    {
        char temp;
        cout << " ---------------------------" << endl;
        printBoard(board, N);
        cout << " ---------------------------" << endl;
        cout << "Enter Value : ";
        cin.get(temp);
        cout << endl;
        return (temp == '1') ? true : false; // Returning the Control Back Inorder to Produce the Next Solution
    }

    // try placing queen in each column of current row
    if (col < N)
    {
        if (checkSafe(board, N, row, col))
        {
            board[row][col] = 'Q';
            if (nQueens(board, N, row + 1, 0)) // Function recalling
                return true;

            board[row][col] = '.';
        }

        nQueens(board, N, row, col + 1);
    }

    return false;
}
