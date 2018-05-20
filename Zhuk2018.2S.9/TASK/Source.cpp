#include<iostream>
#include<fstream>

using namespace std;

void CreateFile(char*, int );
int ContentsFile(char*);
int* InitArray(char*, int);
void AddFile(char*, int*, int);
void HexInclusionSort(int*, int );
void DeleteElement(int*, int & , int);
bool IsBadNumber(int , int);
int FirstHexSymbol(int );
void Task13(int* , int & , char , int* , int & );
int badSymbol(char);
void DeleteEqualElements(int*, int & );
void DeleteInNewArray(int* , int & , char , int*, int & );
void DisplayArray(int* , int );

int main()
{
	const int N = 30;
	char fileName[N] = "";
	int n;
	char a;
	int k = 0;

	cout << "Enter the name of file: ";
	cin.getline(fileName, N, '\n');
	cout << "Enter count of th numbers:" << endl;
	cin >> n;
	cout << "Enter bad Symbol:" << endl;
	cin >> a;
	system("cls");

	CreateFile(fileName, n);

	int count = ContentsFile(fileName);
	int* narray = new int[count];
	int* array = InitArray(fileName, count);

	DisplayArray(array, count);

	Task13(array, count, a, narray, k);

	cout << "Sort and clean array:\n";
	DisplayArray(array, count);
	cout << "Finish new array:\n";
	DisplayArray(narray, k);

	AddFile(fileName, narray, k);

	system("pause");
	return 0;
}

void CreateFile(char* fileName, int n)
{
	ofstream streamOut(fileName);

	if (!streamOut.is_open())
	{
		cout << "Cannot open file to write!" << endl;
		system("pause");
		exit(1);
	}

	system("cls");
	for (int i = 1; i <= n; i++)
	{
		int temp = rand() % 100;
		streamOut.width(5);
		streamOut << temp;
	}

	streamOut.close();
}

int ContentsFile(char* fileName)
{
	ifstream streamIn(fileName);

	if (!streamIn.is_open())
	{
		cout << "Cannot open file to read!" << endl;
		system("pause");
		exit(1);
	}

	int count = 0, term;

	while (!streamIn.eof())
	{
		streamIn >> term;
		count++;
	}
	streamIn.close();
	return count;
}

int* InitArray(char* fileName, int n)
{
	ifstream streamIn(fileName);
	if (!streamIn.is_open())
	{
		cout << "Cannot open file to read!" << endl;
		system("pause");
		exit(1);
	}
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
		streamIn >> arr[i];
	streamIn.close();
	return arr;
}

void AddFile(char* fileName, int* arr, int n)
{
	ofstream streamOut(fileName, ios::app);

	if (!streamOut.is_open())
	{
		cout << "\nCannot open file to addition!\n";
		system("pause");
		exit(1);
	}
	streamOut << "\nFinish array!\n";
	for (int i = 0; i < n; i++)
	{
		streamOut.width(5);
		streamOut << arr[i];
	}
	streamOut.close();
}

void HexInclusionSort(int* array, int n)
{
	for (int i = 1; i < n; i++)
	{
		int index = i;
		int value = array[i];
		while ((index > 0) && (FirstHexSymbol(array[index - 1]) > FirstHexSymbol(value)))
		{
			array[index] = array[index - 1];
			index--;
		}
		array[index] = value;
	}
}

void DeleteElement(int* array, int & n, int num)
{
	for (int i = num; i < n - 1; i++)
	{
		array[i] = array[i + 1];
	}
	n--;
}

bool IsBadNumber(int x, int badsymbol)
{
	while (x > 0)
	{
		if (x % 16 == badsymbol)
			return 1;
		else
			x /= 16;
	}
	return 0;
}

int FirstHexSymbol(int x)
{
	while (x >= 15)
	{
		x /= 16;
	}
	return x;
}

void Task13(int* array, int & n, char a, int* narray, int & k)
{
	DeleteEqualElements(array, n);
	HexInclusionSort(array, n);
	DeleteInNewArray(array, n, a, narray, k);
}

int badSymbol(char symbol)
{
	int a;
	switch (symbol)
	{
	case 'A':
		a = 10;
		break;
	case 'B':
		a = 11;
		break;
	case 'C':
		a = 12;
		break;
	case 'D':
		a = 13;
		break;
	case 'E':
		a = 14;
		break;
	case 'F':
		a = 15;
		break;
	}
	return a;
}

void DeleteEqualElements(int* array, int & n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j<n; j++)
			if (array[i] == array[j])
			{
				DeleteElement(array, n, j);
				j--;
			}
	}
}

void DeleteInNewArray(int* array, int & n, char a, int* narray, int & k)
{
	k = 0;
	for (int i = 0, j = -1; i < n; i++)
	{
		if (IsBadNumber(array[i], badSymbol(a)))
		{
			j++;
			k++;
			narray[j] = array[i];
			DeleteElement(array, n, i);
			i--;
		}
	}
}

void DisplayArray(int* array,int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl<< 
		endl;
}