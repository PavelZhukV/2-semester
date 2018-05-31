#include <iostream>
#include <fstream>
#include <cmath>
#include <stdexcept>

using namespace std;

void addFile(char*, int**, int);
void swap(int& , int& );
int** task8(int**, int);
int maxElement(int**, int, int, int);
int** initMatrix(char*, int);
void DisplayMatrix(int**, int );
int** allocateMemoryForMatrix(int );


int main()
{
	const int N = 30;
	char fileName[N] = "Matrix.txt";
	int n = 4;

	int** matrix = initMatrix(fileName, n);
	DisplayMatrix(matrix, n);
	cout << endl;
	int ** newMatrix = task8(matrix,n);
	DisplayMatrix(newMatrix, n);
	addFile(fileName, newMatrix, n);
	system("pause");
	return 0;
}

int** task8(int** matrix, int n)
{
	int** newmatrix = allocateMemoryForMatrix(n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			newmatrix[i][j] = maxElement(matrix, i, j, n);
		}
	}
	return newmatrix;
}

int maxElement(int** matrix, int a, int b, int n)
{
	int max = matrix[a][b];
	for (int i = 0; i < n; i++)
	{
		int j1 = b - a + i, j2 = a + b - i;
		if (j1 < 0)
			j1 = 0;
		if (j2 > n)
			j2 = n;
		if (j1 > j2)
			swap(j1, j2);
		for (int j = 0; j < n; j++)
		{
			if ((j <= j1) || (j >= j2))
				if (matrix[i][j] > max)
					max = matrix[i][j];
		}
	}
	return max;
}

void swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}

void addFile(char* fileName, int** array, int n)
{
	ofstream streamOut(fileName, ios::app);

	if (!streamOut.is_open())
	{
		cout << "\nCannot open file to addition!\n";
		system("pause");
		exit(1);
	}

	streamOut << "\n new matrix:\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			streamOut.width(4);
			streamOut << array[i][j];
		}
		streamOut << endl;
	}

	streamOut.close();
}

int** initMatrix(char* fileName, int n)
{
	ifstream streamIn(fileName);

	if (!streamIn.is_open())
	{
		cout << "Cannot open file to read!" << endl;
		system("pause");
		exit(1);
	}

	int** matrix = new int*[n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[n];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			streamIn >> matrix[i][j];
		}
	}

	streamIn.close();
	return matrix;
}

void DisplayMatrix(int** matrix, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout.width(4);
			cout << matrix[i][j];
		}
		cout << endl;
	}
}

int** allocateMemoryForMatrix(int n)
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
