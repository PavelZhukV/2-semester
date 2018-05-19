#include <io.h>
#include <fstream>
#include <iostream>
#include "Books.h"
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

void InitFile(char*);
void DisplayFile(char*);
void AddToEndFile(char*);
void ChangeFile(char*);
void RemoveFromFile(char*);
void InitNumber(long&);
void SystemFun();
void InitNameFile(char*);
void SortingFile(char*);
int Menu();


int main()
{
	char fileName[N] = "List.bin";
	enum { Init = 1, Create, Display, Add, Change, Remove, Sort, Exit };
	while (true)
	{
		int key = Menu();
		if (key == Exit)
			return 0;
		system("cls");
		switch (key)
		{
		case Init:
			InitNameFile(fileName);
			SystemFun();
			break;
		case Create:
			InitFile(fileName);
			SystemFun();
			break;
		case Display:
			DisplayFile(fileName);
			SystemFun();
			break;
		case Add:
			AddToEndFile(fileName);
			SystemFun();
			break;
		case Change:
			ChangeFile(fileName);
			SystemFun();
			break;
		case Remove:
			RemoveFromFile(fileName);
			SystemFun();
			break;
		case Sort:
			SortingFile(fileName);
			SystemFun();
			break;
		default:
			cout << "\nIncorrect input! Try again!";
			SystemFun();
		}
	}
}

void InitFile(char* fileName)
{
	ofstream streamOut;
	streamOut.open(fileName, ios::binary);
	if (!streamOut.is_open())
	{
		cout << "\nCan't open file to write!";
		SystemFun();
		return;
	}
	int bufSize = sizeof(Book);
	Book book;
	char ok = 'y';
	while (ok == 'y')
	{
		book.EnterBook();
		streamOut.write((char*)&book, bufSize);
		cout << " If do you want to continue, press 'y' :";
		cin >> ok;
	}
	streamOut.close();
}

void AddToEndFile(char* fileName)
{
	ofstream streamOut(fileName, ios::app | ios::binary);
	if (!streamOut.is_open())
	{
		cout << "Can't open file to write!";
		SystemFun();
		return;
	}
	int bufSize = sizeof(Book);
	Book book;
	char Ok = 'y';
	while (Ok == 'y')
	{
		book.EnterBook();
		streamOut.write((char*)&book, bufSize);
		cout << " If do you want to continue, press 'y' : ";
		cin >> Ok;
	}
	streamOut.close();
}

void ChangeFile(char* fileName)
{
	fstream streamInOut(fileName, ios::in | ios::out | ios::binary);
	if (!streamInOut)
	{
		cout << "Can't open file to read and write!";
		SystemFun();
		return;
	}
	int bufSize = sizeof(Book);
	Book book;
	long position;
	InitNumber(position);
	streamInOut.seekp((position - 1) * bufSize, ios::beg);
	book.EnterBook();
	streamInOut.write((char*)&book, bufSize);
	streamInOut.close();
}

void RemoveFromFile(char* fileName)
{
	fstream streamInOut(fileName, ios::in | ios::out | ios::binary);
	if (!streamInOut.is_open())
	{
		cout << "Can't open file to read and write!";
		SystemFun();
		return;
	}
	streamInOut.seekp(0, ios::end);
	long n = streamInOut.tellp();
	int bufSize = sizeof(Book);
	Book book;
	long Position;
	InitNumber(Position);
	streamInOut.seekp(Position * bufSize, ios::beg);
	while (streamInOut.read((char*)&book, bufSize))
	{
		streamInOut.seekp(-2 * bufSize, ios::cur);
		streamInOut.write((char*)&book, bufSize);
		streamInOut.seekp(bufSize, ios::cur);
	}
	streamInOut.close();
	int diskriptorFile = open(fileName, 2);//*
	chsize(diskriptorFile, n - bufSize);//*
	close(diskriptorFile);//*
}

void SortingFile(char* fileName)
{
	bool flag = true;
	while (flag)
	{
		fstream streamInOut(fileName, ios::in | ios::out | ios::binary);
		if (!streamInOut.is_open())
		{
			cout << "Can't open file to read and write!";
			SystemFun();
			return;
		}
		flag = false;
		Book bookOne, bookTwo;
		int bufSize = sizeof(Book);
		streamInOut.read((char*)&bookOne, bufSize);
		while (streamInOut.read((char*)&bookTwo, bufSize))
		{
			if (bookTwo.GetProfit() < bookOne.GetProfit())
			{
				streamInOut.seekp(-2 * bufSize, ios::cur);
				streamInOut.write((char*)&bookTwo, bufSize);
				streamInOut.write((char*)&bookOne, bufSize);
				flag = true;
			}
			streamInOut.seekp(-bufSize, ios::cur);
			streamInOut.read((char*)&bookOne, bufSize);
		}
		streamInOut.close();
	}
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
	int bufSize = sizeof(Book);
	Book* book = new Book;
	while (streamIn.read((char*)book, bufSize))
	{
		book->DisplayBook();
	}
	streamIn.close();
}

void InitNumber(long& n)
{
	cout << "Enter the number of record:" << endl;
	cin >> n;
	system("cls");
}

void SystemFun()
{
	cout << endl;
	system("pause");
	system("cls");
}

void InitNameFile(char* fileName)
{
	cout << "Enter the name of file: " << endl;
	cin.ignore();
	cin.getline(fileName, 256, '\n');
	system("cls");
}

int Menu()
{
	int k;
	cout << "\n Enter the number - the mode of operations with file:"
		"\n 1 - INITIALIZATION THE NAME OF FILE"
		"\n 2 - FORMATION OF THE FILE"
		"\n 3 - VIEWING OF CONTENTS OF THE FILE"
		"\n 4 - ADD AN ELEMENT TO AND OF FILE"
		"\n 5 - CHANGE THE ELEMENT IN THE FILE"
		"\n 6 - REMOVE THE ELEMENT IN THE FILE"
		"\n 7 - SORTING THE ELEMENT IN THE FILE"
		"\n 8 - EXIT\n";
	cin >> k;
	return k;
}
