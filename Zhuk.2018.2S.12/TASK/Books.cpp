#include <iostream>
#include "Books.h"
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>

using namespace std;


Book::Book(char * Name, char * AuthFirstName, char * AuthLastName, char * publishing, int year, int cost, int price)
{
	this->SetBook(Name, AuthFirstName, AuthLastName, publishing, year, cost, price);
}

void Book::SetBook(char * Name, char * AuthFirstName, char * AuthLastName, char * publishing, int year, int cost, int price)
{
	this->SetName(Name);
	this->SetAuthName(AuthFirstName, AuthLastName);
	this->SetPublishing(publishing);
	this->SetCost(cost);
	this->SetPrice(price);
	this->SetYear(year);
	this->SetProfit(cost, price);
}

void Book::SetName(char * Name)
{
	strcpy(this->Name, Name);
}

void Book::SetAuthName(char * AuthFirstName, char* AuthLastName)
{
	strcpy(this->AuthFirstName, AuthFirstName);
	strcpy(this->AuthLastName, AuthLastName);
}

void Book::SetPublishing(char * publishing)
{
	strcpy(this->Publishing, publishing);
}

void Book::SetYear(int year)
{
	if (year >= 1895 && year <= 2018)
		this->year = year;
}

void Book::SetCost(int cost)
{
	if (cost > 0)
		this->cost = cost;
}

void Book::SetPrice(int price)
{
	if (price > 0)
		this->price = price;
}

char * Book::GetAuthName()
{
	return strcat(this->AuthFirstName, this->AuthLastName);
}

char * Book::GetName()
{
	return this->Name;
}

char * Book::GetPublishing()
{
	return this->Publishing;
}

int Book::GetProfit()
{
	return this->profit;
}

void Book::EnterBook()
{
	const int N = 256;
	char Name[N] = "", AuthFirstName[N] = "", AuthLastName[N] = "", publishing[N] = "";

	cout << "Enter the name of book:";
	cin.ignore();
	cin.getline(Name, N, '\n');
	cout << "Enter the author's first name:";
	cin.getline(AuthFirstName, N, '\n');
	cout << "Enter the author's last name:";
	cin.getline(AuthLastName, N, '\n');
	cout << "Enter the publishing:";
	cin.getline(publishing, N, '\n');

	int year, cost, price;

	cout << "Enter the year:";
	cin >> year;
	cout << "Enter cost: ";
	cin >> cost;
	cout << "Enter price: ";
	cin >> price;

	this->SetBook(Name, AuthFirstName, AuthLastName, publishing, year, cost, price);
}

void Book::DisplayBook()
{
	cout << this->AuthFirstName << " " << this->AuthLastName << '\n' << this->Name << '\n' << "Publishing house: " << this->Publishing << '\n' << "cost: " << this->cost << "\n price : " << this->price << " \nprofit : " << this -> profit<<'\n'<<'\n';
}



void Book::SetProfit(int cost, int price)
{
	this->profit = price - cost;
}