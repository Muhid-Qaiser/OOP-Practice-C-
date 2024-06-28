#include <iostream>
using namespace std;

// !Classes and functions

class Matrix
{
    int **matrix;
    int row;
    int col;

public:
    Matrix()
    {
        matrix = NULL;
        row = 0;
        col = 0;
    }

    Matrix(int n1, int n2, int n3, int n4, int row = 2, int col = 2)
    {
        matrix = new int *[row];

        matrix[0] = new int[col];
        matrix[1] = new int[col];

        matrix[0][0] = n1;
        matrix[0][1] = n2;
        matrix[1][0] = n3;
        matrix[1][1] = n4;

        this->row = row;
        this->col = col;
    }

    Matrix(int n1, int n2, int n3, int n4, int n5, int n6, int n7, int n8, int n9, int row = 3, int col = 3)
    {
        matrix = new int *[row];

        matrix[0] = new int[col];
        matrix[1] = new int[col];
        matrix[2] = new int[col];

        matrix[0][0] = n1;
        matrix[0][1] = n2;
        matrix[0][2] = n3;
        matrix[1][0] = n4;
        matrix[1][1] = n5;
        matrix[1][2] = n6;
        matrix[2][0] = n7;
        matrix[2][1] = n8;
        matrix[2][2] = n9;

        this->row = row;
        this->col = col;
    }

    Matrix(int n1, int n2, int n3, int n4, int n5, int n6, int n7, int n8, int n9, int n10, int n11, int n12, int n13, int n14, int n15, int n16, int row = 4, int col = 4)
    {
        matrix = new int *[row];

        matrix[0] = new int[col];
        matrix[1] = new int[col];
        matrix[2] = new int[col];
        matrix[3] = new int[col];

        matrix[0][0] = n1;
        matrix[0][1] = n2;
        matrix[0][2] = n3;
        matrix[0][3] = n4;
        matrix[1][0] = n5;
        matrix[1][1] = n6;
        matrix[1][2] = n7;
        matrix[1][3] = n8;
        matrix[2][0] = n9;
        matrix[2][1] = n10;
        matrix[2][2] = n11;
        matrix[2][3] = n12;
        matrix[3][0] = n13;
        matrix[3][1] = n14;
        matrix[3][2] = n15;
        matrix[3][3] = n16;

        this->row = row;
        this->col = col;
    }

    Matrix(const Matrix &m)
    {
        this->row = m.row;
        this->col = m.col;

        matrix = new int *[m.row];

        for (int i = 0; i < m.row; i++)
        {
            matrix[i] = new int[m.col];

            for (int j = 0; j < m.col; j++)
                matrix[i][j] = m.matrix[i][j];
        }
    }

    ~Matrix() {}

    int getRow() { return row; }

    int getCol() { return col; }

    int getValue(int r, int c) { return matrix[r][c]; }

    void setValue(int row, int col, int value) { matrix[row][col] = value; }

    int Total()
    {
        int sum = 0;

        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                sum += matrix[i][j];

        return sum;
    }

    double Average()
    {
        double avg = 0.0;

        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                avg += matrix[i][j];

        return avg / (row * col);
    }

    int RowTotal(int row)
    {
        int sum = 0;

        for (int i = 0; i < this->col; i++)
            sum += matrix[row - 1][i];

        return sum;
    }

    int ColumnTotal(int col)
    {
        int sum = 0;

        for (int i = 0; i < this->row; i++)
            sum += matrix[i][col - 1];

        return sum;
    }

    int HighestInRow(int row)
    {
        int max = matrix[row - 1][0];

        for (int i = 0; i < col; i++)
        {
            if (max < matrix[row - 1][i])
                max = matrix[row - 1][i];
        }

        return max;
    }

    int LowestInRow(int row)
    {
        int min = matrix[row - 1][0];

        for (int i = 0; i < col; i++)
        {
            if (min > matrix[row - 1][i])
                min = matrix[row - 1][i];
        }

        return min;
    }

    Matrix Transpose()
    {
        Matrix transpose;

        transpose.matrix = new int *[col];

        for (int i = 0; i < col; i++)
            transpose.matrix[i] = new int[row];

        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                transpose.matrix[j][i] = matrix[i][j];

        return transpose;
    }

    int LeftDiagonalTotal()
    {
        int sum = 0;

        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                if (i == j)
                    sum += matrix[i][j];

        return sum;
    }

    int RightDiagonalTotal()
    {
        int sum = 0;

        for (int i = 0; i < row; i++)
            sum += matrix[i][row - i - 1];

        return sum;
    }

    Matrix Add(Matrix m)
    {
        Matrix result;
        result.matrix = new int *[row];

        for (int i = 0; i < row; i++)
            result.matrix[i] = new int[col];

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                result.matrix[i][j] = matrix[i][j] + m.matrix[i][j];
            }
        }

        return result;
    }

    Matrix Subtract(Matrix m)
    {
        Matrix result;
        result.matrix = new int *[row];

        for (int i = 0; i < row; i++)
            result.matrix[i] = new int[col];

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                result.matrix[i][j] = matrix[i][j] - m.matrix[i][j];
            }
        }

        return result;
    }

    Matrix Multiply(Matrix m)
    {
        Matrix result;
        result.matrix = new int *[row];

        for (int i = 0; i < row; i++)
            result.matrix[i] = new int[col];

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                result.matrix[i][j] = matrix[i][j] * m.matrix[i][j];
            }
        }

        return result;
    }

    int FindkSmallest(int k)
    {
        int *sort = new int[row * col];
        int count = 0;

        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                sort[count++] = matrix[i][j];

        for (int i = 0; i < row * col; i++)
            for (int j = 0; j < (row * col) - 1 - i; j++)
                if (sort[j] > sort[j + 1])
                {
                    int temp = sort[j];
                    sort[j] = sort[j + 1];
                    sort[j + 1] = temp;
                }

        return sort[k - 1];
    }

    int FindkLargest(int k)
    {
        int *sort = new int[row * col];
        int count = 0;

        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                sort[count++] = matrix[i][j];

        for (int i = 0; i < row * col; i++)
            for (int j = 0; j < (row * col) - 1 - i; j++)
                if (sort[j] < sort[j + 1])
                {
                    int temp = sort[j];
                    sort[j] = sort[j + 1];
                    sort[j + 1] = temp;
                }

        return sort[k - 1];
    }

    Matrix merge(Matrix &m)
    {

        Matrix joe;
        joe.matrix = new int *[row];

        for (int i = 0; i < 4; i++)
        {
            joe.matrix[i] = new int[col + m.col];
        }

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                joe.matrix[i][j] = this->matrix[i][j];
            }
        }

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                joe.matrix[i][j + m.col] = m.matrix[i][j];
            }
        }

        return joe;
    }

    void copyMatrix(int row, int col, int m[])
    {
        int count = 0;

        this->row = row;
        this->col = col;

        matrix = new int *[row];

        for (int i = 0; i < row; i++)
        {
            matrix[i] = new int[col];
            for (int j = 0; j < col; j++)
                matrix[i][j] = m[count++];
        }
    }
};

void Menu(int matrix[], int row, int col)
{
    int *temp = new int[row * col];

    int choice = 0;

    Matrix m1, m2, m3;

    m1.copyMatrix(row, col, matrix);

    cout << "\nMatrix : \n";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << m1.getValue(i, j) << " ";
        }
        cout << endl;
    }

    cout << "\n\nChoose Function"
         << "\n1.  getRow()"
         << "\n2.  getCol()"
         << "\n3.  getValue(x,y)"
         << "\n4.  setValue(x,y)"
         << "\n5.  Total()"
         << "\n6.  Average()"
         << "\n7.  Rowtotal(row)"
         << "\n8.  Columntotal(col)"
         << "\n9.  HighestInRow(row)"
         << "\n10. LowestInRow(row)"
         << "\n11. Transpose()"
         << "\n12. LeftDiagonalTotals()"
         << "\n13. RightDiagonalTotals()"
         << "\n14. Add(m)"
         << "\n15. Subtract(m)"
         << "\n16. Multiply(m)"
         << "\n17. FindkSmallest(k)"
         << "\n18. FindkLargest(k)"
         << "\n19. merge(m)"
         << endl
         << "\nEnter : ";
    cin >> choice;

    int x = 0, y = 0, val = 0, r = 0;

    cout << "\n------------------------------------------------\n";

    switch (choice)
    {
    case 1:
        cout << "\nRow of Matrix 1 : " << m1.getRow() << endl;
        break;
    case 2:
        cout << "\nColumn of Matrix 1 : " << m1.getCol() << endl;
        break;
    case 3:
        cout << "\nEnter x : ";
        cin >> x;
        cout << "\nEnter y : ";
        cin >> y;
        cout << "\nValue at index ( " << x << " , " << y << " ) : " << m1.getValue(x, y) << endl;
        break;
    case 4:
        cout << "\nEnter x : ";
        cin >> x;
        cout << "\nEnter y : ";
        cin >> y;
        cout << "\nEnter value at index ( " << x << " , " << y << " ) : ";
        cin >> val;

        cout << "\nSetting value..." << endl;

        m1.setValue(x, y, val);

        cout << "\nValue has been Updated!" << endl
             << endl;

        cout << "Matrix : \n";
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
                cout << m1.getValue(i, j) << " ";
            cout << endl;
        }

        break;
    case 5:
        cout << "\nTotal Sum of Matrix 1 : " << m1.Total() << endl;
        break;
    case 6:
        cout << "\nAverage of Matrix 1 : " << m1.Average() << endl;
        break;
    case 7:
        cout << "\nEnter the row you want to get Sum of : ";
        cin >> r;
        cout << "\nSum of Row " << r << " of Matrix 1 : " << m1.RowTotal(r) << endl;
        break;
    case 8:
        cout << "\nEnter the column you want to get Sum of : ";
        cin >> r;
        cout << "\nSum of Column " << r << " of Matrix 1 : " << m1.ColumnTotal(r) << endl;
        break;
    case 9:
        cout << "\nEnter the Row you want the Highest Value of : ";
        cin >> r;
        cout << "\nHighest Value in Row " << r << " of Matrix 1 : " << m1.HighestInRow(r) << endl;
        break;
    case 10:
        cout << "\nEnter the Row you want the Lowest Value of : ";
        cin >> r;
        cout << "\nLowest Value in Row " << r << " of Matrix 1 : " << m1.LowestInRow(r) << endl;
        break;
    case 11:
        cout << "\nTranspose of Matrix 1 : \n";

        m2 = m1.Transpose();

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cout << m2.getValue(i, j) << " ";
            }
            cout << endl;
        }

        break;
    case 12:
        cout << "\nLeft Diagonal of Matrix 1 : " << m1.LeftDiagonalTotal() << endl;
        break;
    case 13:
        cout << "\nRight Diagonal of Matrix 1 : " << m1.RightDiagonalTotal() << endl;
        break;
    case 14:
        cout << endl;

        for (int i = 0; i < row * col; i++)
        {
            cout << "Enter Matrix2[" << i << "]  : ";
            cin >> temp[i];
        }
        m3.copyMatrix(row, col, temp);

        cout << "\nAdding Matrix1 with Matrix2..." << endl
             << endl;

        m2 = m1.Add(m3);
        cout << "Matrix : \n";
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
                cout << m2.getValue(i, j) << " ";
            cout << endl;
        }

        break;
    case 15:
        cout << endl;

        for (int i = 0; i < row * col; i++)
        {
            cout << "Enter Matrix2[" << i << "]  : ";
            cin >> temp[i];
        }
        m3.copyMatrix(row, col, temp);

        cout << "\nSubtracting Matrix1 with Matrix2..." << endl
             << endl;

        m2 = m1.Subtract(m3);
        cout << "Matrix : \n";
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
                cout << m2.getValue(i, j) << " ";
            cout << endl;
        }

        break;
    case 16:
        cout << endl;

        for (int i = 0; i < row * col; i++)
        {
            cout << "Enter Matrix2[" << i << "]  : ";
            cin >> temp[i];
        }
        m3.copyMatrix(row, col, temp);

        cout << "\nMultiplying Matrix1 with Matrix2..." << endl
             << endl;

        m2 = m1.Multiply(m3);
        cout << "Matrix : \n";
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
                cout << m2.getValue(i, j) << " ";
            cout << endl;
        }

        break;
    case 17:
        cout << "\nEnter the Kth element index for the Smallest Kth element : ";
        cin >> r;
        cout << "\n"
             << r << "th smallest element in the Matrix1 : " << m1.FindkSmallest(r) << endl;
        break;
    case 18:
        cout << "\nEnter the Kth element index for the Largest Kth element : ";
        cin >> r;
        cout << "\n"
             << r << "th largest element in the Matrix1 : " << m1.FindkLargest(r) << endl;
        break;
    case 19:
        cout << endl;

        for (int i = 0; i < row * col; i++)
        {
            cout << "Enter Matrix2[" << i << "]  : ";
            cin >> temp[i];
        }
        m3.copyMatrix(row, col, temp);

        cout << "\nMerging Matrix1 and Matrix2..." << endl
             << endl;

        m2 = m1.merge(m3);

        cout << "Matrix : \n";
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col + col; j++)
                cout << m2.getValue(i, j) << " ";
            cout << endl;
        }
        break;

    default:
        cout << "\nError: Unknown\n";
    }
}

void chooseDimensions()
{
    int choice = 0;

    cout << "Choose Matrix Dimension" << endl
         << "1. 2x2" << endl
         << "2. 3x3" << endl
         << "3. 4x4" << endl
         << endl
         << "Enter : ";
    cin >> choice;

    cout << endl;

    switch (choice)
    {
    case 1:
        int m1[4];
        for (int i = 0; i < 4; i++)
        {
            cout << "Enter Matrix1[" << i << "] : ";
            cin >> m1[i];
        }
        Menu(m1, 2, 2);

        break;

    case 2:
        int m2[9];
        for (int i = 0; i < 9; i++)
        {
            cout << "Enter Matrix1[" << i << "] : ";
            cin >> m2[i];
        }
        Menu(m2, 3, 3);
        break;

    case 3:
        int m3[16];
        for (int i = 0; i < 16; i++)
        {
            cout << "Enter Matrix1[" << i << "] : ";
            cin >> m3[i];
        }
        Menu(m3, 4, 4);
        break;
    }
}

// ! Main

int main()
{
    cout << "\nMatrix Manipulating System" << endl
         << "================================================" << endl
         << endl;

    chooseDimensions();

    cout << "\n================================================" << endl
         << endl;
    return 0;
}
