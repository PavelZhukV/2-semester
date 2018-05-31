#include <iostream>
#include <cmath>

using namespace std;

typedef double(*IntegralFunction)(double);
typedef double(*QuadratureFormula)(double, double,int, IntegralFunction);
double SinExp(double);
double RightRectangle(double, double, int,IntegralFunction);
double DoubleConverting(double, double, double, int,IntegralFunction, QuadratureFormula);
double MiddleRectangle(double, double, int, IntegralFunction);


int main(void)
{
	double BeginSegm, EndSegm, Epsilon, Integral;
	int Number;
	while (true)
	{
		cout << "enter Begin Segment a:";
		cin >> BeginSegm;
		cout << "enter End Segment b:";
		cin >> EndSegm;
		cout << "enter epsilon :";
		cin >> Epsilon;
		cout << "enter start value of line segments:";
		cin >> Number;
		if ((BeginSegm < EndSegm) && (Number > 0) &&
			(Epsilon < 1) && (Epsilon > 0)) break;
		cout << "Invalid data:try again";
	}
	Integral = DoubleConverting(BeginSegm, EndSegm,
		Epsilon, Number, SinExp, RightRectangle);

	cout << "\n Inegral in Rigth rectangles:"<<Integral;
	
	Integral = DoubleConverting(BeginSegm, EndSegm,
		Epsilon, Number, SinExp, MiddleRectangle);

	cout << "\n Inegral in middle rectangles:" << Integral;

	system("pause");

	return 0;
}
double DoubleConverting(double BeginSegm, double EndSegm,double Epsilon, int Number,IntegralFunction F, QuadratureFormula Q)
{
	double PreviousIntegral, NextIntegral;

	do
	{
		PreviousIntegral = Q(BeginSegm, EndSegm,Number, F);
		NextIntegral = Q(BeginSegm, EndSegm,2 * Number, F);
		Number = 2 * Number;
	} while (fabs(PreviousIntegral - NextIntegral) > Epsilon);

	return NextIntegral;
}

double RightRectangle(double LowerLimit, double UpperLimit,int Number, IntegralFunction F)
{
	double Result = 0;
	double Step = (UpperLimit - LowerLimit) / Number;
	double t = LowerLimit + Step;
	while (t < UpperLimit)
	{
		Result = Result + F(t);
		t = t + Step;
	}
	return (Step * Result);
}

double SinExp(double x)
{
		return sin(x) / x ;
}

double MiddleRectangle(double LowerLimit, double UpperLimit,int Number, IntegralFunction F)
{
	double Result = 0;
	double Step = (UpperLimit - LowerLimit) / Number;
	double t = LowerLimit;
	while (t < UpperLimit)
	{
		Result = Result + F(t + Step / 2);
		t = t + Step;
	}
	return (Step * Result);
}