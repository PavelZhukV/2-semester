#pragma once


class Num
{
public:
	Num(){}
	Num(int, int);
	void SetNum(int, int);
	void SetAmount(int);
	void SetSystem(int);
	void DisplayNum();
private:
	int  system,amount;
	char value[256];
	void SetValue(int, int);
};