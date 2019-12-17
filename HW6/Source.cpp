/*
*	Author: Ozan YILDIZ - 151044082
*	Numerical Analysis HW06
*/
#include <stdio.h>
#include <stdlib.h>

#include <math.h>

#define MAX 8

double xe2xIntegration(double, double, double);

int main()
{
	double s[MAX];
	double temp;

	for (int i = 1; i < MAX; i++)
		s[i] = 1;


	for (int i = 1; i< MAX; i++)
		s[i] = 1;

	for (int k = 1; k < MAX; k++)
	{
		for (int i = 1; i <= k; i++)
		{
			if (i == 1)
			{
				temp = s[i];
				s[i] = xe2xIntegration(0.0, 3.0, pow(2, k - 1));
			}
			else
			{
				s[k] = (pow(4, i - 1)*s[i - 1] - temp) / (pow(4, i - 1) - 1);

				temp = s[i];
				s[i] = s[k];
			}
			printf("%f\t", s[i]);
		}
		printf("\n");
	}

	

	system("PAUSE");
	return 0;
}

double xe2xIntegration(double start, double finish, double constant)
{
	const double e = 2.71828;

	finish /= constant;

	return (1.0 / 4.0) * pow(e, 2.0 * finish) * (2.0 * finish - 1.0) - (1.0 / 4.0) * pow(e, 2.0 * start) * (2.0 * start - 1.0);
}