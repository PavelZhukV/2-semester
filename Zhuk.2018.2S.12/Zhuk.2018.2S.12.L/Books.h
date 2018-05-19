#pragma once



const int N = 50;

class Book
{
public:
	Book(){}
	Book(char*, char*, char*, char*, int, int, int);
	~Book(){}
	void SetBook(char *, char *, char *, char *, int, int, int);
	void SetName(char*);
	void SetAuthName(char*,char*);
	void SetPublishing(char*);
	void SetYear(int);
	void SetCost(int);
	void SetPrice(int);
	char* GetAuthName();
	char* GetName();
	char* GetPublishing();
	int GetProfit();
	void EnterBook();
	void DisplayBook();
private:
	char Name[N]{}, AuthFirstName[N]{}, AuthLastName[N]{}, Publishing[N]{};
	int year,price,cost,profit;
	void SetProfit(int,int);
};


