#include<iostream>
#include<vector>

using namespace std;

#define UNASSIGNED 0
#define CAPACITY 9

bool getEmptyGridPosition(int grid[CAPACITY][CAPACITY], int& row, int& col)
{
	for (int i = 0; i < CAPACITY; ++i)
	{
		for (int j = 0; j < CAPACITY; ++j)
		{
			if (grid[i][j] == UNASSIGNED)
			{
				row = i;
				col = j;
				return true;
			}
		}
	}
	return false;
}

bool isSafe(int grid[CAPACITY][CAPACITY], int row, int col, int val)
{
	for (int i = 0; i < CAPACITY; ++i)
	{
		if (grid[row][i] == val)
			return false;

		if (grid[i][col] == val)
			return false;
	}

	for (int i = (row / 3) * 3; i < (row / 3) * 3 + 3; ++i)
	{
		for (int j = (col / 3) * 3; j < (col / 3) * 3 + 3; ++j)
		{
			if (grid[i][j] == val)
				return false;
		}
	}
	return true;
}

bool fillSudoku(int grid[CAPACITY][CAPACITY])
{
	int row, col;
	if (getEmptyGridPosition(grid, row, col))
	{
		for (int i = 1; i <= CAPACITY; ++i)
		{
			if (isSafe(grid, row, col, i))
			{
				grid[row][col] = i;
				if (fillSudoku(grid))
					return true;
				else
				{
					grid[row][col] = UNASSIGNED;
				}
			}
		}
		return false;
	}
	return true;
}

void printGrid(int grid[CAPACITY][CAPACITY])
{
	for (int i = 0; i < CAPACITY; ++i)
	{
		for (int j = 0; j < CAPACITY; ++j)
		{
			cout <<"  "<<grid[i][j];
		}
		cout << endl;
	}
}

int main()
{
	int grid[CAPACITY][CAPACITY] = {
		{3, 0, 0, 0, 9, 4, 0, 0, 6},
		{2, 0, 0, 6, 8, 3, 0, 0, 0},
		{6, 0, 7, 0, 2, 1, 0, 0, 9},
		{0, 1, 4, 0, 6, 0, 0, 0, 2},
		{8, 0, 3, 2, 0, 9, 4, 0, 5},
		{7, 0, 0, 0, 4, 0, 6, 8, 0},
		{9, 0, 0, 8, 1, 0, 5, 0, 4},
		{0, 0, 0, 4, 5, 6, 0, 0, 8},
		{4, 0, 0, 9, 3, 0, 6, 0, 7}
	};

	cout << endl << endl << endl;

	printGrid(grid);
	cout << endl;
	fillSudoku(grid);
	printGrid(grid);

}