#include<iostream>
#include<fstream>

using namespace std;

int ContentsFile(char*);
char* InitString(char*, int);
void OnlyWords(char*);
void CleanStr(char*);
void DisplayStr(char*);
void AddFile(char*, char*);


int main()
{
	const int N = 30;
	char inFileName[N] = "", outFileName[N] = "";
	cout << "Enter the name of input file: ";
	cin.getline(inFileName, N, '\n');
	cout << "Enter the name of output file: ";
	cin.getline(outFileName, N, '\n');

	int n = ContentsFile(inFileName);

	char* str = InitString(inFileName, n);

	DisplayStr(str);

	OnlyWords(str);

	DisplayStr(str);

	AddFile(outFileName, str);

	system("pause");

	return 0;
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

	int count = 0;
	char term;

	while (!streamIn.eof())
	{
		streamIn >> term;
		count++;
	}
	streamIn.close();
	return count;
}

char* InitString(char* fileName, int n)
{
	ifstream streamIn(fileName);
	if (!streamIn.is_open())
	{
		cout << "Cannot open file to read!" << endl;
		system("pause");
		exit(1);
	}
	char* arr = new char[n];

	streamIn.getline(arr, 256);

	streamIn.close();

	return arr;
}

void OnlyWords(char* string)
{
	char symbol[256] = " qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
	char* copy = new char[strlen(string)];
	int len = strlen(string);

	CleanStr(copy);

	for (int i = 0, j = 0; i < len; i++)
	{
		if (strchr(symbol, string[i]) != nullptr)
		{
			copy[j] = string[i];
			j++;
			copy[j] = '\0';
		}
	}

	CleanStr(string);
	strcpy(string, copy);

	delete[] copy;
}

void CleanStr(char* string)
{
	int len = strlen(string);
	for (int i = 0; i < len; i++)
	{
		string = '\0';
	}
}

void DisplayStr(char* string)
{
	int len = strlen(string);
	for (int i = 0; i < len; i++)
	{
		std::cout << string[i];
	}
	std::cout << endl;
}

void AddFile(char* fileName, char* arr)
{
	ofstream streamOut(fileName);

	if (!streamOut.is_open())
	{
		cout << "\nCannot open file to addition!\n";
		system("pause");
		exit(1);
	}

	streamOut << arr;
	
	streamOut.close();
}