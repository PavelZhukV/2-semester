#include <iostream>
#include "Books.h"
#include <string.h>

using namespace std;

Book* InitNewArray(long&);
void DisplayArray(Book*,long);
void AddToEndArray(Book*,long&);
void InitNumber(long&);
void SystemFun();
void SortingArray(Book*,long);
void CopyArray(Book*, Book*, long );
int Menu();


int main()
{
	enum { Init = 1, Display, Add, Sort, Exit };

	long n;
	Book* books = InitNewArray(n);
	

	while (true)
	{
		int key = Menu();
		if (key == Exit)
			return 0;
		system("cls");
		switch (key)
		{
		case Init:
			InitNewArray(n);
			SystemFun();
			break;
		case Display:
			DisplayArray(books,n);
			SystemFun();
			break;
		case Add:
			AddToEndArray(books,n);
			SystemFun();
			break;
		case Sort:
			SortingArray(books,n);
			SystemFun();
			break;
		default:
			cout << "\nIncorrect input! Try again!";
			SystemFun();
		}
	}
}

Book* InitNewArray(long& n)
{
	InitNumber(n);

	Book* books = new Book[n];
	Book book;

	for (int i = 0 ; i < n ; i++)
	{
		book.EnterBook();
		books[i] = book;
	}

	return books;
}

void AddToEndArray(Book* books,long& n)
{
	Book book;
	char Ok = 'y';
	while (Ok == 'y')
	{
		book.EnterBook();

		Book* copy = new Book[n + 1];
		CopyArray(copy, books,n);
		copy[n] = book;
		books = new Book[n + 1];
		CopyArray(books, copy, n + 1);
		delete[]copy;
		n++;

		cout << " If do you want to continue, press 'y' : ";
		cin >> Ok;
	}
}

void SortingArray(Book* books,long n)
{
	bool flag = true;
	while (flag)
	{
		flag = false;
		Book bookBuf;
		for (int i = 0;i < n - 1; i++)
		{
			if (books[i].GetProfit() < books[i + 1].GetProfit())
			{
				bookBuf = books[i];
				books[i] = books[i + 1];
				books[i + 1] = bookBuf;
				flag = true;
			}
		}
	}
}

void DisplayArray(Book* books,long n)
{
	for (int i = 0; i < n; i++)
	{
		books[i].DisplayBook();
	}
}

void InitNumber(long& n)
{
	n = 0;
	while (n <= 0)
	{
		cout << "Enter the number of books n > 0 :" << endl;
		cin >> n;
		if (n < 0)
		{
			cout << "n must be more than 0! Try again" << endl;
			system("pause");
			system("cls");
		}
	}
}

void SystemFun()
{
	cout << endl;
	system("pause");
	system("cls");
}

int Menu()
{
	int k;
	cout << "\n Enter the number - the mode of operations with file:"
		"\n 1 - INITIALIZATION OF THE ARRAY ANEW"
		"\n 2 - VIEWING OF CONTENTS OF THE ARRAY"
		"\n 3 - ADD AN ELEMENTS TO END OF ARRAY"
		"\n 4 - SORTING THE ELEMENT IN THE ARRAY"
		"\n 5 - EXIT\n";
	cin >> k;
	return k;
}

void CopyArray(Book* booksIn, Book* booksFrom, long n)
{
	for (int i = 0; i < n; i++)
	{
		booksIn[i] = booksFrom[i];
	}
}