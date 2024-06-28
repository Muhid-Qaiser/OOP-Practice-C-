#include <iostream>
#include<string>
using namespace std;

void displayBoard(char** grid, int row, int column)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			//cout << grid[i][j] << " ";
			cout << *(*(grid + i) + j) << " ";
		}
		cout << endl;
	}
}

bool isTie(char** grid, int row, int column)
{
	int count = 0;

	row = 0;

	for (int i = 0; i < column; i++)
	{
		//	if(grid[row][i]=='-')
		if (*(*(grid + row) + i) == '-')
		{
			count++;

		}

	}

	if (count == 0)
		return true;

	return false;

}

bool check(char** grid, int row, int column, int place, const char token)
{

	int counter = 0;

	//checking vertically
	for (int i = 0; i < row; i++)
	{
		//if( grid[i][place] == token )
		if (*(*(grid + i) + place) == token)
		{
			counter++;
		}

		else
			counter = 0;

		if (counter == 4)
		{
			return true;
		}

	}

	counter = 0;

	//checking horizontally
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{

			//if( grid[i][j] ==token )
			if (*(*(grid + i) + j) == token)
			{
				counter++;
			}
			else
				counter = 0;

			if (counter == 4)
				return true;

		}

		counter = 0;

	}

	counter = 0;

	//checking diagonally bottm left to top right
	for (int k = 0; k < (row + column - 1); k++)
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < column; j++)
			{
				if ((i + j) == k)
				{

					//if(grid[i][j]==token)
					if (*(*(grid + i) + j) == token)
						counter++;

					else
						counter = 0;

					if (counter == 4)
						return true;

				}
			}

		}

		counter = 0;
	}


	counter = 0;

	//checking diagonally top left to bottom right
	for (int j = 0; j <= (row + column - 1); j++)
	{
		for (int k = 0; k <= (j); k++)
		{
			int i = column - (j - k);

			if (i >= 0 && i < row && k < row)
			{

				//	if(grid[i][k]==token)
				if (*(*(grid + i) + k) == token)
					counter++;

				else
					counter = 0;

				if (counter == 4)
					return true;

			}
		}
		counter = 0;

	}


	return false;

}

int game(char** grid, int row, int column)
{
	int count = 0, place = 0;

	while (true)
	{
		//displaying columns
		for (int i = 0; i < column; i++)
		{
			cout << i << " ";
		}

		cout << endl;

		//displaying array
		displayBoard(grid, row, column);

		cout << ((count % 2 == 0) ? "\nPlayer 1 : " : "\nPlayer 2 : ")
			<< "Enter column to place " << ((count % 2 == 0) ? "x" : "+") << " : ";
		cin >> place;

		while (place >= column)
		{
			cout << "\nInvalid Entry!" << endl
				<< "Enter a column between 0-" << column - 1 << " : ";
			cin >> place;
		}

		cout << endl;



		if (count % 2 == 0)
		{

			//	for (int i = 0; ( i < row && ( grid[i][place]!='x' && grid[i][place] != '+' ) ) ; i++)
			for (int i = 0; (i < row && (*(*(grid + i) + place) != 'x' && *(*(grid + i) + place) != '+')); i++)
			{
				if (i == 0)
					*(*(grid + 0) + place) = 'x';
				//grid[0][place] = 'x';

				else {
					//grid[i][place] = grid[i - 1][place];
					//grid[i - 1][place] = '-';

					*(*(grid + i) + place) = *(*(grid + (i - 1)) + place);
					*(*(grid + (i - 1)) + place) = '-';

				}



			}

			if (check(grid, row, column, place, 'x'))
				return 1;

		}
		//	for (int i = 0; ( i < row && grid[i][place]!='+') ; i++)

		else
		{

			//for (int i = 0; ( i < row && ( grid[i][place]!='x' && grid[i][place] != '+' ) ) ; i++)
			for (int i = 0; (i < row && (*(*(grid + i) + place) != 'x' && *(*(grid + i) + place) != '+')); i++)
			{
				if (i == 0)
					*(*(grid + 0) + place) = '+';
				//grid[0][place] = '+';

				else {
					//grid[i][place] = grid[i - 1][place];
					//grid[i - 1][place] = '-';

					*(*(grid + i) + place) = *(*(grid + (i - 1)) + place);
					*(*(grid + (i - 1)) + place) = '-';

				}

			}

			if (check(grid, row, column, place, '+'))
				return 0;

		}


		if (isTie(grid, row, column))
		{
			return -1;
		}


		count++;

	}

}

void clearBoard(char** grid, int row)
{
	for (int j = 0; j < row; j++)
	{
		delete[](*(grid + j));
		//	grid[j][i] = NULL; 
	}

	delete[] grid;
	grid = NULL;

}

void whoWon(int winner)
{
	if (winner == 1)
	{
		cout << "\nPlayer 1 Won!!" << endl;
	}
	else if (winner == 0)
		cout << "\nPlayer 2 Won!!" << endl;
	else if (winner == -1)
		cout << "\nTie" << endl;
}

void playConnect4(int width, int height, char** board);


int main()
{

	int row = 7, column = 8, winner = 0;
	
	cout << "The Connect-4 Game " << endl
		 << "-----------------------------" << endl << endl ;

	cout << "Enter rows : ";
	cin >> row;

	cout << "Enter columns : ";
	cin >> column;


	char** grid = new char* [row];

	for (int i = 0; i < row; i++)
	{
		*(grid + i) = new char[column];

		for (int j = 0; j < column; j++)
		{
			*(*(grid + i) + j) = '-';
		}
	}

	playConnect4( column, row, grid);




	return 0;


}

void playConnect4(int width, int height, char** board) {
	
	int winner = 0;

	winner = game(board, height, width); //finds winner

	displayBoard(board, height, width); // displays board after every turn

	whoWon(winner); // displays winner

	clearBoard(board, height); // deletes ptrs

}
