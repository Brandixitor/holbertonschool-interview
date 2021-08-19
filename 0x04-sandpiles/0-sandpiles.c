#include "sandpiles.h"
/**
 * sandpiles_print - Function to print grid
 * @grid: Grid to print
**/
void sandpiles_print(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}
/**
 * sandpiles_check - Checks if sandpiles is stable
 * @grid1: grid to check
 * Return: 1 if the sandpiles is stable otherwise 0
 **/
int sandpiles_check(int grid1[3][3])
{
	int x = 0, y = 0;

	while (y < 3)
	{
		x = 0;
		while (x < 3)
		{
			if (grid1[y][x] && grid1[y][x] > 3)
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
/**
 * sandpiles_compute - Compute two grids, simple addition
 * @grid1: Grid A, values are replaced
 * @grid2: Grid B
 **/
void sandpiles_compute(int (*grid1)[3], int grid2[3][3])
{
	int x = 0, y = 0;

	while (y < 3)
	{
		x = 0;
		while (x < 3)
		{
			(*grid1)[x] += grid2[y][x];
			x++;
		}
		(*grid1++);
		y++;
	}
}
/**
 * sandpiles_toppling - Topples the sandpiles
 * @grid1: Old grid values, values are replaced with the new one
 * @grid2: Old grid values
 **/
void sandpiles_toppling(int (*grid1)[3], int grid2[3][3])
{
	int x = 0, y = 0;

	while (y < 3)
	{
		x = 0;
		while (x < 3)
		{
			if (grid2[y][x] > 3)
			{
				(*grid1)[x] -= 4;
			}
			if (x - 1 >= 0)
			{
				if (grid2[y][x - 1] > 3)
					(*grid1)[x] += 1;
			}
			if (x + 1 < 3)
			{
				if (grid2[y][x + 1] > 3)
					(*grid1)[x] += 1;
			}
			if (y - 1 >= 0)
			{
				if (grid2[y - 1][x] > 3)
					(*grid1)[x] += 1;
			}
			if (y + 1 < 3)
			{
				if (grid2[y + 1][x] > 3)
					(*grid1)[x] += 1;
			}
			x++;
		}
		(*grid1++);
		y++;
	}
}
/**
 * sandpiles_sum - function that computes the sum of two sandpiles, must
 * print @grid1 if it is unstable before each toppling
 * @grid1: stable grid
 * @grid2: stable grid
 **/
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int check_sandpiles = -1;
	int y = 0, x = 0;

	sandpiles_compute(grid1, grid2);
	while (check_sandpiles != 1)
	{
		/** Store the new grid in grid2 to make some calculations **/
		for (y = 0; y < 3; y++)
		{
			for (x = 0; x < 3; x++)
			{
				grid2[y][x] = grid1[y][x];
			}
		}
		/** Prints a message if the grid is unstable. **/
		check_sandpiles = sandpiles_check(grid1);
		if (check_sandpiles == 0)
		{
			printf("=\n");
			sandpiles_print(grid1);
		}
		else
			return;
		sandpiles_toppling(grid1, grid2);
	}
}
