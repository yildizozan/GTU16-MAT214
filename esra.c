#include <stdio.h>
#include <iostream>
#include <iomanip>

using std::setw;

void birChar(char * borderChar);
void ikiChar(char * borderChar);

void getInputs(int* num, int* borderWidth, char* borderChar);
int printNumber(int num, int borderWidth, char borderChar);

int main()
{	int * num,number;	
	int * borderWidth,WidthBorder;
	char * borderChar,charBorder;
	
	printf("sayi gir");
	scanf("%d",&number);
		
	printf("kalınlık");
	scanf("%d",&WidthBorder);

	printf("char");
	scanf(" %c",&charBorder);
	/*while(*num>0 && *num<=99999)
		{
			getInputs(&number,&WidthBorder,&charBorder);
			printf("sayi gir");
			scanf("%d",&number);
		
			printf("kalınlık");
			scanf("%d",&WidthBorder);

			printf("char");
			scanf(" %c",&charBorder);
		}*/
	setw(14);
	birChar(&charBorder);
	ikiChar(&charBorder);
	return 0;
}
void getInputs(int* num, int* borderWidth, char* borderChar)
{
	int birbas,onbas,yuzbas,binbas,onbinbas;
	
		onbinbas=*num/10000;
		binbas=(*num%10000)/1000;
		yuzbas=(*num%1000)/100;
		onbas=((*num%1000)%100)/10;
		birbas=*num%10;
	
}
int printNumber(int num, int borderWidth, char borderChar)
{
	return 0;
}


void birChar(char * borderChar)
{
	char harf[7][7];
	int i,j;
	for(i=0;i<7;i++)
		{
			for(j=0;j<7;j++)
				harf[i][j]=' ';
		}
	harf[2][2]=*borderChar;
	harf[1][3]=*borderChar;
	harf[2][3]=*borderChar;
	harf[5][3]=*borderChar;
	harf[3][3]=*borderChar;
	harf[4][3]=*borderChar;
	harf[5][2]=*borderChar;
	harf[5][4]=*borderChar;
	for(i=0;i<7;i++)
		{
			for(j=0;j<7;j++)
				printf("%c",harf[i][j]);
			printf("\n");
		}	
}
void ikiChar(char * borderChar)
{
	char harf[7][7];
	int i,j;
	for(i=0;i<7;i++)
		{
			for(j=0;j<7;j++)
				harf[i][j]=' ';
		}
	harf[1][2]=*borderChar;
	harf[1][3]=*borderChar;
	harf[1][4]=*borderChar;
	harf[2][4]=*borderChar;
	harf[3][3]=*borderChar;
	harf[3][4]=*borderChar;
	harf[3][2]=*borderChar;
	harf[4][2]=*borderChar;
	harf[5][2]=*borderChar;
	harf[5][3]=*borderChar;
	harf[5][4]=*borderChar;
	for(i=0;i<7;i++)
		{
			for(j=0;j<7;j++)
				printf("%c",harf[i][j]);
			printf("\n");
		}	
}
