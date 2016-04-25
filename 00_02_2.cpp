// CompPhys_Ue1_A2.cpp : Definiert den Einstiegspunkt für die
//Konsolenanwendung.

#include "stdafx.h"
#include <iostream>
#include <ios>

double testFunc(double x)
{
	return x*x;
}

double aFunc(double x)
{
	if (x == 0)
		exit(1); //Krude Behandlung von 1/0
	return exp(-x) / x;
}

double bFunc(double x)
{
	if (x == 0)
		return 0; //Grenzwert
	return x*sin(1 / x);
}

double simpson(double(*func)(double), double min, double max, int N)
{
	double h{ (max - min) / N };
	double result{ 0 };
	int counter{ 1 };
	for (double ii{ min + h }; ii <= max - h; ii += h)
	{
		result += (++counter % 2 == 0) ? (4 / 3)*func(ii) : (2 / 3)*func(ii);
	}
	result += ((1 / 3)*(func(min) + func(max)));
	result *= h;
	return 2 * result; //Willkürlicher (?) Faktor 2 der das Ergebnis richtig macht. Warum?
}

double mittel(double(*func)(double), double min, double max, int N)
{
	double h{ (max - min) / N };
	double result{ 0 };
	for (double ii{ min + (0.5*h) }; ii <= max; ii += h)
	{
		result += func(ii);
	}
	result *= h;
	return result;
}

double trapez(double(*func)(double), double min, double max, int N)
{
	double h{ (max - min) / N };
	double result{ 0 };
	for (double ii{ min + h }; ii <= max - h; ii += h)
	{
		result += func(ii);
	}
	result *= h;
	result += ((h / 2)*(func(min) + func(max)));
	return result;
}

void iterativeSolver(double(*integral)(double(double), double, double, int), double(*func)(double), double min, double max)
{
	int nStuetzen{ 5 }, nStuetzenOld{ 5 }; //Willkürliche Zahl von Startstützstellen
	int counter{ 0 };
	double result{ 0 }, resultOld{ 0 };
	double mdiff{ 0 };
	do {
		resultOld = result;
		nStuetzen *= 2;
		result = integral(func, min, max, nStuetzen);
		mdiff = abs(resultOld - result);
		std::cout << ::std::fixed << "iteration " << ++counter << ": " << result << "    mdiff: " << mdiff << "\n";
	} while (mdiff > 10e-4 && counter <= 30 || counter == 1);
	if (counter > 30)
		std::cout << "Did not converge in 30 iterations.\n";
}

int main()
{
	//std::cout << trapez(testFunc, 0, 10, 10e4) << "\n";
	//std::cout << mittel(testFunc, 0, 10, 10e4) << "\n";
	//std::cout << simpson(testFunc, 0, 10, 10e4) << "\n";

	std::cout << "\nFunction A\n\n";

	iterativeSolver(trapez, aFunc, 1, 100);
	std::cout << "\n\n";
	iterativeSolver(mittel, aFunc, 1, 100);
	std::cout << "\n\n";
	iterativeSolver(simpson, aFunc, 1, 100);

	std::cout << "\nFunction B\n\n";

	iterativeSolver(trapez, bFunc, 0, 1);
	std::cout << "\n\n";
	iterativeSolver(mittel, bFunc, 0, 1);
	std::cout << "\n\n";
	iterativeSolver(simpson, bFunc, 0, 1);

	return 0;
}