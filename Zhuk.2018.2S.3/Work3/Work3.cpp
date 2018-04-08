#include "stdafx.h"
#include <cmath>
#include "Work3.h"
#include <stdexcept>

using namespace std;
using namespace Work3;

WORK3LIBRARY_API int** Work3:: allocateMemoryForMatrix(int n)
{
	if (n < 1)
		throw out_of_range("Invalid data");
	int** x = new int*[n];
	for (int i = 0; i < n; i++)
	{
		x[i] = new int[n];
	}
	return x;
}

WORK3LIBRARY_API void Work3::initRandMatrix(int** matrix, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrix[i][j] = rand() % 100;
		}
	}
}

WORK3LIBRARY_API int** Work3::task8(int** matrix, int n)
{
	int** newmatrix = Work3::allocateMemoryForMatrix(n);
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			newmatrix[i][j] = Work3::maxElement(matrix,i,j,n);
		}
	}
	return newmatrix;
}

WORK3LIBRARY_API int Work3::maxElement(int** matrix, int a, int b,int n)
{
	int max = matrix[a][b];
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if ((j >= b - a + i) || (j <= a + b + i))
			{
				if (matrix[i][j] > max)
					max = matrix[i][j];
			}
		}
	}
	for (int i = a,j = 0; j < n; j++)
	{
				if (matrix[i][j] > max)
					max = matrix[i][j];
	}
	for (int i = a + 1; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if ((j <= b - a + i) || (j >= a + b + i))
			{
				if (matrix[i][j] > max)
					max = matrix[i][j];
			}
		}
	}
	return max;
}