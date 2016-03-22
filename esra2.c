#include <stdio.h>
double sine(int degree,int n);
double cosine(int degree,int n);
double numberPow(double number,int powNumber);

int long factorial(int number);

void getInputs(int* degree,int* n,int* exist);

int main()
{
	int *degree, *n, *exist;
	int number, nn, exit = 0;
	char cikis;

	// Ana blok
	while(exit == 0)
	{	
		printf("degeri gir\n");
		scanf("%d",&number);
	
		printf(" ");
		scanf("%d",&nn);
		
		if(number == 101 || nn == '101')
		{
			printf("%c\n", number);
			exit = 1;
		}
		else
		{
		getInputs(&number,&nn,&exit);
		return 0;	
		}
		
		
	} // end while exit != !

	return 0;
} // end main

// Sinus Calc
double sine(int degree,int n)
{
	double firstProcess,secondProcess,thirdProcess,result,sonResult=0,number;
	int i;
	if(degree>360)
		degree=degree%360;

	number=(degree*3.14)/180;
	for(i=0;i<=n;i++)
	{
		firstProcess=numberPow(-1,i);
			
		secondProcess=factorial(2*i+1);
			
		thirdProcess=numberPow(number,2*i+1);
			
		result=(firstProcess/secondProcess)*thirdProcess;
			
		sonResult=sonResult+result;
				
	}
	
	return sonResult;
}
double cosine(int degree,int n)
{
	double firstProcess,secondProcess,thirdProcess,result,sonResult=0,number;
	int i;
	if(degree>360)
		degree=degree%360;

	number=(degree*3.14)/180;
	for(i=0;i<=n;i++)
	{
		firstProcess=numberPow(-1,i);
		secondProcess=factorial(2*i);
		thirdProcess=numberPow(number,2*i);
		result=(firstProcess/secondProcess)*thirdProcess;
		sonResult=sonResult+result;		
	}
	return sonResult;
}
int long factorial(int number)
{	
	int i;
	int long result=1;
	for(i=1;i<=number;i++)
	{
		result=result*i;
	}
	
	return result;

}
double numberPow(double number,int powNumber)
{
	double result=1;
	int i;
	for(i=1;i<=powNumber;i++)
		result=result*number;
			
	return result;
}
void getInputs(int* degree,int* n,int* exist)
{
	double sinValue,cosValue;
	sinValue=sine(*degree,*n);
	printf("sinus degeri %.4f \n",sinValue);

	cosValue=cosine(*degree,*n);
	printf("cosinus degeri %.4f \n",cosValue);
}
