#include <iostream>
#include <math.h>

#define TOTAL_ELEM 11

int toplamX(int x[]);
int toplamY(int y[]);

int toplamXkare(int x[]);
int toplamYkare(int y[]);

int carpimlarinToplami(int x[], int y[]);
int toplamlarinCarpimlari(int x[], int y[]);


int main(int argc, char *argv[])
{
	int x[] = { 6,	7,	11,	15,	17,	21,	23,	29,	29,	37,	39 };
	int y[] = { 29,	21,	29	,14	,21	,15	,7,	7,	13,	0,	3 };

	float a1pay = (TOTAL_ELEM * carpimlarinToplami(x, y) - toplamlarinCarpimlari(x, y));
	float a1payda = (TOTAL_ELEM * toplamXkare(x) - (toplamX(x) * toplamX(x)));
	float a1 = a1pay / a1payda;

	float a0 = (toplamY(y) - (a1 * toplamX(x))) / TOTAL_ELEM;

	float r = (TOTAL_ELEM * carpimlarinToplami(x, y) - toplamlarinCarpimlari(x, y)) / (sqrt(TOTAL_ELEM * toplamXkare(x) - (toplamX(x) * toplamX(x)))  * sqrt(TOTAL_ELEM * toplamYkare(y) - (toplamY(y) * toplamY(y))));

	std::cout << a1 << "x + " << a0 << std::endl
			  << "r: " << r * r << std::endl;

	system("PAUSE");
	return 0;
}

int toplamX(int x[])
{
	int toplam = 0;
	for (int i = 0; i < TOTAL_ELEM; i++)
	{
		toplam += x[i];
	}

	return toplam;
}

int toplamY(int y[])
{
	int toplam = 0;
	for (int i = 0; i < TOTAL_ELEM; i++)
	{
		toplam += y[i];
	}

	return toplam;
}

int toplamXkare(int x[])
{
	int toplam = 0;
	for (int i = 0; i < TOTAL_ELEM; i++)
	{
		toplam += x[i] * x[i];
	}

	return toplam;
}

int toplamYkare(int y[])
{
	int toplam = 0;
	for (int i = 0; i < TOTAL_ELEM; i++)
	{
		toplam += y[i] * y[i];
	}

	return toplam;
}

int carpimlarinToplami(int x[], int y[])
{
	int toplam = 0;

	for (int i = 0; i < TOTAL_ELEM; i++)
	{
		toplam += x[i] * y[i];
	}

	return toplam;
}

int toplamlarinCarpimlari(int x[], int y[])
{
	int toplamX = 0;
	int toplamY = 0;

	for (int i = 0; i < TOTAL_ELEM; i++)
	{
		toplamX += x[i];
		toplamY += y[i];
	}

	return toplamX * toplamY;
}
