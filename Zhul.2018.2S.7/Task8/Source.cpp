#include <iostream>
#include <cmath>

typedef double(*Method)(double,double,int);

double SecondNewtonMethod(double, double, int);
double FirstNewtonMethod(double, double,int);
double Function(double,int);
double Derivative(double,int);
void SolveEqu(double , double, int, int, int, Method);

using namespace std;

int main(void)
{
	double Root, Epsilon;
	int a, b, Step;
	while (true)
	{
		cout << "enter aprocsimate root:";
		cin >> Root;
		cout << "enter epsilon:";
		cin >> Epsilon;
		cout << "enter a:";
		cin >> a;
		cout << "enter b:";
		cin >> b;
		cout << "enter step:";
		cin >> Step;
		if ((Epsilon < 1) && (Epsilon > 0) && (Step < b - a) && (b > a)) 
			break;
		cout << "Invalid data ,try again";
	}

	SolveEqu(Root, Epsilon, a, b, Step, FirstNewtonMethod);
	SolveEqu(Root, Epsilon, a, b, Step, FirstNewtonMethod);

	system("pause");
	return 0;
}
double FirstNewtonMethod(double Previous, double Epsilon,int alph)
{
	double x = Previous;
	double Following = Previous - Function(Previous,alph) / Derivative(x,alph);
	while (fabs(Previous - Following) >= Epsilon)
	{
		Previous = Following;
		Following = Previous -
			Function(Previous,alph) / Derivative(x,alph);
	}
	return Following;
}

double Function(double x,int a)
{
	return exp(x) - 1 - a * pow(x,3);
}

double Derivative(double x,int a)
{
	return exp(x) - 3 * a * pow(x,2);
}

double SecondNewtonMethod(double Previous, double Epsilon,int alph)
{
	double Following = Previous - Function(Previous,alph) / Derivative(Previous,alph) - (Function(Previous - 1 / Derivative(Previous,alph)*Function(Previous,alph), alph)) / Derivative(Previous,alph);
	while (fabs(Previous - Following) >= Epsilon)
	{
		Previous = Following;
		Following = Previous - Function(Previous, alph) / Derivative(Previous, alph) - (Function(Previous - 1 / Derivative(Previous, alph)*Function(Previous, alph), alph)) / Derivative(Previous, alph);
	}
	return Following;
}

void SolveEqu(double Previous, double Epsilon, int a,int b,int step ,Method Meth)
{
	for (int i = a; a <= b; a += step)
	{
		cout << "Solve the equastion for Alpha:" << a << "= " << Meth(Previous, Epsilon, a)<<endl;
	}
}