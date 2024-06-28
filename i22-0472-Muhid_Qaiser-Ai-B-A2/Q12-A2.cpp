#include <iostream>
using namespace std;

// ! Function Prototypes

// * Display Board
void displayBoard(char **board, int i = 0, int j = 0)
{
    // Base Condition
    if (i == 12)
        return;

    else if (j < 12)
    {
        cout << board[i][j] << " ";
        displayBoard(board, i, j + 1);
    }

    else
    {
        cout << endl;
        displayBoard(board, i + 1, 0);
    }
}

// * Checking right side
bool RightContact(char **board, int row, int col, int r, int c)
{
    if (r == 1)
        return board[row][col - 1] == '#';

    else if (c == 1)
        return board[row + 1][col] == '#';

    else if (r == -1)
        return board[row][col + 1] == '#';

    else if (c == -1)
        return board[row - 1][col] == '#';
}

// * Traversing the Maze board
bool mazeTraverse(char **board, int srow, int scol, int row, int col, int r, int c)
{
    // * Checking if Maze Not Traversed
    if (row == srow && col == scol)
        return false;

    // * Checking if Mazed is Traversed
    else if (row == 11 || col == 11 || row == 0 || col == 0)
        return true;

    // * Moving X around the right side of the Maze
    else if (!RightContact(board, row, col, r, c))
    {
        // Changing the Direction to the right side of the Maze
        if (r == -1 && c == 0)
        {
            r = 0;
            c = 1;
        }
        else if (r == 0 && c == 1)
        {
            r = 1;
            c = 0;
        }
        else if (r == 1 && c == 0)
        {
            r = 0;
            c = -1;
        }
        else if (r == 0 && c == -1)
        {
            r = -1;
            c = 0;
        }
    }

    // * Checking to see if the Next Step is a Wall
    else if (board[row + r][col + c] == '#')
    {

        if (r == -1)
        {
            r = 0;
            if (board[row][col + 1] != '#')
                c = 1;
            else if (board[row][col - 1] != '#')
                c = -1;
            else
                r = 1;
        }
        else if (r == 1)
        {
            r = 0;
            if (board[row][col - 1] != '#')
                c = -1;
            else if (board[row][col + 1] != '#')
                c = 1;
            else
                r = -1;
        }
        else if (c == -1)
        {
            c = 0;
            if (board[row - 1][col] != '#')
                r = -1;
            else if (board[row + 1][col] != '#')
                r = 1;
            else
                c = 1;
        }
        else if (c == 1)
        {
            c = 0;
            if (board[row + 1][col] != '#')
                r = 1;
            else if (board[row - 1][col] != '#')
                r = -1;
            else
                c = -1;
        }
    }

    // Updating X position
    row += r, col += c;
    board[row][col] = 'X';

    // * Display Board
    /*
    for (int i = 0; i < 12; i++, cout << " ", cout << endl)
        for (int j = 0; j < 12; j++)
            cout << board[i][j] << " ";
    */

    displayBoard(board);

    cout << "\n-----------------------" << endl;

    return mazeTraverse(board, srow, scol, row, col, r, c); // Function calling
}

// * Getting the intial direction and position ready for traversal of Maze
bool solveMaze(char **board, int nrows, int ncols, int srow, int scol)
{
    int r = 0, c = 0, row, col;

    // * Setting initial Direction of movement
    if (srow == 0)
        r = 1;
    else if (scol == 0)
        c = 1;
    else if (srow == 11)
        r = -1;
    else if (scol == 11)
        c = -1;

    board[srow][scol] = 'X';

    // * Display Board
    /*
    for (int i = 0; i < 12; i++, cout << " ", cout << endl)
        for (int j = 0; j < 12; j++)
            cout << board[i][j] << " ";
    */

    displayBoard(board);

    cout << "\n-----------------------" << endl;

    // * Moving Position of X
    row = srow + r, col = scol + c;
    board[row][col] = 'X';

    // * Display Board
    /*
    for (int i = 0; i < 12; i++, cout << " ", cout << endl)
        for (int j = 0; j < 12; j++)
            cout << board[i][j] << " ";
    */

    displayBoard(board);

    cout << "-----------------------" << endl;

    return mazeTraverse(board, srow, scol, row, col, r, c); // Function calling
}

// ! Main Function
int main()
{
    // Initializing the Maze in Temporary Board
    char temp_board[12][12] = {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '#'},
        {'#', '.', '#', '.', '#', '.', '#', '#', '#', '#', '.', '#'},
        {'#', '#', '#', '.', '#', '.', '.', '.', '.', '#', '.', '#'},
        {'#', '.', '.', '.', '.', '#', '#', '#', '.', '#', '.', '.'},
        {'#', '#', '#', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
        {'#', '.', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
        {'#', '#', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
        {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '#'},
        {'#', '#', '#', '#', '#', '#', '.', '#', '#', '#', '.', '#'},
        {'.', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}};

    char **board = new char *[12]; // Declaring actual Board

    for (int i = 0; i < 12; i++)
    {
        board[i] = new char[12];

        for (int j = 0; j < 12; j++)
            board[i][j] = temp_board[i][j]; // Copying Temp Board to actual Board
    }

    // ? Second Board for Checking
    /*    char board[12][12] = {
            {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
            {'#', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '#'},
            {'.', '.', '#', '.', '#', '.', '#', '#', '#', '#', '.', '#'},
            {'#', '#', '#', '.', '#', '.', '.', '.', '.', '#', '.', '#'},
            {'#', '.', '.', '.', '.', '#', '#', '#', '.', '#', '.', '#'},
            {'#', '#', '#', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
            {'.', '.', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
            {'#', '#', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
            {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '#'},
            {'#', '#', '#', '#', '#', '#', '.', '#', '#', '#', '.', '#'},
            {'#', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '#'},
            {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}};

     solveMaze(board, 12, 12, 6, 0);
    */

    cout << "\nMaze Traversing System " << endl
         << "-----------------------------------------------------" << endl
         << endl;

    displayBoard(board);

    cout << "\n-----------------------------------------------------" << endl
         << endl
         << "Press Any Key to Start Traversing..." << endl;
    cin.get();

    // Function Calling
    (solveMaze(board, 12, 12, 4, 11)) ? cout << "\nMaze has been Successfully traversed and Exited!\n\n" : cout << "\nFailed to Exit the Maze!\n\n";

    cout << "-----------------------------------------------------" << endl
         << endl;

    return 0;
}