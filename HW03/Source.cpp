/*
*	Author: Ozan Yıldız
*	Date:	2016.03.20
*	
*	Gebze Technical University for Numerical Analysis HW03
*/

#include <iostream>
#include <stdio.h>
#include <math.h>

#define ITERATION 10

double equation(double x);

double dCalc(double newR, double newXHigh, double newXLow);
double x1Calc(double newXLow, double newD);
double x2Calc(double newXHigh, double newD);
double epsilonCalc(double R, double xHigh, double xLow, double xOpt);

int main(int argc, char const *argv[])
{
	printf("Golden-Section Search v1\n");
	printf("Created by Ozan Yildiz\n\n");

	// Variables
	double xLow = 0, xHigh = 2;				// Max and min variables

	double x1 = 0, x2 = 0, xOpt = 0, d = 0, epsilon = 0;	// Function unknows variables

	double fLow, f1, f2, fHigh;				// Function

	// Golden Ratio
	double R = (sqrt(5) - 1) / 2;
	printf("Golden ratio is %.4lf\n\n", R);

	printf("x(low)\tf(flow)\tx2\tf2\tx1\tf1\tx(high)\tf(high)\td\tepsil\n");

	{ // Variables calculation
		d = dCalc(R, xHigh, xLow);
		x1 = x1Calc(xLow, d);
		x2 = x2Calc(xHigh, d);
	}

	{ // Functions calculation
		fLow = equation(xLow);
		f2 = equation(x2);
		f1 = equation(x1);
		fHigh = equation(xHigh);
	}

	for (int i = 0; i < ITERATION; i++)
	{
		printf("%.4lf\t%.4lf\t%.4lf\t%.4lf\t%.4lf\t%.4lf\t%.4lf\t%.4lf\t%.4lf\t%.2lf\n", xLow,fLow, x2, f2, x1, f1, xHigh, fHigh, d, epsilon);

		if (f2 > f1)
		{
			// New x High value and calculate
			xHigh = x1;
			fHigh = f1;

			// New x1 value and f1 function
			x1 = x2;
			f1 = f2;

			// Optimum x and Epsilon calc
			xOpt = x2;
			epsilon = epsilonCalc(R, xHigh, xLow, xOpt);

			// New d, x2, and f2 calculate
			{
				d = dCalc(R, xHigh, xLow);
				x2 = x2Calc(xHigh, d);
				f2 = equation(x2);
			}
		}
		else if(f2 < f1)
		{
			// New x Low value and calculate
			xLow = x2;
			fLow = f2;

			// x2 value and f2 function
			x2 = x1;
			f2 = f1;

			// Optimum x and Epsilon calc
			xOpt = x1;
			epsilon = epsilonCalc(R, xHigh, xLow, xOpt);

			// New d, x1 and f1 calculate
			{
				d = dCalc(R, xHigh, xLow);
				x1 = x1Calc(xLow, d);
				f1 = equation(x1);
			}
		}

	}

	system("PAUSE");
	return 0;
}

// The equation formule
double equation(double x)
{
	return (-1.0 * 1.5 * pow(x, 6)) - (2.0 * pow(x, 4)) + (12.0 * x);
}


double dCalc(double R, double xHigh, double xLow)
{
	return R * (xHigh - xLow);
}

double x1Calc(double xLow, double d)
{
	return xLow + d;
}

double x2Calc(double xHigh, double d)
{
	return xHigh - d;
}

double epsilonCalc(double R, double xHigh, double xLow, double xOpt)
{
	return (1 - R) * fabs((xHigh - xLow) / xOpt) * 100;
}