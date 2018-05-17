#include <iostream>
#include "Header.h"

const int N = 256;

Num::Num(int amount, int system)
{
	this->SetNum(amount, system);
}

void Num::SetNum(int amount, int system)
{
	this->SetAmount(amount);
	this->SetSystem(system);
	this->SetValue(amount, system);
}

void Num::SetAmount(int amount)
{
	this->amount = amount;
}

void Num::SetSystem(int system)
{
	this->system = system;
}

void systemTransfer(int num, int base, char* trnum)
{
	int n = 0, m, k = num;

	while (k /= base)
		n++;
	trnum[n + 1] = 0;
	for (; n >= 0; n--, num /= base)
	{
		m = num % base;
		switch (m)
		{
		case 0:
			trnum[n] = '0';
			break;
		case 1:
			trnum[n] = '1';
			break;
		case 2:
			trnum[n] = '2';
			break;
		case 3:
			trnum[n] = '3';
			break;
		case 4:
			trnum[n] = '4';
			break;
		case 5:
			trnum[n] = '5';
			break;
		case 6:
			trnum[n] = '6';
			break;
		case 7:
			trnum[n] = '7';
			break;
		case 8:
			trnum[n] = '8';
			break;
		case 9:
			trnum[n] = '9';
			break;
		case 10:
			trnum[n] = 'A';
			break;
		case 11:
			trnum[n] = 'B';
			break;
		case 12:
			trnum[n] = 'C';
			break;
		case 13:
			trnum[n] = 'D';
			break;
		case 14:
			trnum[n] = 'E';
			break;
		case 15:
			trnum[n] = 'F';
			break;
		}
	}
}

void Num::SetValue(int amount, int system)
{
	char val[256];
	systemTransfer(amount, system, val);
	strcpy(this->value, val);
}

void Num::DisplayNum()
{
	std::cout << "in decimal:" << this->amount << '\n' << "base: " << this->system << '\n' << "on this system : " << this->value<<'\n'<<'\n';
}