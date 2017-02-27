#include <iostream>
#include <math.h>
#include <string>
using namespace std;

struct Complex
{
	float a;
	float bi;
};

struct Binomial_Equation
{
	float a;
	float b;
	float c;
};

Complex* RootsOfEquation(Binomial_Equation eq)
{
	Complex* roots = new Complex[2];
	Complex x1;
	Complex x2;
	float delta = eq.b*eq.b - 4 * eq.a*eq.c;
	if (delta >= 0)
	{
		x1.a = 0.5*eq.a * (-eq.b - sqrt(delta));
		x1.bi = 0;
		x2.a = 0.5*eq.a * (-eq.b + sqrt(delta));
		x2.bi = 0;
	}
	else
	{
		x1.a = 0.5*eq.a * -eq.b;
		x1.bi = 0.5*eq.a * -sqrt(delta * -1);
		x2.a = 0.5*eq.a * -eq.b;
		x2.bi = 0.5*eq.a *sqrt(delta * -1);
	}
	roots[0] = x1;
	roots[1] = x2;
	return roots;
}
void PrepareResults(const Complex* roots)
{
	Complex x1 = roots[0];
	Complex x2 = roots[1];
	if (x1.bi == 0 && x2.bi == 0)
	{
		cout << "x1 equals: " << x1.a << endl;
		cout << "x2 equals: " << x2.a << endl;
	}
	else
	{
		string x1sign = x1.bi > 0 ? " + " : " - ";
		string x2sign = x2.bi > 0 ? " + " : " - ";
		cout << "x1 equals: " << x1.a << x1sign << abs(x1.bi) << "i" << endl;
		cout << "x2 equals: " << x2.a << x2sign << abs(x2.bi) << "i" << endl;
	}

}
int main()
{
	Binomial_Equation eq;
	eq.a = 1;
	eq.b = 2;
	eq.c = 2;
	if (eq.a == 0)
	{
		cout << "a = 0, blad" << endl;
	}
	else
	{
		const Complex* roots = RootsOfEquation(eq);
		PrepareResults(roots);
	}

	return 0;
}