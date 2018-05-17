#include<iostream>
#include<fstream>
#include<io.h>
#include "Header.h"

void DisplayFile(char*);
void SystemFun();                              //Text file Named "Control.txt"
void Task(char*,char*, int);
void InitData(int&, char*,char*);

using namespace std;

int main()
{
	int base = 2;
	char textName[32],binName[32];

	InitData(base, textName,binName);

	Task(textName,binName, base);

	DisplayFile(binName);

	system("pause");
	return 0;
}

void DisplayFile(char* fileName)
{
	ifstream streamIn(fileName, ios::binary);
	if (!streamIn.is_open())
	{
		cout << "Can't open file to read!";
		SystemFun();
		return;
	}

	int bufSize = sizeof(Num);
	Num* numbers = new Num;

	while (streamIn.read((char*)numbers, bufSize))
	{
		numbers->DisplayNum();
	}

	streamIn.close();
}

void SystemFun()
{
	cout << endl;
	system("pause");
	system("cls");
}

void Task(char* textname, char* binname, int base)
{
	ifstream streamIn(textname);
	if (!streamIn.is_open())
	{
		cout << "Cannot open file to read!" << endl;
		system("pause");
		exit(1);
	}
	
	ofstream streamOut(binname, ios::app | ios::binary);
	if (!streamOut.is_open())
	{
		cout << "Can't open file to write!";
		SystemFun();
		return;
	}

	Num number;

	while (!streamIn.eof())
	{
		int count = 0;
		streamIn >> count;
		if (count > 0)
		{
			number.SetNum(count, base);
			int bufSize = sizeof(Num);
			streamOut.write((char*)&number, bufSize);
		}
	}

	streamOut.close();
	streamIn.close();
}

void InitData(int& base, char* textname,char* binname)
{
	cout << "enter text file name: ";
	cin.getline(textname, 20);
	cout << "enter bin file name: ";
	cin.getline(binname, 20);
	cout << "enter base: ";
	cin >> base ;
	cout << '\n';
}