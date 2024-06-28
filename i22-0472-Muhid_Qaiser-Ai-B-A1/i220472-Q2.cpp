#include <iostream>
using namespace std;

int** generateMagicSquare(int dimension);

int main()
{
	
	int dim = 0;

	int** MagicSquare = NULL;

	cout << "The Magic Square Generator " << endl 
		 << "---------------------------------------------" << endl << endl
		 << "Enter Dimensions : ";
	cin >> dim;

	while (dim % 2 == 0)
	{
		cout << "Enter Odd Number of Dimensions : ";
		cin >> dim;
	}

	MagicSquare = generateMagicSquare(dim);


	cout << endl << "MAGIC SQAURE : " << endl << endl;


	//Displaying the Magic Square
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			cout << *(*(MagicSquare + i) + j) << " ";
		}
		cout << endl;
	}

}

int** generateMagicSquare(int dimension) {
	


	int mid = 0, x = 0, y = 0, num = 0, temp1 = 0, temp2 = 0;

	num = 2;

	mid = dimension / 2; // getting middle row

	y = mid;

	int** grid = new int* [dimension];


	for (int i = 0; i < dimension; i++)
	{
		//grid[i] = new int[col];
		*(grid + i) = new int[dimension];


	}

	for (int i = 0; i < dimension; i++)
	{
		for (int j = 0; j < dimension; j++)
		{
			//grid[i][j] = 0;
			*(*(grid + i) + j) = 0;
		}
	}



	//grid[0][mid] = 1;
	
	*(*(grid+0)+mid) = 1;

	for (int i = 0; i < dimension; i++)
	{
		for (int j = 0; j < dimension; j++)
		{
			if (i == (dimension - 1) && j == (dimension - 1))
				break;

			temp1 = x;
			temp2 = y;

			if ((x - 1) < 0)
				x = dimension - 1;
			else
				x -= 1;

			if ((y + 1) >= dimension)
				y = 0;
			else
				y += 1;

		//	if (grid[x][y] != 0)
			if( *(*(grid+x)+y) != 0 )
			{

				x = temp1 + 1;
				y = temp2;
			//	grid[x][y] = num;
				*( *(grid+x) + y ) = num;

			}

			else
			{
				//grid[x][y] = num;
				*( *(grid+x) + y ) = num;

			}

			num++;

		}
	}

	return grid;

}
